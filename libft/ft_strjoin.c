/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:07 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:48:08 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*stng;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	stng = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!(stng))
		return (NULL);
	ft_memcpy(stng, s1, len1);
	ft_memcpy(&stng[len1], s2, len2);
	stng[len1 + len2] = '\0';
	return (stng);
}
