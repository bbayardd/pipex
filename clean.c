/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:49:53 by bbayard           #+#    #+#             */
/*   Updated: 2022/01/23 17:49:56 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" 

void	pr_err(char *filename)
{
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(filename, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

void	free_pointerpointer(char **pathvar)
{
	char	**tmp;

	tmp = pathvar;
	while (*tmp)
	{
		free(*tmp);
		tmp++;
	}
	free(pathvar);
}
