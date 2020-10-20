       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.08 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "ft_printf.h"

void	ft_fm_uint(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.u;
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_lu(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.lu;
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_llu(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.llu;
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_hu(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.hu;
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}

void	ft_fm_hhu(t_format_list_el *lst)
{
	unsigned long long	param;
	size_t				len;

	param = (unsigned long long)lst->param.hh;
	ft_ltoa(param, lst);
	lst->str_size = ft_strlen(lst->str);
	len = ft_param_len(lst);
	ft_fill_str(lst, len);
}
