/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:46:38 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:46:40 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t	len)
{
	size_t				i;
	unsigned char		*to;
	const unsigned char	*from;

	i = len;
	to = (unsigned char *)dst;
	from = (const unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	if (to > from)
		while (len--)
			to[len] = from[len];
	else if (to <= from)
		while (0 < i--)
			to[len - i - 1] = from[len - i - 1];
	return (dst);
}
