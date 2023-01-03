/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 02:22:59 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/25 23:11:00 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	p;

	p = ft_strlen((char *)s) + 1;
	while (p--)
	{
		if (s[p] == (char)c)
			return ((char *)s + p);
	}
	return (0);
}
