/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:38:14 by bbayard           #+#    #+#             */
/*   Updated: 2022/01/22 12:38:18 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *s);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		main(int argc, char **argv, char **envp);
void	pipex(int fd_in, int fd_out, char *cmd[2], char **envp);
void	ft_waitpid(int pid, int *status, char *cmd);
void	fd_closer(int dp_0, int dp_1, int cls_1, int cls_2);
void	cmd_exec(char *command, char **envp);
int		only_spaces(char *s);
int		str_start_with(char *str, char *start_str);
char	*get_var(char *var, char **envp);
void	create_pipe(int fds[2]);
void	free_pointerpointer(char **pathvar);
void	pr_err(char *filename);
void	ft_putchar_fd(char c, int fd);
char	*find_path(char *command, char **envp);
char	*ft_strdup(const char *str);

#endif
