#include "ft_printf.h"
#include <libc.h>

int main()
{

     int i, j;
     int k = 255;
     unsigned int l = 10;
//     int k;
//     char *str = "";
// j =  ft_printf("mine:%p\n", (void *)-14523);
//     i = printf("orig:%p\n", (void *)-14523);

     char c = 'a';
     int max = 2147483647;
     int min = -2147483648;
     char *s = "hello";
//cspdiuxX%
//   j = printf("%-200\n",s); worked 
//   j = printf("%maxs\n",s); returned -1
//   j = printf("%c\n",s); returned -1 (TODO)
//   j = printf("og:% 3 1 b\n"); (b)
//   j = printf("og:% 0 -2 ba\n"); (0b a)


//i = printf("\nft:% 214"); ????????
   //j = printf("\nog:% 21

i= ft_printf("\001\002\007\v\010\f\r\n");


j= printf("\001\002\007\v\010\f\r\n");
     //j = printf("%-16s", "nark nark");


    printf("\nft_printf:%d|printf:%d\n", i, j);
}
