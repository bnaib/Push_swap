       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.04 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */
#include "ft_printf.h"

void	ft_fm_int(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.i;
	if (lst->param.i < 0)
	{
		lst->sign = 1;
		param *= -1;
	}
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_ld(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.ld;
	if (lst->param.ld < 0)
	{
		lst->sign = 1;
		param *= -1;
	}
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_lld(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.lld;
	if (lst->param.lld < 0)
	{
		lst->sign = 1;
		param *= -1;
	}
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_hd(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.hd;
	if (lst->param.hd < 0)
	{
		lst->sign = 1;
		param *= -1;
	}
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_hhd(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.c;
	if (lst->param.c < 0)
	{
		lst->sign = 1;
		param *= -1;
	}
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}
