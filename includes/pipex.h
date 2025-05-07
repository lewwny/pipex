/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 16:17:27 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/07 22:14:44 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_pipe
{
	int		fd_infile;
	int		fd_outfile;
	char	*infile;
}	t_pipe;

void	test_arg(int argc);
void	file_error(void);
void	open_files(t_pipe *pipex, char **argv);

#endif
