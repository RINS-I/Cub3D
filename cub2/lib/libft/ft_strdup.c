/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-lfd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:11:36 by aait-lfd          #+#    #+#             */
/*   Updated: 2022/10/17 13:29:28 by aait-lfd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	p = malloc(len + 1);
	i = 0;
	if (p)
	{
		while (s1[i])
		{
			p[i] = s1[i];
			i++;
		}
		p[i] = 0;
	}
	return (p);
}
