#ifndef _UTIL_H_
#define _UTIL_H_

void Print_Int(unsigned long long int input);
int StrCmp(char *input, char* command, int input_length, int command_length);
void reverse(char str[], int length);
char* itoa(unsigned long long int num, char* str, unsigned long long int base);
unsigned long long int atoulli(char* str);

#endif
