/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:30 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:48:32 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t	dstsize)
{
	size_t	i;
	size_t	num;

	num = 0;
	i = 0;
	if (!src || !dst)
		return (0);
	num = (ft_strlen(src));
	if (dstsize == 0)
		return (num);
	while ((src[i]) && (dstsize-- > 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (num);
}
