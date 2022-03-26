/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:12:45 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/16 16:12:49 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "../lib/libft.h"

void	ft_execute(char *argv, char **envp);
void	ft_error(char *str, int code);
int		open_file(char *av, int i);
void	check_error(void);
int		get_next_line(char **line);
void	command(char *av, char **envp);

#endif