/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:48:49 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:48:51 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*stng;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	stng = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!stng)
		return (NULL);
	while (s[i])
	{
		stng[i] = f(i, s[i]);
		i++;
	}
	stng[i] = '\0';
	return (stng);
}
