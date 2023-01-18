/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 14:56:20 by bcaffere          #+#    #+#             */
/*   Updated: 2023/01/15 17:09:43 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	parent_free(t_ppxb *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	while (pipex->cmd_paths[i])
	{
		free(pipex->cmd_paths[i]);
		i++;
	}
	free(pipex->cmd_paths);
	free(pipex->pipe);
}

void	child_free(t_ppxb *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_args[i])
	{
		free(pipex->cmd_args[i]);
		i++;
	}
	free(pipex->cmd_args);
	free(pipex->cmd);
}

void	pipe_free(t_ppxb *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	free(pipex->pipe);
	msg(ERR_ENVP);
	exit(1);
}
