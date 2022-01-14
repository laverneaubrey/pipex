/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:21 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:48:23 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t	dstsize)
{
	size_t	fis;
	size_t	sec;

	fis = 0;
	sec = 0;
	while (dst[fis] && fis < dstsize)
		fis ++;
	while (dstsize > (fis + sec + 1) && src[sec])
	{
		dst[fis + sec] = src[sec];
		sec++;
	}
	if (fis < dstsize)
		dst[fis + sec] = '\0';
	return (fis + ft_strlen(src));
}
