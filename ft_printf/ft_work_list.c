       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.03 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

void			ft_fm_list_free(t_format_list_el **p_fm_list)
{
	t_format_list_el *ptr[2];

	ptr[0] = *p_fm_list;
	while (ptr[0] != NULL)
	{
		ptr[1] = ptr[0]->next;
		if (ptr[0]->str != NULL)
			free(ptr[0]->str);
		free(ptr[0]);
		ptr[0] = ptr[1];
	}
	*p_fm_list = NULL;
}

static void		ft_set_default_fm_list(t_format_list_el **p_fm_list)
{
	(*p_fm_list)->last = NULL;
	(*p_fm_list)->sign = 0;
	(*p_fm_list)->str = NULL;
	(*p_fm_list)->modifiers.type[0] = 0;
	(*p_fm_list)->modifiers.prefix = 0;
	(*p_fm_list)->modifiers.flags = 0;
	(*p_fm_list)->modifiers.width = 0;
	(*p_fm_list)->modifiers.accuracy = 0;
}

void			ft_fm_list_add_el(t_format_list_el **p_fm_list)
{
	t_format_list_el *ptr;

	if (*p_fm_list == NULL)
	{
		if ((*p_fm_list = malloc(sizeof(**p_fm_list))) == NULL)
			exit(0);
		(*p_fm_list)->next = NULL;
	}
	else
	{
		if ((ptr = malloc(sizeof(*ptr))) == NULL)
		{
			ft_fm_list_free(p_fm_list);
			exit(0);
		}
		ptr->next = *p_fm_list;
		(*p_fm_list)->last = ptr;
		*p_fm_list = ptr;
	}
	ft_set_default_fm_list(p_fm_list);
}

void			ft_fm_list_del_first_el(t_format_list_el **p_fm_list)
{
	t_format_list_el *ptr;

	ptr = (*p_fm_list)->next;
	if ((*p_fm_list)->str != NULL)
		free((*p_fm_list)->str);
	free(*p_fm_list);
	*p_fm_list = ptr;
}
