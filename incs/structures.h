#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_point
{
    float   x;
    float   y;
}   t_point;

typedef struct s_vector
{
    float   v_x;
    float   v_y;
}   t_vector;

typedef struct s_player
{
    t_point     position;
    t_vector    orientation;
}   t_player;

// MAP STRUCTURES

typedef struct s_line
{

}

typedef struct s_map
{

}


#endif