/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananariv>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 09:04:53 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/16 09:16:11 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "engime.h"

int	generateRandomNumber(int min, int max)
{
    int	temp;

    if (min > max)
    {
        // Swap min and max if min is greater than max
        temp = min;
        min = max;
        max = temp;
    }
    return ((rand() % (max - min + 1)) + min);
}