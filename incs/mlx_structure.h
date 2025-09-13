/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csavreux <csavreux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:24:03 by csavreux          #+#    #+#             */
/*   Updated: 2025/09/13 16:25:50 by csavreux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCTURE_H
# define MLX_STRUCTURE_H

typedef struct s_mlx_env
{
	void		*mlx;
	void		*mlx_win;
	int			win_size_x;
	int			win_size_y;
	void		*mlx_img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_mlx_env;

#endif