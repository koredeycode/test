#include <stdio.h>

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 *
 * Return: string
 */
char *convert(long int num, int base)
{
        static char *array = "0123456789abcdef";
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long n = num;

        if (num < 0)
        {
                n = -num;
                sign = '-';
        }
        ptr = &buffer[49];
        *ptr = '\0';

        do      {
                *--ptr = array[n % base];
                n /= base;
        } while (n != 0);

        if (sign)
                *--ptr = sign;
        return (ptr);
}

int main(void)
{
        int a = 435;
        printf("%s\n", convert(a, 10));
        printf("%s\n", convert(a, 2));
        printf("%s\n", convert(a, 16));
}
