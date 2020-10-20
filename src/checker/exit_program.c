       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

void		free_split_param(t_global_variables *p_gv)
{
	size_t		i;

	if (p_gv->split_param == NULL)
		return ;
	i = (size_t)-1;
	while (p_gv->split_param[++i] != NULL)
		free(p_gv->split_param[i]);
	free(p_gv->split_param);
	p_gv->split_param = NULL;
}

void		exit_program(t_global_variables *p_gv, t_error_code c)
{
	free_split_param(p_gv);
	if (p_gv->p_istream != NULL)
		istream_destruct(&(p_gv->p_istream));
	if (p_gv->p_commands != NULL)
		class_list_destruct(&(p_gv->p_commands));
	if (p_gv->p_stacks[0] != NULL)
		class_list_destruct(&(p_gv->p_stacks[0]));
	if (p_gv->p_stacks[1] != NULL)
		class_list_destruct(&(p_gv->p_stacks[1]));
	if (c == EC_OK)
		write(1, "OK\n", 3);
	else if (c == EC_KO)
		write(1, "KO\n", 3);
	if (c == EC_ERROR)
		write(2, "Error\n", 6);
	else
		print_usage(p_gv);
	exit(0);
}
