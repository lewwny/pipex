/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:48:07 by lengarci          #+#    #+#             */
/*   Updated: 2025/05/19 10:50:50 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

static void	exec_cmd(t_pipe *pipex, char **envp, int i)
{
	if (pipex->path_cmd[i])
		execve(pipex->path_cmd[i], pipex->cmd[i], envp);
	ft_puterror("Error\nCommand <");
	ft_puterror(pipex->cmd[i][0]);
	ft_puterror("> does not found\n");
	free_cmd(pipex->cmd, pipex);
	free_split_n(pipex->path_cmd, pipex->cmd_count);
	free_split(pipex->paths, pipex);
	exit(127);
}

static void	son_program(t_pipe *pipex, char **envp, int input_fd, int output_fd)
{
	dup2(input_fd, 0);
	dup2(output_fd, 1);
	exec_cmd(pipex, envp, pipex->i);
}

static void	last_pipe(t_pipe *pipex, int pipe_in, char **envp)

void	pipex_func(t_pipe *pipex, char **envp, char **argv, int argc)
{
	int		fd[2];
	int		pipe_in;
	pid_t	pid;

	pipex->i = 0;
	pipe_in = pipex->fd_infile;
	while (pipex->i < pipex->cmd_count - 1)
	{
		if (pipe(fd) == -1)
			error_pipe(pipex);
		pid = fork();
		if (pid == 0)
			son_program(pipex, envp, pipe_in, fd[1]);
		close(fd[1]);
		if (pipe_in != pipex->fd_infile)
			close(pipe_in);
		pipe_in = fd[0];
		pipex->i++;
	}
	pipex->fd_outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC,
			0644);
	pid = fork();
	if (pid == 0)
		son_program(pipex, envp, pipe_in, pipex->fd_outfile);
	close(pipe_in);
	close(pipex->fd_outfile);
	while (wait(NULL) < 0)
	{
	}
}
