/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_atoi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amait-ou <amait-ou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 00:40:23 by amait-ou          #+#    #+#             */
/*   Updated: 2023/03/27 00:40:49 by amait-ou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	contain(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		++s;
	}
	return (0);
}

static int	spaces(char c)
{
	return (contain("\t\n\v\f\r ", c));
}

static int	signs(char c)
{
	return (contain("-+", c));
}

int	philosopher_atoi(const char *str)
{
	char	*p;
	int		s;
	int		r;

	p = (char *)str;
	s = 1;
	r = 0;
	while (spaces(*p))
		++p;
	if (signs(*p))
	{
		if (*p == '-')
			s *= -1;
		++p;
	}
	while (*p >= '0' && *p <= '9')
	{
		r = r * 10 + *p - 48;
		++p;
	}
	return (r * s);
}
