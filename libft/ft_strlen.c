/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:31:22 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/24 09:45:54 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_size_t	ft_strlen(const char *s)
{
	if (s[0] == '\0')
		return (0);
	return (1 + ft_strlen(++s));
}

t_size_t	ft_strlen_set(const char *s, const char *set)
{
	if (*s == '\0' || !ft_strrchr(set, *s))
		return (0);
	return (1 + ft_strlen_set(++s, set));
}
