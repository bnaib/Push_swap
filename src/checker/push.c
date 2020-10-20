       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

static void	push(t_class_list *p_list_from, t_class_list *p_list_to)
{
	t_list_element	*p_list_element;

	if (p_list_from->length < 1)
		return ;
	p_list_element = class_list_cut_root(p_list_from);
	class_list_add_to_start(p_list_to, p_list_element);
}

void		pa(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
		push(p_gv->p_stacks[1], p_gv->p_stacks[0]);
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "pa\n", 3);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}

void		pb(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
		push(p_gv->p_stacks[0], p_gv->p_stacks[1]);
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "pb\n", 3);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}
