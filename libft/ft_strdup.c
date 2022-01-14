/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:47:57 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:48:00 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		cou;
	char	*string;

	cou = 0;
	while (s1[cou])
		cou++;
	string = (char *)malloc(sizeof(*s1) * (cou + 1));
	if (string == NULL)
		return (NULL);
	string[cou] = '\0';
	while (cou--)
		string[cou] = s1[cou];
	return (string);
}
