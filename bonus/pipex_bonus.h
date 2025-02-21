/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reerikai <reerikai@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:13:34 by reerikai          #+#    #+#             */
/*   Updated: 2025/02/01 18:41:16 by reerikai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <errno.h>
# include "../libft/libft.h"

						/*MANDATORY*/

void	handle_two_commands(char **argv, char **envp);
void	child_process_in(char **argv, char **envp, int *fd);
void	child_process_out(char **argv, char **envp, int *fd);
void	execute(char **argv, char **envp, int child);

					/*MULTIPLE COMMANDS*/

void	handle_many_commands(int argc, char **argv, char **envp);
void	handle_middle_commands(char **argv, char **envp, int index);
void	handle_last_command(int argc, char **argv, char **envp);
void	exec_many(char **argv, char **envp, int index);

						/*HERE DOC*/

void	handle_here_doc(int argc, char **argv, char **envp);
int		prep_here_doc(char **argv);

						/*PATH UTILS*/

char	*find_my_path(char **full_path);
char	*find_exec_path(char **envp, char **commands);
char	*get_path(char **path, char **commands);

						/*UTILS*/

void	close_fds(int *fd);
void	ft_free_array(char **array);
int		open_file(char *file, int code);

						/*ERROR*/

void	perror_and_exit(const char *msg);
void	empty_command_exit(char **commands);
void	command_not_found(char **commands);
void	command_not_executable(char **commands, char *exec_path);
void	file_not_found(char **commands);

#endif
