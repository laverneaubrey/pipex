/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:49:14 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:54:51 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t	len)
{
	char	*s1;
	char	*s2;
	size_t	len2;
	size_t	i;
	size_t	exi;

	i = 0;
	s1 = (char *)haystack;
	s2 = (char *)needle;
	len2 = (ft_strlen(s2));
	if (!s2 || !len2)
		return (s1);
	while (s1[i] && (i <= (len - len2)) && (len >= len2))
	{
		exi = 0;
		while (s1[i + exi] == s2[exi])
		{
			if (len2 - 1 == exi)
				return (s1 + i);
			exi++;
		}
		i = i + 1;
	}
	return (0);
}
