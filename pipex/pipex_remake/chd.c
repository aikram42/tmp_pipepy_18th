/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:00:09 by aikram            #+#    #+#             */
/*   Updated: 2023/01/18 18:40:20 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

int	get_cmd(t_info *info)
{
	char	*tmp;
	
	info->cmd_p = NULL;
	while (info->pthz)
	{
		tmp = ft_strjoin(*info->pthz, "/");
		info->cmd_p = ft_strjoin(tmp, *info->cmd);
		free(tmp);
		if (!access(info->cmd_p, X_OK))
			return (1);
		free(info->cmd_p);
		info->cmd_p = NULL;
		info->pthz++;
	}
	return (0);
}

void	child_a(t_info *info)
{
	close(info->pp[0]);
	close(info->out);
	info->cmd = ft_split(info->vec[2], ' ');
	if (!get_cmd(info))
	{
		free_child(info);
		msg_err(ERR_CMD);
		exit(1);
	}
	dup2(info->pp[1], STDOUT_FILENO);
	dup2(info->in, STDIN_FILENO);
	close(info->pp[1]);
	close(info->in);
	execve(info->cmd_p, info->cmd, info->env);
	free_child(info);
}

void	child_b(t_info *info)
{
	close(info->pp[1]);
	close(info->in);
	info->cmd = ft_split(info->vec[4], ' ');
	if (!get_cmd(info))
	{
		free_child(info);
		msg_err(ERR_CMD);
		exit(1);
	}
	dup2(info->out, STDOUT_FILENO);
	dup2(info->pp[0], STDIN_FILENO);
	close(info->pp[0]);
	close(info->out);
	execve(info->cmd_p, info->cmd, info->env);
	free_child(info);
}