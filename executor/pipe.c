/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:38:05 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/19 16:58:50 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/executor.h"

int	redirect_pipe(t_data *data, t_program *pro_node)
{
	if (data->pipes > 0 && pro_node == data->pro_head)
	{
		if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
			return (-1);
	}
	else if (pro_node->next)
	{
		if (dup2(data->tmp_fd, STDIN_FILENO) == -1)
			return (-1);
		if (dup2(data->pipe_fd[1], STDOUT_FILENO) == -1)
			return (-1);
	}
	else if (!pro_node->next)
	{
		if (dup2(data->tmp_fd, STDIN_FILENO) == -1)
			return (-1);
	}
	return (0);
}
