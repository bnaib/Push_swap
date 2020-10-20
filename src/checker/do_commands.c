       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

void		do_commands(t_global_variables *p_gv)
{
	t_list_element			*p_element;
	t_command_list_content	*p_content;
	size_t					i;
	int						flags;

	flags = p_gv->flags;
	if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
	{
		p_gv->flags |= GV_FLAGS_PRINT_COMMAND;
		cls(p_gv);
		print_state(p_gv);
	}
	p_element = class_list_get_root(p_gv->p_commands);
	i = -1;
	while (++i < p_gv->p_commands->length)
	{
		p_content = p_element->p_content;
		p_content->command(p_gv);
		p_element = p_element->p_next;
	}
	p_gv->flags = flags;
}
