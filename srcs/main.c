/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:55:59 by csavreux          #+#    #+#             */
/*   Updated: 2025/09/13 16:55:17 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "game_structures.h"
#include "mlx_structure.h"
#include "mlx.h"
#include "initialization.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Handles the proper cleanup and termination of the application.
 *
 * @param env Pointer to the environment structure containing all program data
 * @return Always returns 0 (though the program exits before returning)
 */
static int	close_window(t_mlx_env *env)
{
	mlx_destroy_image(env->mlx, env->mlx_img);
	mlx_destroy_window(env->mlx, env->mlx_win);
	mlx_destroy_display(env->mlx);
	free(env->mlx);
	exit(0);
	return (0);
}

/**
 * @brief Handle keypresses in the window.
 *
 * @param keycode The key code of the pressed key
 * @param env Pointer to the environment structure
 * @return Always returns 0
 */
static int	key_handler(int keycode, t_mlx_env *env)
{
	if (keycode == 65307)
		close_window(env);
	return (0);
}

/**
 * @brief Initializes the mlx environment for the FdF program.
 *
 * @param map The map data structure containing the 3D map information
 * @param env Pointer to the environment structure to be initialized
 * @return A pointer to the initialized environment or NULL on failure
 */
static void	*init_env(t_mlx_env *env)
{
	env->mlx = mlx_init();
	if (!env->mlx)
		return (NULL);
	env->mlx_win = mlx_new_window(env->mlx, env->win_size_x, env->win_size_y,
			"cub3D");
	if (!env->mlx_win)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		return (NULL);
	}
	env->mlx_img = mlx_new_image(env->mlx, env->win_size_x, env->win_size_y);
	if (!env->mlx_img)
	{
		mlx_destroy_window(env->mlx, env->mlx_win);
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		return (NULL);
	}
	return (env);
}

/**
 * @brief Main function for the FdF program.
 *
 * This function initializes the environment and map, renders a 3D wireframe
 * representation of the provided map file, and handles window events.
 * The program takes exactly one command line argument: the path to a map
 * file.
 *
 * @param ac Argument count
 * @param av Argument vector (array of strings)
 * @return int 0 on successful execution, 1 on error
 */
int	main(void)
{
	t_mlx_env	env;
	t_map_data map_data;
	t_player player;
	char *map[6] = {
		"11111",
		"10001",
		"10001",
		"10N01",
		"10001",
		"11111"
	};
	
	map_data.map = map;
	map_data.map_size_x = 5;
	map_data.map_size_y = 5;

	initialize_player_data(&player, &map_data);
	
	env.win_size_x = 1920;
	env.win_size_y = 1080;
	init_env(&env);
	env.addr = mlx_get_data_addr(env.mlx_img, &env.bits_per_pixel,
			&env.line_length, &env.endian);
	mlx_put_image_to_window(env.mlx, env.mlx_win, env.mlx_img, 0, 0);
	mlx_hook(env.mlx_win, 17, 0, close_window, &env);
	mlx_hook(env.mlx_win, 2, 1, key_handler, &env);
	mlx_loop(env.mlx);
	return (0);
}