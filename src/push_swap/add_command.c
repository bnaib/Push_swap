       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.18 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

void			add_command(
	t_global_variables *p_gv,
	t_class_list *p_command_list,
	void (*command)(t_global_variables *))
{
	t_command_list_content	content;

	content.command = command;
	if (class_list_create_element_to_end(
		p_command_list, &content) == NULL)
		exit_program(p_gv, EC_ERROR);
	command(p_gv);
}
