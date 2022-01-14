/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:53:11 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:53:13 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t	len)
{
	size_t	leng;
	char	*stng;

	if (!s || (start >= ft_strlen(s) || (len <= 0)))
		return (ft_strdup(""));
	leng = ft_strlen(&s[start]);
	if (len > leng)
	{
		stng = (char *)malloc(sizeof(*s) * (leng));
		if (!stng)
			return (NULL);
		ft_memmove(stng, &s[start], leng);
		stng[len] = '\0';
	}
	else
	{
		stng = malloc(sizeof(*s) * (len + 1));
		if (!stng)
			return (NULL);
		ft_memmove(stng, &s[start], len);
		stng[len] = '\0';
	}
	return (stng);
}
