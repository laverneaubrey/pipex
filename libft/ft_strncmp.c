/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:49:00 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:49:01 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t	n)
{
	unsigned char	*fis;
	unsigned char	*sec;
	size_t			i;

	i = 0;
	fis = (unsigned char *)s1;
	sec = (unsigned char *)s2;
	while ((fis[i] == sec[i]) && n > i && fis[i])
		i++;
	if (n == i)
		return (0);
	return (fis[i] - sec[i]);
}
