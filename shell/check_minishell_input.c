/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minishell_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:20:43 by jpfuhl            #+#    #+#             */
/*   Updated: 2022/05/23 13:44:16 by arendon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/minishell.h"

int	check_minishell_input(t_data *data)
{
	if (ft_strlen(data->cmdline) == 0)
	{
		free(data->cmdline);
		return (0);
	}
	if (wrong_input(data->cmdline) != 0)
	{
		error_exit("error", "unclosed quotes!");
		free(data->cmdline);
		return (ERROR);
	}
	if (empty_input(data->cmdline) == 0)
	{
		free(data->cmdline);
		return (0);
	}
	return (1);
}
