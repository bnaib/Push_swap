       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2020.01.16 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#ifndef __FT_ADVLONGD_H
# define __FT_ADVLONGD_H

# include "ft_printf.h"

/*
** ADVLD_INT_PART - count elements of integer part in array t_advld.val
** ADVLD_INT_PART_LAST_ID - last id for integer part in array t_advld.val
** 							= ADVLD_INT_PART - 1;
** ADVLD_FRACT_PART - count elements of fractional part in array t_advld.val
**						(VALUE NOT USED - only for info)
** ADVLD_ALL_PART - count elements in array t_advld.val
**						= ADVLD_INT_PART + ADVLD_FRACT_PART;
** Integer part:
** t_advld.val[0] ... t_advld.val[ADVLD_INT_PART_LAST_ID]
** Fractional part:
** t_advld.val[ADVLD_INT_PART] ... t_advld.val[ADVLD_ALL_PART - 1]
**
** For long double:
** t_advld.val[0] ... t_advld.val[548] t_advld.val[549] ... t_advld.val[2376]
**
** Example 1
** number = 999999999;
** t_advld.start_el_id = 548;
** t_advld.end_el_id = 548;
** [0] = 0 ... [547] = 0 [548] = 999999999 [549] = 0 ... [2376] = 0
**
** Example 2
** number = 000000000012345000000000123450000.6789000000067890000000000000000;
** t_advld.start_el_id = 546;
** t_advld.end_el_id = 550;
** [0] = 0 ... [545] = 0
** [546] = 123450
** [547] = 1
** [548] = 23450000
** [549] = 678900000
** [550] = 6789000
** [551] = 0 ... [2376] = 0
*/

# define ADVLD_INT_PART 549
# define ADVLD_INT_PART_LAST_ID 548
# define ADVLD_FRACT_PART 1828
# define ADVLD_ALL_PART 2377

typedef struct					s_advld
{
	int							start_el_id;
	int							end_el_id;
	int							*val;
}								t_advld;

void							ft_advld_set_one_int(t_advld *p_advld, int i);
void							ft_advld_mult_two(t_advld *p_advld);
void							ft_advld_div_two(t_advld *p_advld);
void							ft_advld_get_two_in_degree(
									t_advld *p_advld,
									int degree);
void							ft_advld_add(
									t_advld *p_advld_from,
									t_advld *p_advld_to);
int								ft_advld_malloc_val(t_advld *advld_2arr);
void							ft_advld_free_val(t_advld *advld_2arr);
void							ft_advld_get_from_longdouble(
									long double ld,
									t_advld *advld_2arr);
void							ft_advld_set_itoa(
									char **str,
									int val,
									size_t *st,
									char first_el);
void							ft_advld_get_str(t_format_list_el *fm_list);
char							ft_advld_check_infnan(
									t_format_list_el *fm_list);
void							ft_advlongd_round(
									t_format_list_el *fm_list,
									t_advld *advld_2arr);

#endif
