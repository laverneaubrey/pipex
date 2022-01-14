/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:51:46 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:51:49 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*new;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while ((end > start) && ft_strrchr(set, s1[end - 1]))
		end--;
	new = malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	ft_memcpy(new, &s1[start], (end - start));
	new[end - start] = '\0';
	return (new);
}
