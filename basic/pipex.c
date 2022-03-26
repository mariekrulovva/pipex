/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:15:07 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/25 19:13:07 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	ft_child(char **argv, char **envp, int *fd)
{
	int		fd_input;

	fd_input = open(argv[1], O_RDONLY);
	if (fd_input == -1)
		ft_error("In file", 1);
	dup2(fd[1], STDOUT_FILENO);
	dup2(fd_input, STDIN_FILENO);
	close(fd[0]);
	ft_execute(argv[2], envp);
}

static void	ft_parent(char **argv, char **envp, int *fd)
{
	int		fd_out;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		ft_error("Out file", 1);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd_out, STDOUT_FILENO);
	close(fd[1]);
	ft_execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	pid;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Pipe", 1);
		pid = fork();
		if (pid == -1)
			ft_error("Pid", 1);
		if (pid == 0)
			ft_child(argv, envp, fd);
		waitpid(0, NULL, 0);
		ft_parent(argv, envp, fd);
		close(fd[0]);
		close(fd[1]);
	}
	else
		ft_error("Error: Not enough arguments\n", 2);
}
