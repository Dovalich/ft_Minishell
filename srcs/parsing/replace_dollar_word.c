/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:31:19 by nammari           #+#    #+#             */
/*   Updated: 2021/12/01 15:33:37 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_word(char *word, char *new_wrd, char *dlr_wrd, char *dlr_value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (word[i] != '\0' && word[i] != '$')
	{
		new_wrd[j] = word[i];
		++j;
		++i;
	}
	if (word[i] == '$')
		++i;
	i = i + ft_strlen(dlr_wrd);
	while (dlr_value && *dlr_value)
	{
		new_wrd[j++] = *dlr_value;
		++dlr_value;
	}
	while (word[i] != '\0')
	{
		new_wrd[j++] = word[i];
		++i;
	}
	new_wrd[j] = '\0';
}

char	*get_dollar_word_value(t_vars *vars, char *dollar_word)
{
	t_variable *env_var;
	t_variable *global_var;

	env_var = vars->env;
	global_var = vars->global;
	while (env_var)
	{
		if (ft_strcmp(env_var->name, dollar_word) == 0)
			return (env_var->value);
		env_var = env_var->next;
	}
	while (global_var)
	{
		if (ft_strcmp(global_var->name, dollar_word) == 0)
			return (global_var->value);
		global_var = global_var->next;
	}
	return (NULL);
}

char	*replace_dollar_word(char *word, char *dollar_word, t_vars *vars)
{
	long	len;
	char	*new_wrd;
	char	*dlr_wrd_value;

	dlr_wrd_value = get_dollar_word_value(vars, dollar_word);
	len = ft_strlen(word) - ft_strlen(dollar_word) + ft_strlen(dlr_wrd_value);
	new_wrd = malloc(sizeof(*new_wrd) * len + 1);
	if (new_wrd == NULL)
		return (NULL);
	copy_word(word, new_wrd, dollar_word, dlr_wrd_value);
	free(dollar_word);
	free(word);
	return (new_wrd);
}