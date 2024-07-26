/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coins.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franaivo <franaivo@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 10:43:15 by franaivo          #+#    #+#             */
/*   Updated: 2024/07/26 10:43:32 by franaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*get_coin_1(void)
{
	const char	*coin_1;

	coin_1 = "./asset/xmp/props/key1.xpm,"
		"./asset/xmp/props/key2.xpm,"
		"./asset/xmp/props/key3.xpm,"
		"./asset/xmp/props/key4.xpm";
	return (coin_1);
}

const char	*get_coin_2(void)
{
	const char	*coin_2;

	coin_2 = "./asset/xmp/props/potion1.xpm,"
		"./asset/xmp/props/potion2.xpm,"
		"./asset/xmp/props/potion3.xpm,"
		"./asset/xmp/props/potion4.xpm";
	return (coin_2);
}

const char	*get_coin_3(void)
{
	const char	*coin_3;

	coin_3 = "./asset/xmp/props/heart1.xpm,"
		"./asset/xmp/props/heart2.xpm,"
		"./asset/xmp/props/heart3.xpm,"
		"./asset/xmp/props/heart4.xpm";
	return (coin_3);
}

const char	*get_coin_4(void)
{
	const char	*coin_4;

	coin_4 = "./asset/xmp/props/food1.xpm,"
		"./asset/xmp/props/food2.xpm,"
		"./asset/xmp/props/food3.xpm,"
		"./asset/xmp/props/food4.xpm";
	return (coin_4);
}
