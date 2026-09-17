#include"libft.h"

int ft_atoi(const char *str)
{
    int i;
    int sign;
    int final_number;

    i = 0;
    while((str[i] >= 9 && str[i] <= 13 ) || str[i] == 32)
        i++;

    sign = 1;
    if (str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }

    final_number = 0;
    while(str[i] >= '0' && str[i] <= '9')
    {
        final_number = final_number * 10 + (str[i] - '0');
        i++;
    }

    return(final_number * sign);
}