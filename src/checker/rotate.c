       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "checker.h"

static void	rotate(t_class_list *p_list)
{
	t_list_element	*p_list_element;

	if (p_list->length < 2)
		return ;
	p_list_element = class_list_get_root(p_list);
	p_list->p_element = p_list_element->p_next;
}

void		ra(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
		rotate(p_gv->p_stacks[0]);
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "ra\n", 3);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}

void		rb(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
		rotate(p_gv->p_stacks[1]);
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "rb\n", 3);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}

void		rr(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
	{
		rotate(p_gv->p_stacks[0]);
		rotate(p_gv->p_stacks[1]);
	}
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "rr\n", 3);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}
