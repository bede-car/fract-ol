/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 02:24:00 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/25 21:45:03 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*prt;
	size_t	mult;

	mult = nmemb * size;
	if (nmemb == SIZE_MAX || size == SIZE_MAX || size != (mult / nmemb))
		return (NULL);
	prt = malloc(mult);
	if (!prt)
		return (NULL);
	ft_bzero(prt, (mult));
	return (prt);
}
