/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_minishell_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:25:37 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/20 16:26:06 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

void	read_minishell_input(t_data *data)
{
	if (!isatty(STDIN_FILENO))
	{
		if (dup2(data->stdin_fd, STDIN_FILENO) == -1)
			exit(EXIT_DUP_FAILURE);
	}
	data->cmdline = readline(data->prompt);
	if (data->cmdline == NULL)
	{
		write(STDERR_FILENO, "exit\n", 6);
		free_minishell_data(data);
		exit(EXIT_READLINE_FAILURE);
	}
}
