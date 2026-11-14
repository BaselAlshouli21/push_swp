/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balshoul <balshoul@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 16:17:51 by balshoul          #+#    #+#             */
/*   Updated: 2026/11/14 14:20:23 by balshoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*llist;

	llist = malloc(sizeof(t_list));
	if (!llist)
		return (NULL);
	llist->content = content;
	llist->next = NULL;
	return (llist);
}
