/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:40:47 by nammari           #+#    #+#             */
/*   Updated: 2021/12/04 11:41:09 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

int	exec_builtin(t_command_vars *commands)
{
	int	exit_status;
	
	exit_status = -1;
	if (ft_strcmp(commands->name[0], "cd") == 0)
		exit_status = ft_cd(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "echo") == 0)
		exit_status = ft_echo(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "pwd") == 0)
		exit_status = ft_pwd(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "env") == 0)
		exit_status = ft_env(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "exit") == 0)
		exit_status = ft_exit(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "export") == 0)
		exit_status = ft_export(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "unset") == 0)
		exit_status = ft_unset(commands->name + 1);
	if (exit_status != -1)
		variables->last_exit_status = exit_status;
	return (exit_status);
}