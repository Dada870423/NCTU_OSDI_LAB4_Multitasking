#include "../include/util.h"
#include "../include/uart.h"
void Print_Int(unsigned long long int input)
{
    int Flag = 0, i;
    char digit;
    char ar[100];
    //init array
    for(i=0;i<100;i++) ar[i] = '0';
    //put input into array
    i = 99;
    while(input > 0 && i > 0)
    {
        digit = (input % 10) + '0';
        input = input / 10;
        ar[i--] = digit;
    }
    //print
    for(i=0;i<100;i++)
    {
        if(Flag == 0)
        {
            if(ar[i] == '0') continue;
            else
            {
                Flag = 1;
                uart_send(ar[i]);
            }
        }
        else uart_send(ar[i]);
    }
}

int StrCmp(char *input, char* command, int input_length, int command_length)
{
    int i, Equal = 1;
    if(input_length != command_length) return 0;
    for(i=0;i<input_length;i++)
    {
        if(input[i] != command[i]) Equal = 0;
    }
    return Equal;
}

void reverse(char str[], int length) 
{
    int start = 0;
    int end = length -1;
    while (start < end) 
    {
        char tmp  = *(str+start);
        *(str+start) = *(str+end);
        *(str+end) = tmp;
        //swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

char* itoa(unsigned long long int num, char* str, unsigned long long int base) {
    unsigned long long int i = 0;
    _Bool isNegative = 0;

    if (num == 0) 
    {
        str[i] = '0';
        i = i + 1;
        str[i] = '\0';
        return str;
    }
    if (num < 0 && base == 10) 
    {
        isNegative = 1;
        num = -num;
    }
    while (num != 0) 
    {
        unsigned long long int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }
    if (isNegative) str[i++] = '-';

    str[i] = '\0';
    reverse(str, i);
    return str;
}

unsigned long long int atoulli(char* str){
    unsigned long long res = 0; // Initialize result
    for(int i = 0; str[i] != '\0'; ++i) res = res * 10 + str[i] - '0';
    return res;
}
