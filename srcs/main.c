/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:57:36 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/13 13:04:20 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	exit_program(t_pipe *pipex)
{
	int	i;

	i = 0;
	while (pipex->paths[i])
		free(pipex->paths[i++]);
	free(pipex->paths);
	free_cmd(pipex->cmd);
	free_split(pipex->path_cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	test_arg(argc);
	open_files(&pipex, argv);
	get_path(&pipex, envp[27]);
	take_commands(&pipex, argc, argv);
	pipex_func(&pipex, envp);
	exit_program(&pipex);
	return (0);
}
