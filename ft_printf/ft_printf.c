       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.02 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

static size_t		ft_printf_check_percent(
					const char *format_n,
					va_list *p_args,
					va_list *p_args_root,
					t_format_list_el **plst)
{
	size_t				i[3];

	ft_fm_list_add_el(plst);
	i[0] = 0;
	i[1] = 1;
	while (i[1] > 0)
	{
		i[1] = 0;
		i[1] += ft_printf_get_flags(&(format_n[i[0] + i[1]]), *plst);
		i[1] += ft_printf_get_dollar(&(format_n[i[0] + i[1]]), *plst);
		i[1] += ft_printf_get_width(&(format_n[i[0] + i[1]]),
					p_args, p_args_root, *plst);
		i[1] += ft_printf_get_accuracy(&(format_n[i[0] + i[1]]),
					p_args, p_args_root, *plst);
		i[0] += i[1] += ft_printf_get_prefix(&(format_n[i[0] + i[1]]), *plst);
	}
	if ((i[2] = ft_printf_get_type(&(format_n[i[0]]),
					p_args, p_args_root, *plst)) == 0)
	{
		ft_fm_list_del_first_el(plst);
		return (i[0]);
	}
	ft_check_flags(*plst);
	ft_printf_set_str_from_rapam(*plst);
	return (i[0] + i[2]);
}

static void			ft_printf_check_text(
					const char *format,
					size_t *i,
					t_format_list_el **p_fm_list)
{
	size_t				buf_i;

	if (format[*i] == '\0' || format[*i] == '%')
		return ;
	ft_fm_list_add_el(p_fm_list);
	(*p_fm_list)->str_size = 0;
	while (format[*i + (*p_fm_list)->str_size] != '\0'
			&& format[*i + (*p_fm_list)->str_size] != '%')
		(*p_fm_list)->str_size++;
	if (((*p_fm_list)->str = malloc(sizeof(*((*p_fm_list)->str))
			* (*p_fm_list)->str_size)) == NULL)
		ft_printf_exit(p_fm_list);
	buf_i = 0;
	while (format[*i] != '\0' && format[*i] != '%')
	{
		(*p_fm_list)->str[buf_i] = format[*i];
		buf_i++;
		(*i)++;
	}
}

static size_t		ft_printf_get_result_size(t_format_list_el **fm_list)
{
	size_t	size;

	size = 0;
	while (*fm_list != NULL && (*fm_list)->next != NULL)
	{
		size += (*fm_list)->str_size;
		*fm_list = (*fm_list)->next;
	}
	if (*fm_list != NULL)
		size += (*fm_list)->str_size;
	return (size);
}

static size_t		ft_printf_print_result_3(t_format_list_el *fm_list)
{
	size_t	size;
	size_t	i[2];
	char	*str;

	size = ft_printf_get_result_size(&fm_list);
	if ((str = malloc(size)) == NULL)
		ft_printf_exit(&fm_list);
	i[0] = 0;
	while (fm_list != NULL)
	{
		i[1] = -1;
		while (++i[1] < fm_list->str_size)
			ft_printf_check_color(str, fm_list->str[i[1]], i);
		fm_list = fm_list->last;
	}
	write(1, str, i[0]);
	free(str);
	return (size);
}

int					ft_printf(const char *format, ...)
{
	size_t				i;
	va_list				args[2];
	t_format_list_el	*fm_list;
	size_t				size;

	fm_list = NULL;
	va_start(args[0], format);
	va_copy(args[1], args[0]);
	i = 0;
	while (format[i] != '\0')
	{
		ft_printf_check_text(format, &i, &fm_list);
		if (format[i] == '%')
			i += 1 + ft_printf_check_percent(&(format[i + 1]),
						&(args[0]), &(args[1]), &fm_list);
	}
	va_end(args[1]);
	va_end(args[0]);
	size = ft_printf_print_result_3(fm_list);
	ft_fm_list_free(&fm_list);
	return ((int)size);
}
