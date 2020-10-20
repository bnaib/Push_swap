       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.10 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static void	ft_fill_s(t_format_list_el *lst)
{
	size_t		i;
	char		*str_null;

	i = 0;
	str_null = "(null)";
	if (lst->param.s == NULL)
	{
		while (i < lst->str_size)
		{
			lst->str[i] = str_null[i];
			i++;
		}
	}
	else
	{
		while (i < lst->str_size)
		{
			lst->str[i] = lst->param.s[i];
			i++;
		}
	}
	lst->str[i] = '\0';
}

void		ft_check_str(t_format_list_el *lst)
{
	if (lst->param.s == NULL)
		lst->str_size = 6;
	else
		lst->str_size = ft_strlen(lst->param.s);
	if ((lst->modifiers.flags & FM_FLAG_ACCURACY) &&
		((size_t)lst->modifiers.accuracy < lst->str_size))
		lst->str_size = lst->modifiers.accuracy;
	lst->modifiers.flags &= ~(int)FM_FLAG_ACCURACY;
	lst->modifiers.accuracy = 0;
	if (!(lst->str = (char *)malloc(sizeof(char) * (lst->str_size + 1))))
	{
		ft_fm_list_free(&lst);
		exit(0);
	}
	ft_fill_s(lst);
}
