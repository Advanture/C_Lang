#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char is_digit(char digit)
{
    return (digit >= '0' && digit <= '9');
}

//1) Реализуйте функцию, которая принимает параметром строку и возвращает количество цифр в этой строке.
//int count_digits(char* s)
size_t count_digits(char* message)
{
    size_t counter = 0;
    size_t len = strlen(message);
    size_t i;
    for (i = 0; i < len; ++i)
    {
        if (is_digit(message[i]))
        {
            counter++;
        }
    }
    return counter;
}

//2) Реализуйте функцию, которая принимает параметром строку и символ и возвращает адрес первого вхождения этого символа в строку.
//char* str_chr(char* s, char c)
char* str_chr(char* message, char symbol)
{
    size_t len = strlen(message);
    size_t i;
    for (i = 0; i < len; ++i)
    {
        if (message[i] == symbol)
        {
            return &message[i];
        }
    }
}

//3) Реализовать функцию int fatoi(const char* str) для приведения(конвертации) строки в числовой вид.
int fatoi(const char* message)
{
    size_t i;
    size_t len = strlen(message);
    int result = 0;
    for (i = 0; i < len; ++i)
    {
        if (is_digit(message[i]))
        {
            result *= 10;
            result += message[i] - 48; // ну тут я вообще молчу
        }
    }

    return result;
}

int main()
{
    char message[256] = "Hello, my Name is Nikita123!";
    printf("%d\n", count_digits(message));
    printf("%p\n", str_chr(message, 'm'));
    printf("%d\n", fatoi(message));
    return 0;
}