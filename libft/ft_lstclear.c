/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-car <bede-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 03:08:32 by bede-car          #+#    #+#             */
/*   Updated: 2022/06/26 03:18:04 by bede-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cont;

	if (!del)
		return ;
	while (*lst)
	{
		cont = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = cont;
	}
	*lst = (NULL);
}
