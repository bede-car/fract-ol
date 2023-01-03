/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:27:09 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/23 00:40:41 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*first;
	unsigned char	*second;
	size_t			i;

	first = (unsigned char *)str1;
	second = (unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (n == 0)
			return (0);
		if (first[i] != second[i])
			return (first[i] - second[i]);
		i++;
	}
	return (0);
}
