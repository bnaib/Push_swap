       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

int		main(int argc, char **argv)
{
	t_global_variables	gv;

	load_default(&gv, argc, argv);
	load_params(&gv);
	gv.max_index = set_index(gv.p_stacks[0]);
	if (gv.p_stacks[0]->length == 0)
		exit_program(&gv, EC_NOTHING);
	load_commands(&gv);
	do_commands(&gv);
	exit_program(&gv, check_sort(&gv));
}
