*This project has been created as part of the 42 curriculum by migarrid.*

# Cub3d: Raycasting Rendering Engine

## Description

Cub3d is a first-person maze exploration engine built from scratch inspired by the 1992 classic, Wolfenstein 3D. Developed as part of the 42 curriculum, this project serves as a practical implementation of computer graphics concepts, linear algebra, and multithreading performance using (MLX42).

In simple terms: the program **tricks us**. The whole game actually happens on a flat 2-dimensional map (like a chessboard), but through some calculations, we can create the illusion of a 3D world on your screen.

## Mathematical Foundations & Core Architecture

To simulate a 3D environment using 2D concepts, the engine relies on mathematical algorithms. The following sections break down the theoretical foundation and how we've implemented it in the code.

### 1. The Camera and Vectors (How do we represent the player?)

The player is not just an `(X, Y)` coordinate on the map. To know exactly what they are looking at, we need to build a "camera". The camera is made up of three main elements or vectors:

- **Position Vector ($P$)**: `(Px, Py)` - Exactly where the player is standing on the board.
- **Direction Vector ($D$)**: `(Dx, Dy)` - An invisible arrow strictly pointing to where the player's nose is facing.
- **Camera Plane ($C$)**: `(Cx, Cy)` - A horizontal line perpendicular to their gaze. The width of this line is what defines the "Field of View" (FOV). The longer it is, the more peripheral vision you have.

```text
       Camera Plane (C)
       +--------+--------+
        \       |       /
         \      |      /
          \     |     /   Ray(x)
           \    |    /
            \   |   /  Direction (D)
             \  |  /
              \ | /
               \|/
             Player (P)
```

### 2. Raycasting and the DDA Algorithm

To draw what the player sees on the computer screen, we need to analyze each vertical pixel of the window. If the window is 1920 pixels wide, the player shoots 1920 invisible "rays" (one for each vertical column of the screen).

Once we cast a ray $\vec{R}$, we need to know where it hits a wall. If we try to check the position pixel by pixel to see if there is a wall, the computer would become extremely slow.

This is where the **DDA (Digital Differential Analyzer)** algorithm comes in. Instead of moving little by little, this algorithm smartly jumps from one grid line to the next. It always asks itself: *"What is closer to me, crossing a vertical line(X) or a horizontal line(Y) on the map?"* and takes the shortest jump. Thus, it travels from square to square until it hits.

**Implementation:**
The algorithm continuously compares the accumulated distance in $X$ and $Y$, always choosing the shortest path, until the grid indicates there is a "wall".

```c
void	perform_dda(t_map *map, t_ray *ray)
{
	bool hit;

	// The ray advances from square to square on the grid until it hits
	hit = FALSE;
	while (!hit)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
			move_x_side(ray);
		else
			move_y_side(ray);
		// Once positioned on the new square, we check the map
		if (is_hit_wall_or_door(map, ray))
		{
			// If the obstacle is transparent we record the hit
			// to draw it later, but the ray keeps going
			if (is_transparent_door(map, ray))
				init_transparent_hit(ray);
			else
				// It's a solid wall or opaque door
				hit = TRUE;
		}
	}
}
```

### 3. Perpendicular Distance: Unlocking Flat Projection and Height

When we shoot the rays, the rays going towards the edges of your screen naturally travel a longer physical distance than the ray going straight through the middle. If we use that real distance to decide how big to draw the wall, straight walls would look curved towards the sides, creating a rounded "Fisheye" effect.

To make the walls look flat, we don't use the total distance traveled by the ray. Instead, we calculate the **perpendicular distance**; imagining a horizontally flat straight line from the player in front of the wall and we only take that frontal distance, canceling the angle the ray traveled at.

Once we have the exact perpendicular distance, we need to know how many pixels high the wall strip will be on our screen. Based on perspective rules (similar triangles), the projected height is inversely proportional to the distance. It simplifies to: $h_{projected} = \frac{h_{screen}}{d_{perp}}$

