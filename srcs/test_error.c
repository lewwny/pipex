/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lenygarcia <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 21:58:42 by lenygarcia        #+#    #+#             */
/*   Updated: 2025/05/07 22:05:20 by lenygarcia       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	test_arg(int argc)
{
	if (argc != 5)
	{
		ft_printf("Error, use : ./pipex file1 cmd1 cmd2 file2\n");
		exit(1);
	}
}
