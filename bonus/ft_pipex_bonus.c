/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laubrey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 18:41:37 by laubrey           #+#    #+#             */
/*   Updated: 2021/10/18 18:41:40 by laubrey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex_bonus.h"

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
		printf("Wrong function name\n");
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
	dup2(fd0, 0);
	dup2(fd1, 1);
	if (execve(way, flag, env))
		ft_exit(5);
}

//static void	mider(int i, int id, char *argv, int argc, int fd1, int fd2, char **env, int fd00, int fd01, int fd10, int fd11)
//{
//	if (i == 2 && id == 0)
//	{
//		close(fd00);
//		process(ft_split(argv, ' '), env, fd1, fd01);
//	}
//	else if (i == argc - 2 && id == 0)
//	{
//		close(fd00);
//		close(fd01);
//		close(fd11);
//		process(ft_split(argv, ' '), env, fd10, fd2);
//	}
//	else if (id == 0)
//	{
//		close(fd00);
//		close(fd11);
//		process(ft_split(argv, ' '), env, fd10, fd01);
//	}
//	else
//	{
//		wait(NULL);
//		close(fd01);
//		if (i > 3)
//			close(fd10);
//	}
//}

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	id;
	int	fd[argc - 2][2];
	int	fd1;
	int	fd2;

	i = 1;
	if (argc < 3)
		ft_exit(1);
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0 || fd2 < 0)
		ft_exit(2);
	while (argc - 1 != ++i)
	{
		if (pipe(fd[i - 2]) < 0)
			ft_exit(3);
		id = fork();
		if (id < 0)
			ft_exit(4);
		if (i == 2 && id == 0)
		{
			close(fd[i - 2][0]);
			process(ft_split(argv[i], ' '), env, fd1, fd[i - 2][1]);
		}
		else if (i == argc - 2 && id == 0)
		{
			close(fd[i - 2][0]);
			close(fd[i - 2][1]);
			close(fd[i - 3][1]);
			process(ft_split(argv[i], ' '), env, fd[i - 3][0], fd2);
		}
		else if (id == 0)
		{
			close(fd[i - 2][0]);
			close(fd[i - 3][1]);
			process(ft_split(argv[i], ' '), env, fd[i - 3][0], fd[i - 2][1]);
		}
		else
		{
			wait(NULL);
			if
			close(fd[i - 2][1]);
			if (i > 3)
				close(fd[i - 3][0]);
		}
	}
	close(fd[i - 3][0]);
	while (--i < -1)
		wait(NULL);
	close(fd1);
	close(fd2);
}
