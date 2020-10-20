       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.15 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_class_list *p_list)
{
	p_list->p_element = class_list_get_end(p_list);
}

void		rra(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
		reverse_rotate(p_gv->p_stacks[0]);
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "rra\n", 4);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}

void		rrb(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
		reverse_rotate(p_gv->p_stacks[1]);
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "rrb\n", 4);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}

void		rrr(t_global_variables *p_gv)
{
	if (p_gv->flags & GV_FLAGS_DO_COMMAND)
	{
		reverse_rotate(p_gv->p_stacks[0]);
		reverse_rotate(p_gv->p_stacks[1]);
	}
	if (p_gv->flags & GV_FLAGS_PRINT_COMMAND)
	{
		cls(p_gv);
		write(1, "rrr\n", 4);
		if (p_gv->flags & (GV_FLAGS_PRINT_STATE | GV_FLAGS_PRINT_LINES))
			print_state(p_gv);
	}
}