**Implementation:**
```c
void	calc_perp_distance(t_plyr *player, t_ray *ray)
{
	// Depending on which side of the wall we hit, we use the X or Y axis
	if (ray->wall_side == WEST || ray->wall_side == EAST)
		calculate_distance(player, ray, X);
	else
		calculate_distance(player, ray, Y);
}

static void	calculate_distance(t_plyr *player, t_ray *ray, t_pos axis)
{
	double	axis_dist;
	double	wall_pos;

	wall_pos = calculate_real_coord_wall(ray, axis);
	axis_dist = wall_pos - player->pos[axis];

	// By dividing it by the ray's own direction, we obtain the flat projection
	ray->perp_dist = axis_dist / ray->dir[axis];
}

static void	get_start_end_pixel_wall(t_plyr *player, t_opt *vars, t_ray *ray)
{
	int	half_line_height;

	// Calculate the wall height trough similar triangles
	ray->wall_height = (int)(data->img->height / ray->perp_dist);

	// Calculate the current viewing center point
	ray->screen_center[X] = vars->half_img_width + (int)player->head[SWAY];
	ray->screen_center[Y] = vars->half_img_height + player->head[POS];

	half_line_height = ray->wall_height / 2;

	// Determine the start and end of the wall we see
	ray->wall_start = (int)ray->screen_center[Y] - half_line_height;
	ray->wall_end = (int)ray->screen_center[Y] + half_line_height;
}
```

Now that we know exactly how high the wall is (e.g. 400 pixels high) and where it starts and ends on the screen, all that's left is to paint it.

Painting the wall involves going over that vertical strip pixel by pixel, from top to bottom, finding the corresponding color in our image file (2D texture) and drawing it at the window coordinates, applying light calculations along the way.

``` c
static void	draw_txtr_col(t_data *data, t_ray *ray, mlx_texture_t *txtr, int x)
{
	int         mapped_tex[AXIS];
    double      brightness;
    uint32_t    color;

	// Find which pixel of the texture corresponds to this point on the wall
	mapped_tex[X] = (int)ray->tex[X] & TEXTURE_MODULE;
	brightness = get_wall_brightness(data, ray);

	// Iterate through the vertical strip on the screen
	while (ray->wall_start <= ray->wall_end)
	{
		// Find which pixel of the texture corresponds to this point on the wall
		mapped_tex[Y] = (int)ray->tex[Y] & TEXTURE_MODULE;
		color = get_pixel_color(txtr->pixels, mapped_tex, txtr->width);

		if (is_visible_pixel(color))
		{
			color = apply_light(data, color, brightness);
			fast_put_pixel(data->img, x, ray->wall_start, color);
		}

		// Advance in the texture and on the screen
		ray->tex[Y] += ray->tex_step;
		ray->wall_start++;
	}
}
```

### 4. Kinematics: Rotating Using Math

When you move the mouse to the right, the 3D environment doesn't actually move. What we do is "rotate" the 2D camera. But rotating both vectors (the Direction $\vec{D}$ and the Camera Plane $\vec{C}$) is not as simple as adding a number, it requires using complex number trigonometry.

To rotate a vector by any angle $\theta$, we use the famous "2D rotation matrix". We extract sine and cosine of the desired angle of rotation and recompute the `x` and `y` positions.

$$
\begin{bmatrix}
x' \\
y'
\end{bmatrix}
=
\begin{bmatrix}
\cos\theta & -\sin\theta \\
\sin\theta & \cos\theta
\end{bmatrix}
\begin{bmatrix}
x \\
y
\end{bmatrix}
$$

**Implementation:**
We update the axes equally so that the camera doesn't deform when turning.

```c
static void apply_x_rotation(t_plyr *player, double angle)
{
    double  sin_a = sin(angle);
    double  cos_a = cos(angle);
    double  old_dir_x = player->dir[X];

    // Applying the mathematical formula to rotate the player's gaze...
    player->dir[X] = player->dir[X] * cos_a - player->dir[Y] * sin_a;
    player->dir[Y] = old_dir_x * sin_a + player->dir[Y] * cos_a;

    // ... and the vision plane must rotate equally to remain perpendicular
    player->fov[X] = -player->dir[Y] * FOV_FACTOR;
    player->fov[Y] = player->dir[X] * FOV_FACTOR;
}
```

### 5. Lighting: The Inverse-Square Law

