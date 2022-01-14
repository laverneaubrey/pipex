/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:50:10 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:50:11 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		clo;
	char	*fis;

	clo = ft_strlen(s) - 1;
	fis = (char *)s;
	if (c == '\0')
		return (&fis[clo + 1]);
	while (clo >= 0)
	{
		if (fis[clo] == (char)c)
			return (fis + clo);
		clo--;
	}
	return (NULL);
}
