/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:46:16 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:46:18 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t	n)
{
	unsigned char	*fir;
	unsigned char	*sec;

	fir = (unsigned char *)s1;
	sec = (unsigned char *)s2;
	if ((fir == sec) || n == 0)
		return (0);
	while (n)
	{
		if (*fir != *sec)
			return (*fir - *sec);
		fir++;
		sec++;
		n--;
	}
	return (0);
}
