       /* ****************************************************************** */
      /*                                             _____ _   __           */
     /*    By: Sergey Nikolaev                      / ___// | / /          */
    /*    Сontacts: sn.prog@yandex.ru               \__ \/  |/ /          */
   /*    Created: 2019.09.09 (YYYY.MM.DD)          ___/ / /|  /          */
  /*    Updated: 2020.10.21 (YYYY.MM.DD)          /____/_/ |_/          */
 /*                                                                    */
/* ****************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_itoa(int n)
{
	int		i;
	char	*str;
	char	minus;

	minus = n < 0;
	i = ft_itoalen(n);
	str = malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (i)
	{
		i--;
		if (minus)
			str[i] = n % 10 * -1 + '0';
		else
			str[i] = n % 10 + '0';
		n /= 10;
	}
	if (minus)
		str[0] = '-';
	return (str);
}
