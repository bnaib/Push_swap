       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

void	ft_fill_octothorpe(t_format_list_el *lst, char *s, size_t *n)
{
	if (lst->param.u != 0 || lst->modifiers.type[0] == 'p')
	{
		if (lst->modifiers.type[0] == 'o')
			s[(*n)++] = '0';
		else if (lst->modifiers.type[0] == 'x' ||
				lst->modifiers.type[0] == 'p')
		{
			s[(*n)++] = '0';
			s[(*n)++] = 'x';
		}
		else if (lst->modifiers.type[0] == 'X')
		{
			s[(*n)++] = '0';
			s[(*n)++] = 'X';
		}
		else if (lst->modifiers.type[0] == 'b')
		{
			s[(*n)++] = '0';
			s[(*n)++] = 'b';
		}
	}
}

void	ft_fill_zero(char *s, size_t *n, int len)
{
	while (len--)
		s[(*n)++] = '0';
}

void	ft_fill_space(t_format_list_el *lst, char *s, size_t *n, int len)
{
	while (len--)
		s[(*n)++] = ' ';
	if (!(lst->modifiers.flags & FM_FLAG_MINUS) &&
			((lst->modifiers.flags & FM_FLAG_PLUS) || lst->sign ||
			lst->modifiers.flags & FM_FLAG_OCTOTHORPE))
	{
		if (((lst->modifiers.type[0] == 'x' || lst->modifiers.type[0] == 'X' ||
			lst->modifiers.type[0] == 'b') && lst->param.u != 0) ||
			lst->modifiers.type[0] == 'p')
			(*n)--;
		if (!(lst->param.u == 0 && (lst->modifiers.type[0] == 'o' ||
			lst->modifiers.type[0] == 'x' || lst->modifiers.type[0] == 'X' ||
			lst->modifiers.type[0] == 'b')))
			(*n)--;
		ft_check_sign(lst, s, n);
	}
}

void	ft_fill_param(t_format_list_el *lst, char *s, size_t *n)
{
	size_t i;

	i = 0;
	while (i < lst->str_size)
		s[(*n)++] = lst->str[i++];
}

char	*ft_fill_str(t_format_list_el *lst, size_t len)
{
	char		*tmp;
	size_t		i;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * len + 1)))
		ft_printf_exit(&lst);
	if ((lst->str_size < (size_t)lst->modifiers.accuracy) &&
		lst->modifiers.type[0] == 'o')
		lst->modifiers.flags &= ~(int)FM_FLAG_OCTOTHORPE;
	if ((size_t)lst->modifiers.width > lst->str_size
		&& lst->modifiers.width > lst->modifiers.accuracy)
		ft_check_minus(lst, tmp, &i);
	else
	{
		ft_check_sign(lst, tmp, &i);
		ft_check_accuracy(lst, tmp, &i);
		ft_fill_param(lst, tmp, &i);
	}
	tmp[i] = '\0';
	lst->str_size = i;
	free(lst->str);
	lst->str = tmp;
	return (lst->str);
}
