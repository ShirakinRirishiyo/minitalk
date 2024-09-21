/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dediaz-f <dediaz-f@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:05:40 by dediaz-f          #+#    #+#             */
/*   Updated: 2024/03/09 19:05:40 by dediaz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int main () {
   char str1[50];
   char str2[50];
   __int64 ret;

   strcpy(str1, "Estamos preparados");
   strcpy(str2, "Estamos parados");

   ret = strncmp(str1, str2, 6);

   if(ret < 0) {
      printf("str1 is less than str2");
   } else if(ret > 0) {
      printf("str2 is less than str1");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char)s2[i];
		if (uc1 != uc2)
		{
			if (uc1 > uc2)
				return (1);
			else if (uc1 < uc2)
				return (-1);
			else
			{
				return (0);
			}
		}
		i++;
	}
	return (0);
}
