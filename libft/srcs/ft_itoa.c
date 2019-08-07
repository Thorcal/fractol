/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuisais <spuisais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:05:41 by spuisais          #+#    #+#             */
/*   Updated: 2019/04/16 15:36:32 by spuisais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nb;

	len = ft_intlen(n);
	nb = n;
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	str[len--] = '\0';
	if (nb == 0)
		str[len--] = '0';
	if (nb < 0)
	{
		nb = -nb;
		str[0] = '-';
	}
	while (nb != 0)
	{
		str[len--] = (nb % 10 > 9) ? (nb % 10 - 10) : nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}
