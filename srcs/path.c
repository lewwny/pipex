/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lengarci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 08:42:29 by lengarci          #+#    #+#             */
/*   Updated: 2025/05/13 08:50:43 by lengarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_path(t_pipe *pipex, char *path)
{
	(void)pipex;
	path = path + 5;
	if (!path)
		path_error();
	pipex->paths = ft_split(path, ':');
	if (!pipex->paths)
		malloc_error();
}
