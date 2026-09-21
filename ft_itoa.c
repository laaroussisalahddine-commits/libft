#include"libft.h"

char    *ft_itoa(int n)
{
    size_t count_sign;
    size_t count_number;
    size_t total_number;

    long temp;
    char *fresh;

    count_number = 0;
    count_sign = 0;
    temp = n;
    if(temp < 0)
    {
        temp = -temp;
        count_sign++;
    }
    while(temp >= 10)
    {
        temp = temp / 10;
        count_number++;
    }
    count_number++;
  
    total_number = count_number + count_sign;
    fresh = ft_strnew(total_number);
    if (!fresh)
    return (NULL);
    
    temp = n;
    if (temp < 0)
        temp = -temp;
    while(total_number > 0)
    {
        fresh[total_number - 1] = (temp % 10) + '0';
        temp = temp / 10;
        total_number--;
    }
    if(count_sign == 1)
        fresh[total_number] = '-';
    return(fresh);
    
}
