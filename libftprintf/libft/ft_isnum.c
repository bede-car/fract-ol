/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:10:14 by bede-car          #+#    #+#             */
/*   Updated: 2023/01/21 10:10:31 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char *s)
{
	int	flag;

	flag = 0;
	if (!s || !*s)
		return (0);
	if (*s == '-' || *s == '+')
		s++;
	if (*s == '.')
		return (0);
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != '.')
			return (0);
		if (flag > 1)
			return (0);
		if (*s == '.')
			flag++;
		s++;
	}
	if (*(s - 1) == '.')
		return (0);
	return (1);
}