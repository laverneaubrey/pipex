/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:45:42 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:45:43 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size(int num)
{
	int	i;

	i = 0;
	if (num < 0)
	{
		num = num * -1;
		i++;
	}
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*vnos(char *rev, int n, int i)
{
	if (n < 0)
	{
		rev[0] = '-';
		n = n * -1;
	}
	rev[i] = '\0';
	if (n == 0)
		rev[0] = '0';
	while (n != 0)
	{
		if (n < 0)
			rev[0] = '-';
		i--;
		rev[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (rev);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*rev;

	i = size(n);
	rev = (char *)malloc(sizeof(char) * (i + 1));
	if (!rev)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(rev, "-2147483648", 12);
		return (rev);
	}
	vnos(rev, n, i);
	return (rev);
}
