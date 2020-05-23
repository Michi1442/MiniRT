/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minirt_utils_three.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: migalvar <migalvar@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/22 20:03:27 by migalvar      #+#    #+#                 */
/*   Updated: 2020/05/22 20:36:25 by migalvar      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*int			ft_parse_loc(t_shape *obj, char *lines, int i)
{
	obj->loc_cero[0] = ft_simple_ftoi(lines, &i, obj->loc_cero[0]);
	if (obj->type == "tr")
	{

	}
}*/

void		ft_parse_obj(char *lines, t_shape *obj)
{
	int		i;

	i = 0;
	i = ft_skip_c(lines, i, ' ');
	obj->type[0] = lines[i];
	i++;
	obj->type[1] = lines[i];
/*	while (lines[i] != '\0')
	{
		i = ft_skip_c(lines, i, ' ');
		i = ft_parse_loc(obj, lines, i);
	}*/
}