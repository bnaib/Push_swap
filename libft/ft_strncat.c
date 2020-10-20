       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.07 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		i2;

	if (n)
	{
		i = ft_strlen(s1);
		i2 = ft_strlen(s2);
		if (n > i2)
		{
			ft_strncpy(s1 + i, s2, i2);
			*(s1 + i + i2) = '\0';
		}
		else
		{
			ft_strncpy(s1 + i, s2, n);
			*(s1 + i + n) = '\0';
		}
	}
	return (s1);
}
