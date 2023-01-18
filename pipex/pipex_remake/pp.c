/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:30:49 by aikram            #+#    #+#             */
/*   Updated: 2023/01/18 15:37:05 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

void	close_ppe(t_info *info)
{
	close(info->pp[0]);
	close(info->pp[1]);
}

void	get_path(t_info *info)
{
	int	i;

	i = 0;
	while (info->env[i] && ft_strncmp("PATH", info->env[i], 4))
		i++;
	info->pthz = ft_split(info->env[i] + 5, ':');
}

void	pipex(t_info *info)
{
	if (pipe(info->pp) == -1)
	{
		msg_err(ERR_PPE);
		return ;
	}
	get_path(info);
	info->pid1 = fork();
	if (info->pid1 == -1)
	{
		msg_err(ERR_FRK);
		return ;
	}
	if (!info->pid1)
		child_a(info);
	info->pid2 = fork();
	if (info->pid2 == -1)
	{
		msg_err(ERR_FRK);
		return ;
	}
	if (!info->pid2)
		child_b(info);
	close_ppe(info);
	waitpid(info->pid1, NULL, 0);
	waitpid(info->pid2, NULL, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->vec = argv;
	info->env = envp;
	if (argc != 5)
		err_ext(ERR_INP);
	info->in = open(argv[1], O_RDONLY);
	if (info->in == -1)
		err_ext(ERR_INF);
	info->out = open(argv[4], O_CREAT | O_TRUNC | O_RDONLY, 0644);
	if (info->out == -1)
		err_ext(ERR_OUF);
	pipex(info);
	free_parent(info);
}
