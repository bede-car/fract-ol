/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:33:43 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/26 04:19:44 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aux;

	if (!f || !del || !lst)
		return (NULL);
	aux = ft_lstnew(f(lst->content));
	if (!aux)
	{
		ft_lstclear(&aux, del);
		return (NULL);
	}
	aux->next = ft_lstmap(lst->next, f, del);
	return (aux);
}
