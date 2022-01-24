/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 12:38:32 by bbayard           #+#    #+#             */
/*   Updated: 2022/01/22 12:38:35 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmd_exec(char *command, char **envp)
{
	char	**cmd_args;
	char	*path;
	char	buff;

	if (only_spaces(command))
	{
		cmd_args = ft_split(command, ' ');
		if (cmd_args == 0)
			exit(2);
		path = find_path(cmd_args[0], envp);
		if (path == 0)
			exit(1);
		free(cmd_args[0]);
		cmd_args[0] = path;
		execve(cmd_args[0], cmd_args, envp);
	}
	else
	{
		cmd_args = ft_split(command, ' ');
		while (read(0, &buff, 1))
			write(1, &buff, 1);
		close(1);
	}
}

void	fd_closer(int dp_0, int dp_1, int cls_1, int cls_2)
{
	if (dup2(dp_0, 0) == -1)
		exit(3);
	if (dup2(dp_1, 1) == -1)
		exit(3);
	close(cls_1);
	close(cls_2);
}	

void	ft_waitpid(int pid, int *status, char *cmd)
{
	waitpid(pid, status, 0);
	if (!WIFEXITED(*status))
	{
		ft_putnbr_fd(pid, 2);
		ft_putstr_fd(" ERROR ", 2);
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	pipex(int fd_in, int fd_out, char *cmd[2], char **envp)
{
	int	pid[2];
	int	status;

	create_pipe(pid);
	if (fork() == 0)
	{
		fd_closer(fd_in, pid[1], fd_out, pid[0]);
		cmd_exec(cmd[0], envp);
	}
	else
	{
		ft_waitpid(1, &status, cmd[0]);
		close(pid[1]);
		if (fork() == 0)
		{
			fd_closer(pid[0], fd_out, fd_in, pid[1]);
			cmd_exec(cmd[1], envp);
		}
		else
			ft_waitpid(1, &status, cmd[1]);
	}
	close(pid[0]);
}

int	main(int argc, char **argv, char **envp)
{
	char	*comand[2];
	int		files_1;
	int		files_2;

	if (argc != 5)
	{
		ft_putstr_fd("Pipex takes exactly 4 arguments\n", 2);
		exit(1);
	}
	comand[0] = argv[2];
	comand[1] = argv[3];
	files_1 = open(argv[1], O_RDONLY, 0);
	if (files_1 < 0)
		pr_err(argv[1]);
	files_2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (files_2 < 0)
		pr_err(argv[4]);
	pipex(files_1, files_2, comand, envp);
}
