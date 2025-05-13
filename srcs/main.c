/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:57:36 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/13 08:57:41 by lengarci         ###   ########.fr       */
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
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	pipex;

	test_arg(argc);
	open_files(&pipex, argv);
	get_path(&pipex, envp[27]);
	exit_program(&pipex);
	return (0);
}
