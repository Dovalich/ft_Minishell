/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 18:25:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_export(t_variable **env, char **args)
{
	t_variable	*new;

	new = get_variables_assignations(args);
	printenv(new);
	return 0;
	//new = create_variable(name, value);
	if (new == NULL)
	{
		perror("export");
		return (errno);
	}
	add_variable(env, new);
    return (0);
}