/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:27:22 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 14:55:33 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

static int	count_pipes(t_token *tok_head)
{
	int		pipes;
	t_token	*tmp;
	char	*str;

	pipes = 0;
	tmp = tok_head;
	while (tmp)
	{
		str = tmp->source;
		if (ft_strlen(str) == 1 && str[0] == '|')
			pipes ++;
		tmp = tmp->next;
	}
	return (pipes);
}

int	minishell(t_data *data)
{
	t_token		*tok_head;
	t_program	*pro_head;

	add_history(data->cmdline);
	if (check_minishell_input(data) <= 0)
		return (0);
	tok_head = tokenizer(data->env_head, data->cmdline);
	if (tok_head)
	{
		data->pipes = count_pipes(tok_head);
		pro_head = create_programs(tok_head, data->pipes);
		fill_all_programs(pro_head);
		data->pro_head = pro_head;
		if (g_exit_status == 0)
		{
			signals_unsetter();
			executor(data);
			signals_setter();
		}
		free_program_list(pro_head);
	}
	free(data->cmdline);
	return (g_exit_status);
}
