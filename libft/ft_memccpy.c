/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:45:52 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 19:02:41 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t	n)
{
	size_t	i;

	i = 0;
	while ((n > i) && (dst || src || c))
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		if (((const unsigned char *)dst)[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
