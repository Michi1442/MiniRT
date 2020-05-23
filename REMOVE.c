#include "minirt.h"

void			print_structs(t_env *env, t_shape *obj)//TO REMOVE!!
{
	printf("Resolution:		%ix%i\n", env->res[0], env->res[1]);
	printf("Ambience intesity:	%f				Color: %i, %i, %i\n", 
			env->amb, env->amb_rgb[0], env->amb_rgb[1], env->amb_rgb[0]);
	while (obj->next != NULL)
	{
		if (obj->type[0] == 'c' && obj->type[1] != 'y')
			printf("Camera location: %f, %f, %f			Vector: %f, %f, %f			FOV: %i\n",
					obj->loc_cero[0], obj->loc_cero[1], obj->loc_cero[2],
					obj->vector[0], obj->vector[1], obj->vector[2], obj->color[0]);
		if (obj->type[0] == 'c' && obj->type[1] == 'y')
			printf("Cilinder location: %f, %f, %f			Vector: %f, %f, %f			Diameter: %f		Side: %f		Color: %i, %i, %i\n",
					obj->loc_cero[0], obj->loc_cero[1], obj->loc_cero[2],
					obj->vector[0], obj->vector[1], obj->vector[2], 
					obj->diam, obj->side, 
					obj->color[0], obj->color[1], obj->color[2]);
		if (obj->type[0] == 'l')
			printf("Light location: %f, %f, %f			Color: %i, %i, %i\n",
					obj->loc_cero[0], obj->loc_cero[1], obj->loc_cero[2],
					obj->color[0], obj->color[1], obj->color[2]);
		if (obj->type[0] == 'p')
			printf("Plane location: %f, %f, %f			Vector: %f, %f, %f			Color: %i, %i, %i\n",
					obj->loc_cero[0], obj->loc_cero[1], obj->loc_cero[2],
					obj->vector[0], obj->vector[1], obj->vector[2], 
					obj->color[0], obj->color[1], obj->color[2]);
		if (obj->type[0] == 's' && obj->type[1] == 'p')
			printf("Sphere location: %f, %f, %f			Diameter: %f					Color: %i, %i, %i\n",
					obj->loc_cero[0], obj->loc_cero[1], obj->loc_cero[2],
					obj->diam, 
					obj->color[0], obj->color[1], obj->color[2]);
		if (obj->type[0] == 's' && obj->type[1] == 'q')
			printf("Cube location: %f, %f, %f			Vector: %f, %f, %f			Side: %f			Color: %i, %i, %i\n",
					obj->loc_cero[0], obj->loc_cero[1], obj->loc_cero[2],
					obj->vector[0], obj->vector[1], obj->vector[2], 
					obj->side, 
					obj->color[0], obj->color[1], obj->color[2]);
		if (obj->type[0] == 't')
			printf("Triangle location one: %f, %f, %f		Triangle location two: %f, %f, %f	Triangle location three: %f, %f, %f	Color: %i, %i, %i\n",
					obj->loc_cero[0], obj->loc_cero[1], obj->loc_cero[2],
					obj->loc_one[0], obj->loc_one[1], obj->loc_one[2],
					obj->loc_two[0], obj->loc_two[1], obj->loc_two[2],
					obj->color[0], obj->color[1], obj->color[2]);
		obj = obj->next;
	}
}