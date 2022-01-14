/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:46:03 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:46:07 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t	n)
{
	size_t			i;
	unsigned char	*b;

	i = 0;
	b = (unsigned char *)s;
	while ((n > i))
	{
		if (b[i] == (unsigned char)c)
			return (b + i);
		i++;
	}
	return (NULL);
}
