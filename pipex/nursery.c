/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nursery.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:40:26 by aikram            #+#    #+#             */
/*   Updated: 2023/01/18 19:10:01 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pcmd(t_var *var)
{
	while (*var->pths)
	{
		var->tmp = ft_strjoin(*var->pths, "/");
		var->pth = ft_strjoin(var->tmp, var->cmdarg[0]);
		free(var->tmp);
		if (!access(var->pth, 0))
			return (1);
		free(var->pth);
		var->pths++;
	}
	return (0);
}

void	first_born(t_var *var)
{
	var->cmdarg = ft_split(var->v[2], ' ');
	if (!pcmd(var))
	{
		write(2, "bullshuit", 10);
		free_child(var);
		exit(1);
	}
	dup2(var->fd[1], STDOUT_FILENO);
	dup2(var->in, STDIN_FILENO);
	close(var->fd[0]);
	close(var->fd[1]);
	close(var->in);
	execve(var->pth, var->cmdarg, var->e);
	free(var->pth);
	errs(5);
}

void	second_born(t_var *var)
{
	var->cmdarg = ft_split(var->v[3], ' ');
	if (!pcmd(var))
	{
		write(2, "bullshuit\n", 11);
		free_child(var);
		exit(1);
	}
	dup2(var->fd[0], STDIN_FILENO);
	dup2(var->out, STDOUT_FILENO);
	close(var->fd[1]);
	close(var->fd[0]);
	close(var->out);
	execve(var->pth, var->cmdarg, var->e);
	free(var->pth);
	errs(5);
}
