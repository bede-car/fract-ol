/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:01:20 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/25 22:43:03 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*strnew;
	size_t	sz;

	sz = (ft_strlen(s)+ 1);
	strnew = malloc(sz);
	if (!strnew)
		return (NULL);
	ft_strlcpy(strnew, s, sz);
	return (strnew);
}
