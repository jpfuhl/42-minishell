/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:37:04 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/10 20:53:35 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/env.h"

void	add_env_node(t_env *head, char **key_value_pair)
{
	t_env	*node;

	node = get_last_env_node(head);
	node->next = create_env_node();
	if (node->next)
	{
		fill_env_node(node->next, key_value_pair);
		node->next->prev = node;
	}
}
