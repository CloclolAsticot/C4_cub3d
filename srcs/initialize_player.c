/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:46:17 by csavreux          #+#    #+#             */
/*   Updated: 2025/09/13 16:45:08 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "game_structures.h"

static void	initialize_player_location(t_point *player_position, char **map,
				size_t map_size_x, size_t map_size_y);

static void	initialize_player_orientation(t_vector *player_orientation,
				int player_position_x, int player_position_y, char **map);

/**
 * @brief Initializes all player data including position and orientation
 *
 * @param player Pointer to the player structure to be initialized
 * @param map_data Pointer to the map data structure containing map layout
 *                 and dimensions
 */
void	initialize_player_data(t_player *player, t_map_data *map_data)
{
	initialize_player_location(&player->position, map_data->map,
		map_data->map_size_x, map_data->map_size_y);
	initialize_player_orientation(&player->orientation, (int)player->position.x,
		(int)player->position.y, map_data->map);
	return ;
}

/**
 * @brief Initializes the player's starting location on the map
 *
 * @param player_position Pointer to t_point structure to store player
 *                      coordinates
 * @param map 2D character array representing the game map
 * @param map_size_x Width of the map (number of columns)
 * @param map_size_y Height of the map (number of rows)
 */
static void	initialize_player_location(t_point *player_position, char **map,
		size_t map_size_x, size_t map_size_y)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map_size_y)
	{
		x = 0;
		while (x < map_size_x)
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'X')
			{
				player_position->x = (float)x + 0.5f;
				player_position->y = (float)y + 0.5f;
				return ;
			}
			x++;
		}
		y++;
	}
}

/**
 * @brief Initializes the player's orientation vector based on map identifier
 *
 * @param player_orientation Pointer to the vector structure to be initialized
 *                          with the player's orientation direction
 * @param player_position The starting position of the player on the map
 * @param map 2D character array representing the game map
 */
static void	initialize_player_orientation(t_vector *player_orientation,
		int player_position_x, int player_position_y, char **map)
{
	char	orientation_identifier;

	orientation_identifier = map[player_position_y][player_position_x];
	if (orientation_identifier == 'N')
	{
		player_orientation->v_x = 0.0f;
		player_orientation->v_y = -1.0f;
	}
	else if (orientation_identifier == 'S')
	{
		player_orientation->v_x = 0.0f;
		player_orientation->v_y = 1.0f;
	}
	else if (orientation_identifier == 'E')
	{
		player_orientation->v_x = 1.0f;
		player_orientation->v_y = 0.0f;
	}
	else if (orientation_identifier == 'W')
	{
		player_orientation->v_x = -1.0f;
		player_orientation->v_y = 0.0f;
	}
	return ;
}

// #include <stdio.h>

// int main(void)
// {
// 	t_map_data map_data;
// 	t_player player;
// 	char *map[6] = {
// 		"11111",
// 		"10001",
// 		"10001",
// 		"10N01",
// 		"10001",
// 		"11111"
// 	};
	
// 	map_data.map = map;
// 	map_data.map_size_x = 5;
// 	map_data.map_size_y = 5;

// 	initialize_player_data(&player, &map_data);

// 	printf("Player position : x=%f, y=%f\n", player.position.x, player.position.y);
// 	printf("Player orientation : v_x=%f, v_y=%f\n", player.orientation.v_x, player.orientation.v_y);

// 	return (0);
// }