/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:33:06 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/26 04:54:27 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	len_max;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_strdup(""));
	if ((len_s - start) <= len)
		len_max = len_s - start;
	else
		len_max = len;
	sub = malloc(len_max + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, &s[start], len_max + 1);
	return (sub);
}
