       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.09.19 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __CLASS_LIST_H
# define __CLASS_LIST_H

# include <stdlib.h>

typedef enum					e_type_sort
{
	ASC,
	DESC
}								t_type_sort;

typedef struct					s_list_element
{
	void						*p_content;
	struct s_list_element		*p_last;
	struct s_list_element		*p_next;
}								t_list_element;

typedef struct					s_class_list
{
	void						(*free_list_content)(void *);
	void						*(*copy_list_content)(const void *);
	struct s_class_list			*(*acopy_list_content)(
								struct s_class_list *,
								const struct s_class_list *);
	size_t						length;
	t_list_element				*p_element;
}								t_class_list;

t_class_list					*class_list_construct(
	void *(*copy_list_content)(const void *),
	void (*free_list_content)(void *),
	t_class_list *(*acopy_list_content)(t_class_list *, const t_class_list *));
void							class_list_destruct(
	t_class_list **pp_list);
t_class_list					*class_list_copy(
	const t_class_list *p_list_from);

void							class_list_add_to_end(
	t_class_list *p_list,
	t_list_element *p_element);
void							class_list_add_to_start(
	t_class_list *p_list,
	t_list_element *p_element);

t_list_element					*class_list_create_element(
	const t_class_list *p_list,
	const void *p_content);
t_list_element					*class_list_create_element_to_end(
	t_class_list *p_list,
	const void *p_content);
t_list_element					*class_list_create_element_to_start(
	t_class_list *p_list,
	const void *p_content);

t_list_element					*class_list_get_root(
	const t_class_list *p_list);
t_list_element					*class_list_get_end(
	const t_class_list *p_list);
t_list_element					*class_list_get_element_from_start_index(
	const t_class_list *p_list,
	size_t index);
t_list_element					*class_list_get_element_from_end_index(
	const t_class_list *p_list,
	size_t index);

void							class_list_cut_element(
	t_class_list *p_list,
	t_list_element *p_element);
t_list_element					*class_list_cut_root(
	t_class_list *p_list);
t_list_element					*class_list_cut_end(
	t_class_list *p_list);
t_list_element					*class_list_cut_element_from_start_index(
	t_class_list *p_list,
	size_t index);
t_list_element					*class_list_cut_element_from_end_index(
	t_class_list *p_list,
	size_t index);

void							class_list_del_element(
	t_class_list *p_list,
	t_list_element **pp_element);
void							class_list_del_root(
	t_class_list *p_list);
void							class_list_del_end(
	t_class_list *p_list);
void							class_list_del_element_from_start_index(
	t_class_list *p_list,
	size_t index);
void							class_list_del_element_from_end_index(
	t_class_list *p_list,
	size_t index);

t_list_element					*class_list_copy_element(
	const t_class_list *p_list,
	t_list_element *p_element);
t_list_element					*class_list_copy_root(
	const t_class_list *p_list);
t_list_element					*class_list_copy_end(
	const t_class_list *p_list);
t_list_element					*class_list_copy_element_from_start_index(
	const t_class_list *p_list,
	size_t index);
t_list_element					*class_list_copy_element_from_end_index(
	const t_class_list *p_list,
	size_t index);

void							lass_list_sort(
	t_class_list *p_list,
	int	(*list_elements_cmp)(t_list_element *, t_list_element *),
	t_type_sort type_sort);

#endif
