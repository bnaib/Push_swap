       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.08 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

void	ft_fm_percent(t_format_list_el *lst)
{
	size_t	len;

	lst->str_size = 1;
	if ((lst->str = malloc(sizeof(*(lst->str)) * 2)) == NULL)
	{
		ft_fm_list_free(&lst);
		exit(0);
	}
	lst->str[0] = '%';
	lst->str[1] = '\0';
	len = (lst->str_size < (size_t)lst->modifiers.width)
		? (size_t)lst->modifiers.width : lst->str_size;
	ft_fill_str(lst, len);
}

void	ft_fm_char(t_format_list_el *lst)
{
	size_t	len;

	lst->str_size = 1;
	if ((lst->str = malloc(sizeof(*(lst->str)) * 2)) == NULL)
	{
		ft_fm_list_free(&lst);
		exit(0);
	}
	lst->str[0] = lst->param.c;
	lst->str[1] = '\0';
	len = (lst->str_size < (size_t)lst->modifiers.width)
		? (size_t)lst->modifiers.width : lst->str_size;
	ft_fill_str(lst, len);
}

void	ft_fm_wchar(t_format_list_el *lst)
{
	size_t	len;

	lst->str_size = convert_utf32_to_utf8(lst->param.lc, &lst->str);
	len = (lst->str_size < (size_t)lst->modifiers.width)
		? (size_t)lst->modifiers.width : lst->str_size;
	ft_fill_str(lst, len);
}

void	ft_fm_wstr(t_format_list_el *lst)
{
	size_t	len;

	lst->str_size = calculate_wstrlen(lst->param.ls, lst->modifiers.accuracy,
					lst->modifiers.flags & FM_FLAG_ACCURACY);
	lst->modifiers.flags &= ~(int)FM_FLAG_ACCURACY;
	lst->modifiers.accuracy = 0;
	if (!(lst->str = (char *)malloc(sizeof(char) * (lst->str_size + 1))))
	{
		ft_fm_list_free(&lst);
		exit(0);
	}
	convert_utf32_to_utf8_str(lst);
	lst->str[lst->str_size] = '\0';
	len = (lst->str_size < (size_t)lst->modifiers.width)
		? (size_t)lst->modifiers.width : lst->str_size;
	ft_fill_str(lst, len);
}

void	ft_fm_str(t_format_list_el *lst)
{
	size_t	len;

	ft_check_str(lst);
	len = (lst->str_size < (size_t)lst->modifiers.width)
		? (size_t)lst->modifiers.width : lst->str_size;
	ft_fill_str(lst, len);
}
