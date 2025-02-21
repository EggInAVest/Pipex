/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:22:25 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 18:46:07 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include "./libft/libft.h"

						/*EXECUTION*/

void	child_process_in(char **argv, char **envp, int *fd);
void	child_process_out(char **argv, char **envp, int *fd);
void	execute(char **argv, char **envp, int child);
char	*find_exec_path(char **envp, char **commands);

						/*UTILS*/

char	*get_path(char **path, char **commands);
char	*find_my_path(char **full_path);
void	check_args(int argc);
void	ft_free_array(char **array);
void	close_fds(int *fd);

						/*ERRORS*/

void	perror_and_exit(const char *msg);
void	empty_command_exit(char **commands);
void	command_not_found(char **commands);
void	command_not_executable(char **commands, char *exec_path);
void	file_not_found(char **commands);

#endif
