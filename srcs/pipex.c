/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:48:07 by lengarci          #+#    #+#             */
/*   Updated: 2025/05/13 13:04:10 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	exec_cmd(t_pipe *pipex, char **envp, int i)
{
	execve(pipex->path_cmd[i], pipex->cmd[i], envp);
	ft_printf("Error\nA cmd didn't exec\n");
	free_cmd(pipex->cmd);
	free_split(pipex->path_cmd);
	free_split(pipex->paths);
	exit(1);
}

void	pipex_func(t_pipe *pipex, char **envp)
{
	int	fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (pipe(fd) == -1)
		error_pipe(pipex);
	pid1 = fork();
	if (pid1 == 0)
	{
		dup2(pipex->fd_infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd(pipex, envp, 0);
	}
	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(pipex->fd_outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd(pipex, envp, 1);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
