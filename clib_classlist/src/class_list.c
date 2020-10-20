       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "class_list.h"

t_class_list					*class_list_construct(
	void *(*copy_list_content)(const void *),
	void (*free_list_content)(void *),
	t_class_list *(*acopy_list_content)(t_class_list *, const t_class_list *))
{
	t_class_list	*p_list;

	if ((p_list = malloc(sizeof(*p_list))) == NULL)
		return (NULL);
	p_list->free_list_content = free_list_content;
	p_list->copy_list_content = copy_list_content;
	p_list->acopy_list_content = acopy_list_content;
	p_list->length = 0;
	p_list->p_element = NULL;
	return (p_list);
}

void							class_list_destruct(
	t_class_list **pp_list)
{
	t_list_element	*p_current;
	t_list_element	*p_next;
	size_t			i;

	p_next = (*pp_list)->p_element;
	i = 0;
	while (i++ < (*pp_list)->length)
	{
		p_current = p_next;
		p_next = p_current->p_next;
		if (p_current->p_content != NULL)
			(*pp_list)->free_list_content(p_current->p_content);
		free(p_current);
	}
	free(*pp_list);
	*pp_list = NULL;
}

t_class_list					*class_list_copy(
	const t_class_list *p_list_from)
{
	t_class_list	*p_list_to;
	t_list_element	*ptr[2];
	size_t			i;

	if (p_list_from == NULL ||
		(p_list_to = class_list_construct(p_list_from->copy_list_content,
			p_list_from->free_list_content,
			p_list_from->acopy_list_content)) == NULL)
		return (NULL);
	if (p_list_from->length == 0)
		return (p_list_to);
	ptr[0] = p_list_from->p_element->p_last;
	i = -1;
	while (++i < p_list_from->length)
	{
		ptr[0] = ptr[0]->p_next;
		if ((ptr[1] = class_list_copy_element(p_list_from, ptr[0])) == NULL)
		{
			class_list_destruct(&p_list_to);
			return (NULL);
		}
		class_list_add_to_end(p_list_to, ptr[1]);
	}
	return ((p_list_to->acopy_list_content == NULL) ? p_list_to :
		p_list_to->acopy_list_content(p_list_to, p_list_from));
}
