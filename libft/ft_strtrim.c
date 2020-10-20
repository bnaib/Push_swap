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

char	*ft_strtrim(char const *s)
{
	char	*str;
	char	*res;
	size_t	len;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	len = ft_strlen(str);
	while (len
		&& (str[len - 1] == ' '
			|| (str[len - 1] >= '\t' && str[len - 1] <= '\r')))
		len--;
	res = malloc(sizeof(*str) * (len + 1));
	if (!res)
		return (NULL);
	ft_strncpy(res, str, len);
	res[len] = 0;
	return (res);
}
