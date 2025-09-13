#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <sys/types.h>

typedef struct s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct s_vector
{
	float		v_x;
	float		v_y;
}				t_vector;

typedef struct s_player
{
	t_point		position;
	t_vector	orientation;
}				t_player;

// MAP STRUCTURES

typedef struct s_color
{
	int			R;
	int			G;
	int			B;
}				t_color;

typedef struct s_map_data
{
	// fds of the wall textures
	int			NO;
	int			SO;
	int			WE;
	int			EA;

	// color components for floor/ceiling
	t_color		F;
	t_color		C;

    // map array
	char		**map;
    size_t map_size_x;
    size_t map_size_y;
}				t_map_data;

#endif