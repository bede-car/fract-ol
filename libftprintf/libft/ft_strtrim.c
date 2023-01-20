/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:06:25 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/26 04:56:45 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	index_rev;

	if (!s1)
		return (NULL);
	if (!set)
		return ((char *)s1);
	index_rev = (ft_strlen(s1));
	index = 0;
	while (*(s1 + (index_rev - 1)) \
	&& ft_strchr(set, (int)*(s1 + (index_rev - 1))))
		index_rev--;
	while (*(s1 + index) && ft_strchr(set, (int)*(s1 + index)))
		index++;
	return (ft_substr(s1, index, (index_rev - index)));
}
