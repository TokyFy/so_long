/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:04:53 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 14:21:42 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "engime.h"

void	init_zero(void *ptr1, void *ptr2, void *ptr3, void *ptr4)
{
	if (ptr1)
		*(int *)ptr1 = 0;
	if (ptr2)
		*(int *)ptr2 = 0;
	if (ptr3)
		*(int *)ptr3 = 0;
	if (ptr4)
		*(int *)ptr4 = 0;
}

int	ft_random(int min, int max)
{
	int	temp;

	if (min > max)
	{
		temp = min;
		min = max;
		max = temp;
	}
	return ((rand() % (max - min + 1)) + min);
}

void	free_2d_int(int **arr, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	debug_grid(t_mlx_image img, int color)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < img.heigth)
	{
		x = 0;
		while (x < img.width)
		{
			if (x % 32 == 0 || y % 32 == 0)
				put_pixel_img(img, x, y, color);
			x++;
		}
		y++;
	}
}
