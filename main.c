#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    ft_printf("hello world from %x (%d %s)!\n", 0x1337, 0x2A, "Network");

    // Basic tests
    ret1 = ft_printf("Hello, %s!\n", "world");
    ret2 = printf("Hello, %s!\n", "world");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
    
    // Integer tests
    ret1 = ft_printf("Integer: %d, Negative: %i\n", 42, -42);
    ret2 = printf("Integer: %d, Negative: %i\n", 42, -42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
    
    // Hexadecimal tests
    ret1 = ft_printf("Hex: %x, Upper Hex: %X\n", 255, 255);
    ret2 = printf("Hex: %x, Upper Hex: %X\n", 255, 255);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
    
    // Pointer test
    void *ptr = (void *)0x12345678;
    ret1 = ft_printf("Pointer: %p\n", ptr);
    ret2 = printf("Pointer: %p\n", ptr);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
    
    // Unsigned integer test
    ret1 = ft_printf("Unsigned: %u\n", 4294967295);
    ret2 = printf("Unsigned: %u\n", 4294967295);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
    
    // Some Bonus flag tests
    ret1 = ft_printf("Width: %10d | Zero: %010d | Left: %-10d\n", 42, 42, 42);
    ret2 = printf("Width: %10d | Zero: %010d | Left: %-10d\n", 42, 42, 42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);
    
    ret1 = ft_printf("Plus: %+d | Space: % d\n", 42, 42);
    ret2 = printf("Plus: %+d | Space: % d\n", 42, 42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

	ret1 = ft_printf("Plus: %.4d | Space: % d\n", 42, 42);
    ret2 = printf("Plus: %.4d | Space: % d\n", 42, 42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

	ret1 = ft_printf("Plus: %-4s | %.1s\n", "42", "42");
    ret2 = printf("Plus: %-4s | %.1s\n", "42", "42");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    return 0;
}
