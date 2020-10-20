       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_global_variables	gv;

	load_default(&gv, argc, argv);
	load_params(&gv);
	if (gv.p_stacks[0]->length == 0)
		exit_program(&gv, EC_OK);
	gv.max_index = set_index(gv.p_stacks[0]);
	if ((gv.p_stacks[2] = class_list_copy(gv.p_stacks[0])) == NULL)
		exit_program(&gv, EC_ERROR);
	solve(&gv, norm_equally, gv.p_commands[0]);
	class_list_destruct(&(gv.p_stacks[0]));
	if ((gv.p_stacks[0] = class_list_copy(gv.p_stacks[2])) == NULL)
		exit_program(&gv, EC_ERROR);
	solve(&gv, norm_more, gv.p_commands[1]);
	class_list_destruct(&(gv.p_stacks[0]));
	if ((gv.p_stacks[0] = class_list_copy(gv.p_stacks[2])) == NULL)
		exit_program(&gv, EC_ERROR);
	print_commands(&gv, (gv.p_commands[0]->length < gv.p_commands[1]->length) ?
		gv.p_commands[0] : gv.p_commands[1]);
	exit_program(&gv, EC_OK);
}
