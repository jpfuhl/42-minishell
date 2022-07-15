/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_shlvl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:05:38 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 10:57:38 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static void	add_shlvl_node(t_data *data)
{
	char	**key_value_pair;

	key_value_pair = create_key_value_pair("SHLVL=1");
	add_env_node(data->env_head, key_value_pair);
	free_key_value_pair(key_value_pair);
}

static void	increase_shlvl(t_env *env_node)
{
	char	*tmp;
	int		shlvl;

	tmp = env_node->value;
	shlvl = ft_atoi(env_node->value);
	shlvl += 1;
	env_node->value = ft_itoa(shlvl);
	free(tmp);
}

void	modify_shlvl(t_data *data)
{
	t_env	*env_node;

	env_node = get_keymatch_env_node(data->env_head, "SHLVL");
	if (env_node)
		increase_shlvl(env_node);
	else if (!env_node)
		add_shlvl_node(data);
}
