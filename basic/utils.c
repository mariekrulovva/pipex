/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:15:43 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/16 16:15:46 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(char *str, int code)
{
	if (code == 1)
	{
		perror(str);
		exit(1);
	}
	if (code == 2)
	{
		write(1, str, ft_strlen(str));
		exit(1);
	}
}

void	ft_free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

static char	**ft_valid_path(char **envp)
{
	char	*tmp_path;
	char	**path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	tmp_path = ft_strdup(envp[i] + 5);
	path = ft_split(tmp_path, ':');
	free(tmp_path);
	return (path);
}

char	*ft_command_path(char *argv, char **envp, int i)
{
	char	**path;
	char	*command;
	char	*path_comm;

	command = ft_strjoin("/", argv);
	path = ft_valid_path(envp);
	while (path[i])
	{
		path_comm = ft_strjoin(path[i], command);
		if (!access(path_comm, F_OK))
		{
			free(command);
			ft_free_arr(path);
			return (path_comm);
		}
		else
		{
			free(path_comm);
			path_comm = NULL;
		}
		i++;
	}
	ft_free_arr(path);
	free(command);
	return (NULL);
}

void	ft_execute(char *argv, char **envp)
{
	char	**command;
	char	*path;

	command = ft_split(argv, ' ');
	path = ft_command_path(command[0], envp, 0);
	if (execve(path, command, envp) == -1)
		ft_error("Command", 1);
}
