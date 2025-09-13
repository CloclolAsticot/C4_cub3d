/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 15:55:59 by csavreux          #+#    #+#             */
/*   Updated: 2025/09/13 16:15:39 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "initialization.h"
#include <stdio.h>

int main(void)
{
	t_map_data map_data;
	t_player player;
	char *map[5] = {
		"11111",
		"10001",
		"10001",
		"10E01",
		"11111"
	};
	
	map_data.map = map;
	map_data.map_size_x = 5;
	map_data.map_size_y = 5;

	initialize_player_data(&player, &map_data);

	printf("Player position : x=%f, y=%f\n", player.position.x, player.position.y);
	printf("Player orientation : v_x=%f, v_y=%f\n", player.orientation.v_x, player.orientation.v_y);

	return (0);
}