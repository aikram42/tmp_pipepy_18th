/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:00:13 by aikram            #+#    #+#             */
/*   Updated: 2023/01/18 15:42:34 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pp.h"

void	free_parent(t_info *info)
{
	int	i;

	i = -1;
	close(info->in);
	close(info->out);
	while (info->pthz[++i])
		free(info->pthz[i]);
	free(info->pthz);
	free(info);
}

void	free_child(t_info *info)
{
	int	i;

	i = 0;
	while (info->cmd[i])
	{
		free(info->cmd[i]);
		i++;
	}
	free(info->cmd);
	if (info->cmd_p)
		free(info->cmd_p);
}