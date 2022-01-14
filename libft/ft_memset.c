/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:46:48 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:46:50 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t	len)
{
	unsigned char	all;
	unsigned char	*num;

	all = (unsigned char)c;
	num = (unsigned char *)b;
	while (len-- > 0)
		num[len] = all;
	return (b);
}
