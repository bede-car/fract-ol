/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:55:12 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/26 01:41:42 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	len_dst;
	size_t	len_src;
	size_t	return_ft;

	index = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	return_ft = len_dst + len_src;
	if (size < len_dst)
		return (size + len_src);
	while (len_dst < (size - 1) && size > 0 && src[index])
	{
		dst[len_dst] = src[index];
		len_dst++;
		index++;
	}
	dst[len_dst] = '\0';
	return (return_ft);
}
