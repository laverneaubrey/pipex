/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:46:28 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:57:01 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t	n)
{
	size_t	i;

	i = 0;
	while ((n > i) && (dst || src))
	{
		((unsigned char *)dst)[i] = ((unsigned const char *)src)[i];
		i++;
	}
	return (dst);
}
