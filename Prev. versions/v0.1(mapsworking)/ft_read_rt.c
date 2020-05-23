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

/*void		ft_info(char *content, t_shape **obj, t_env *env, int i)
{
	ft_pop(env, obj);

}*/

int			ft_read_rt(/*t_env *env, t_shape **obj, */int fd)
{
	char	*content;
	char	**lines;
	int		count;
	int		i;//TO REMOVE

	i = 0;//TO REMOVE
	content = ft_content(fd, 1);//WORKS
	if (content == NULL)
		return (-1);
	count = ft_check_and_count(content, 0);//WORKS
	if (count == -1)
		return (-1);
	lines = (char **)malloc(sizeof(char *) * (count + 5));
	if (!lines)
		return (-1);
	ft_cut(lines, content);
	while (lines[i] != NULL)//TO REMOVE
	{
		printf("Line %i: %s\n", (i + 1), lines[i]);//TO REMOVE
		i++;//TO REMOVE
	}
//	ft_info(env, obj, content, 0);
	ft_free(lines);
	return (count);
}

int			main(int argc, char **argv)
{
//	t_env	env;
//	t_shape	obj[256];
	int		fd;

	if (argc != 2)
		return (write(2, "Error\nWrong number of arguments\n", 32));
	fd = open(argv[1], O_RDONLY);
	if (ft_read_rt(/*&env, &obj, */fd) == -1)//Map goes in, all info goes to structs
		return(write(2, "Error\nInvalid map\n", 18));
	write(1, "Looks fine, this is the end of the program\n", 44);
	return (0);
}