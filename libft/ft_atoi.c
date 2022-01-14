/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:44:14 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:44:19 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	bet;
	int		cou;

	cou = 1;
	bet = 0;
	while (str && ((*str == '\f') | (*str == '\t') | (*str == '\v')
			| (*str == '\r') | (*str == '\n') | (*str == ' ')))
		str++;
	if ((*str == '-') || (*str == '+'))
		if (*str++ == '-')
			cou = -1;
	while (str && ((*str >= '0') && (*str <= '9')))
	{
		if ((bet > 2147483647) && (cou == 1))
			return (-1);
		else if ((bet > 2147483647) && (cou == -1))
			return (0);
		bet = bet * 10 + (*str - '0');
		str++;
	}
	return (cou * bet);
}
