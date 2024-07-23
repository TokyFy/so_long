/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:01:52 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/23 15:57:31 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "engime.h"

uint64_t	gettimeofday_ms(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * (uint64_t)1000) + (t.tv_usec / 1000));
}

uint64_t	timestamp_in_ms(void)
{
	static uint64_t	created_at;

	if (created_at == 0)
		created_at = gettimeofday_ms();
	return (gettimeofday_ms() - created_at);
}
