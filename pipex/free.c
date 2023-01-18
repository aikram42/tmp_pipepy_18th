/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:46:33 by aikram            #+#    #+#             */
/*   Updated: 2023/01/18 18:50:21 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_parent(t_var *var)
{
	int	i;

	i = -1;
	close(var->in);
	close(var->out);
	while (var->pths[++i])
		free(var->pths[i]);
	free(var->pths);
}

void	free_child(t_var *var)
{
	int	i;

	i = 0;
	while (var->cmdarg[i])
	{
		free(var->cmdarg[i]);
		i++;
	}
	free(var->cmdarg);
	if (var->pth)
		free(var->pth);
}
