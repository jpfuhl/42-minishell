/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpfuhl <jpfuhl@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:31:32 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 10:50:11 by jpfuhl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/minishell.h"

int	g_exit_status;

int	main(int argc, char **argv, char **envp)
{
	t_data		*data;

	signal(SIGQUIT, SIG_IGN);
	signals_setter();
	data = create_minishell_data(argc, argv, envp);
	if (!data)
		return (EXIT_MALLOC_FAILURE);
	modify_shlvl(data);
	while (1)
	{
		init_minishell_data(data);
		read_minishell_input(data);
		minishell(data);
	}
	free_minishell_data(data);
	return (0);
}
