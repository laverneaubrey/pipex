/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:12:43 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/15 19:12:48 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

static void	ft_free_mass(char **matrix)
{
	int	j;

	j = 0;
	while (matrix[j])
		j++;
	while (matrix[j])
	{
		free(matrix[j]);
		matrix[j] = NULL;
		j--;
	}
	if (matrix[j])
	{
		free(matrix);
		matrix = NULL;
	}
}

static void	ft_exit(int i)
{
	if (i == 1)
		printf("Wrong number of arguments\n");
	else if (i == 2)
		printf("Can`t open the file\n");
	else if (i == 3)
		printf("Wrong pipe identification\n");
	else if (i == 4)
		printf("Wrong fork identification\n");
	else if (i == 5)
		printf("Wrong command name\n");
	else if (i == 6)
		printf("ERROR\n");
	exit (0);
}

static char	*path_and_way(char **flag, char **env)
{
	int		i;
	char	*temp;
	char	**envi;

	i = -1;
	while (env[++i])
	{
		temp = ft_strnstr(env[i], "PATH=", 5);
		if (temp)
			envi = ft_split(&temp[5], ':');
	}
	i = -1;
	while (envi[++i])
	{
		temp = ft_strjoin(ft_strjoin(envi[i], "/"), flag[0]);
		if (!access(temp, 1))
		{
			ft_free_mass(envi);
			return (temp);
		}
		free(temp);
	}
	ft_exit(5);
	return (0);
}

static void	process(char **flag, char **env, int fd0, int fd1)
{
	char	**temp;
	char	*way;
	int		i;

	i = 0;
	if (flag[0][i] == '/' || (flag[0][i] == '.' && flag[0][i + 1] == '/') ||
	((flag[0][i] == '.') && (flag[0][i + 1] == '.') && (flag[0][i + 2] == '/')))
	{
		if (!access(flag[0], 1))
		{
			temp = ft_split(flag[0], '/');
			while (temp[++i])
				way = flag[0];
			flag[0] = temp[i - 1];
			ft_free_mass(temp);
		}
		else
			ft_exit(5);
	}
	else
		way = path_and_way(flag, env);
	if (dup2(fd0, 0) < 0 || dup2(fd1, 1) < 0)
		ft_exit(6);
	if (execve(way, flag, env))
		ft_exit(5);
}

int	main(int argc, char **argv, char **env)
{
	int	id;
	int	fd[2];
	int	fd1;
	int	fd2;

	if (argc != 5)
		ft_exit(1);
	fd1 = open(argv[1], O_RDONLY, 0777);
	fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd1 < 0 || fd2 < 0)
		ft_exit(2);
	if (pipe(fd) < 0)
		ft_exit (3);
	id = fork();
	if (id == 0)
	{
		close(fd[0]);
		process(ft_split(argv[2], ' '), env, fd1, fd[1]);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		process(ft_split(argv[3], ' '), env, fd[0], fd2);
	}
}
