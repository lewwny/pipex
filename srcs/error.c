/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:08:00 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/13 13:50:45 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	file_error(void)
{
	ft_printf("Error\nA file can't be open\n");
	exit(1);
}

void	path_error(void)
{
	ft_printf("Error\nPath error\n");
	exit(1);
}

void	malloc_error(t_pipe *pipex)
{
	if (pipex)
	{
		if (pipex->cmd)
			free_cmd(pipex->cmd);
		if (pipex->paths)
			free_split(pipex->paths);
		if (pipex->path_cmd)
			free_split(pipex->path_cmd);
	}
	ft_printf("Error\nMalloc error\n");
	exit(1);
}

void	access_error(t_pipe *pipex)
{
	if (pipex->cmd)
		free_cmd(pipex->cmd);
	if (pipex->paths)
		free_split(pipex->paths);
	if (pipex->path_cmd)
		free_split(pipex->path_cmd);
	ft_printf("Error\nCommand does not found\n");
	exit(1);
}

void	error_pipe(t_pipe *pipex)
{
	if (pipex->cmd)
		free_cmd(pipex->cmd);
	if (pipex->paths)
		free_split(pipex->paths);
	if (pipex->path_cmd)
		free_split(pipex->path_cmd);
	ft_printf("Error\nPipe error\n");
	exit(1);
}
