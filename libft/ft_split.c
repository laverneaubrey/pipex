/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:47:39 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 19:01:29 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	makeclean(char **s, int i)
{
	while (i > 0)
	{
		free(s[i]);
		i--;
	}
	free(s);
}

void	line(char **stolb, int nw, const char *s, char cut)
{
	int	coul;
	int	i;

	i = 0;
	while ((s) && (nw > i))
	{
		while ((*s == cut) && (*s != '\0'))
			s++;
		coul = 0;
		while (*s && (*s != cut))
		{
			coul++;
			s++;
		}
		stolb[i] = (char *) malloc(sizeof(char) * (coul + 1));
		if (!*stolb)
			makeclean(stolb, i);
		ft_strlcpy(stolb[i], s - coul, coul + 1);
		i++;
	}
	stolb[nw] = NULL;
}

int	couword(char const *str, char cut)
{
	int	cou;

	cou = 0;
	if (!(str[0]))
		return (cou);
	while (*str)
	{
		while (ft_strchr(&cut, *str) && *str)
			str++;
		while (*str && (*str != cut))
			str++;
		cou++;
	}
	if (*--str == cut)
		return (cou - 1);
	return (cou);
}

char	**ft_split(char const *s, char c)
{
	int		nw;
	char	**stolb;

	if (s == NULL)
		return (NULL);
	nw = couword(s, c);
	stolb = (char **) malloc(sizeof(char *) * (nw + 1));
	if (!stolb)
		return (NULL);
	line(stolb, nw, s, c);
	return (stolb);
}