To give it a less synthetic look, lights don't cover the whole hallway uniformly. In real life, imagine lighting a match. The light expands like an invisible balloon or a sphere around the flame. As that sphere of light gets larger, it stretches, so its brightness has to cover more space.

In physics, this dictates that the intensity of lighting weakens aggressively, being proportional to the "inverse square of the distance". If you move twice as far away, you see the light four times less brightly. $I \propto \frac{1}{r^2}$.

We added a small factor `$k$` and adjusted a $1.0$ so that the intensity does not cause technical failures (divisions by zero).

$$
I_{received} = \frac{I_0}{1.0 + k \cdot d^2}
$$

**Implementation:**
```c
static void calc_light_to_cell(t_map *map, t_light *light, double x, double y)
{
    double	dist;
	double	intensity_received;

	dist = ft_dist(light->pos[X], light->pos[Y], target[X], target[Y]);
    if (dist > light->radius || is_light_path_blocked(map, light, target))
        return ;

    // Approximation of the Inverse Law using our parameters...
    intensity_received = light->intensity / (1.0 + dist * dist * 0.5);

    // Add the bounce of light on the mapped wall
    map->lightmap[sub_cell[Y]][sub_cell[X]] += intensity_received;
}
```

### 6. Multithreading System

Shooting almost 2,000 rays and painting them every second you walk costs a lot of power to your computer's Processor (CPU).

However, since ray number `1` on the left of the screen does not mathematically depend on ray `10` or ray `500`; we can ask the computer to draw them all simultaneously.
This is called parallelism. The program counts how many "cores" your CPU has. If you have 4 cores, it divides the screen width into 4 piles, and draws them all at the same time using `pthreads`.

Disclaimer: Some bonus features we needed to use functions that weren't listed in the allowed functions of the subject. These functions, in any case, were used to facilitate the mandatory part or any other part of the project where it was necessary to implement some bonus features.

**Implementation:**
```c
void render_map(t_data *data)
{
	t_thread	threads[MAX_THREADS];
	int			cols_per_thread;
    int			i;

	i = 0
    // We fairly dispatch the tasks in parallel among the cores
    while (i < data->vars.n_cores)
    {
        cols_per_thread = data->img->width / data->vars.n_cores;
        init_thread(data, threads, i, cols_per_thread);
        pthread_create(&threads[i].thread, NULL, render_section, &threads[i]);
        i++;
    }

    // We wait for all to finish painting before refreshing the image
    i = 0;
    while (i < data->vars.n_cores)
    {
        pthread_join(threads[i].thread, NULL);
        i++;
    }
}
```

## Instructions

### Compilation
To compile the main executable along with the optimizations quickly, simply run:
```bash
make
```

### Execution
Launch the binary by passing it the map model file:
```bash
./cub3d map/hospital.cub
```

### Controls
- **W/A/S/D:** Walk through the maze.
- **Shift + W/A/S/D:** Run.
- **Left/Right Arrows or Mouse Movement:** Rotate camera.
- **Left Click:** Aim the weapon.
- **Left Click (Hold):** Full fire or melee attack.
- **E:** Interact with model doors.
- **Space:** Jump.
- **ESC:** Safely exit the program.

## Resources
- [Lode's Computer Graphics Tutorial (Raycasting)](https://lodev.org/cgtutor/raycasting.html) - The most indispensable guide out there on raycasting projections and DDA grids.
- [Why Wolfenstein Was Way Ahead of It’s Time](https://www.youtube.com/watch?v=rPn_LKUJ7II) - Informative analysis of the famous video game that inspired these mathematical techniques (id Software's Wolfenstein 3D).
- [Wolfenstein 3D Source Code](https://github.com/id-Software/wolf3d) - Original C source code repository for 1995 Wolfenstein.
- [MLX42 Documentation](https://github.com/codam-coding-college/MLX42) - The comprehensive documentation on the cross-platform graphics library for drawing pixels.
- [Generative Artificial](https://gemini.google.com) Intelligence models were used as tool to generate visuals and textures as well to optimize mathematical functions in order to optimized the performance of this game. It has been consulted also to polish the mathematical explanations for these documentation.
