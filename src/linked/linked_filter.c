/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vivan-de <vivan-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 20:44:37 by vivan-de          #+#    #+#             */
/*   Updated: 2022/12/10 11:52:54 by vivan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			validate_args(t_linked **list);

t_linked	*linked_filter(t_linked **list, t_linked_filter_fn fn)
{
	t_linked		*new_list;
	t_node			*current_node;
	unsigned int	i;
	int				filter_result;

	if (!validate_args(list))
		return (NULL);
	new_list = linked_new_list();
	current_node = (*list)->head;
	if (!new_list)
		return (NULL);
	i = 0;
	while (i++ < (*list)->size)
	{
		filter_result = fn(current_node->content);
		if (filter_result)
			linked_add_back(&new_list, linked_new_node(current_node->content));
		current_node = current_node->next;
	}
	return (new_list);
}
