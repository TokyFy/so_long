/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:31:12 by franaivo          #+#    #+#             */
/*   Updated: 2024/02/23 16:31:12 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char	*ptr;

	ptr = s;
	while (*ptr)
	{
		f(ptr - s, ptr);
		ptr++;
	}
}
