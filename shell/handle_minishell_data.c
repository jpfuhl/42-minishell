/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_minishell_data.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:49:33 by arendon-          #+#    #+#             */
/*   Updated: 2022/05/20 22:14:07 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	free_minishell_data(t_data *data)
{
	clear_history();
	free_env_list(data->env_head);
	if (data->cmdline != NULL)
		free(data->cmdline);
	free(data);
}

void	init_minishell_data(t_data *data)
{
	data->prompt = "MiniShell Ƹ̵̡Ӝ̵̨̄Ʒ ";
	data->pipes = 0;
	data->pipe_fd[0] = 0;
	data->pipe_fd[1] = 0;
	data->tmp_fd = 0;
	data->cmdline = NULL;
	data->pro_head = NULL;
	data->builtin_code = 0;
}

t_data	*create_minishell_data(int argc, char **argv, char **envp)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->env_head = create_env_list(envp);
	if (!data->env_head)
		exit(EXIT_MALLOC_FAILURE);
	data->stdin_fd = dup(STDIN_FILENO);
	data->stdout_fd = dup(STDOUT_FILENO);
	if (data->stdin_fd == -1 || data->stdout_fd == -1)
		exit(EXIT_DUP_FAILURE);
	data->argc = argc;
	data->argv = argv;
	return (data);
}
