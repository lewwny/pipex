/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:53:47 by lengarci          #+#    #+#             */
/*   Updated: 2025/05/13 15:47:06 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_cmd(char ***cmd, t_pipe *pipex)
{
	int	i;
	int	j;

	i = 0;
	while (i < pipex->cmd_count)
	{
		j = 0;
		while (cmd[i][j])
		{
			free(cmd[i][j]);
			j++;
		}
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	free_split(char **tab, t_pipe *pipex)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (i < pipex->cmd_count)
		free(tab[i++]);
	free(tab);
}
