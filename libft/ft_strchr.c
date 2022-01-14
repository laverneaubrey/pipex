/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:47:49 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:47:50 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		clo;
	char	*fis;

	clo = 0;
	fis = (char *)s;
	while (fis[clo])
	{
		if (fis[clo] == (const char)c)
			return (fis + clo);
		clo++;
	}
	if (c == '\0')
		return (&fis[clo]);
	return (NULL);
}
