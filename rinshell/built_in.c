/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frariel <frariel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:58:36 by frariel           #+#    #+#             */
/*   Updated: 2021/05/10 16:08:10 by frariel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**init_built_in_array()
{
	char	**built_in;

	built_in = (char**)malloc(sizeof(char*) * 8);
	built_in[0] = ft_strdup("echo");
	built_in[1] = ft_strdup("cd");
	built_in[2] = ft_strdup("pwd");
	built_in[3] = ft_strdup("export");
	built_in[4] = ft_strdup("unset");
	built_in[5] = ft_strdup("env");
	built_in[6] = ft_strdup("exit");
	built_in[7] = NULL;
	return (built_in);
}
