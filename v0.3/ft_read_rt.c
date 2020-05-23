/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_read_rt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/18 19:33:01 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/18 19:33:01 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_read_rt(t_env *env, t_shape *obj, int fd)
{
	char	*content;
	char	**lines;
	int		c;
	int		i;//TO REMOVE

	i = 0;//TO REMOVE
	content = ft_content(fd, 1);//WORKS
	c = ft_check_and_count(content, 0, 0);//WORKS
	if (c == -1)
	{
		free(content);
		return (-1);
	}
	lines = (char **)malloc(sizeof(char *) * (c + 5));
	if (!lines || c == -1)
	{
		free(content);
		return (-1);
	}
	ft_cut(lines, content);
	while (lines[i] != NULL)//TO REMOVE
	{
		printf("Line %i: %s\n", (i + 1), lines[i]);//TO REMOVE
		i++;//TO REMOVE
	}
	obj = ft_info(lines, obj, env, c);
	ft_free(lines);
	return (c);
}

int			main(int argc, char **argv)
{
	t_env	env;
	t_shape	obj;
	int		fd;

	if (argc != 2)
		return (write(2, "Error\nWrong number of arguments\n", 32));
	fd = open(argv[1], O_RDONLY);
	fd = ft_read_rt(&env, &obj, fd);
	if (fd == -1)//Map goes in, all info goes to structs
		return(write(2, "Error\nInvalid map\n", 18));
	write(1, "Looks fine, this is the end of the program\n", 44);
	return (0);
}