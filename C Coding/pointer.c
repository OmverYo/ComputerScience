#include <stdio.h>

int main()
{
    int myAge = 26;
    printf("%d\n", myAge);  // Outputs 26
    printf("%p\n", &myAge); // Outputs 00000000005FFE7C

    int *ptr = &myAge;
    printf("%p\n", ptr); // Outputs 00000000005FFE7C

    /*
    Explanation: When a variable is created in C,
    a memory address is assigned to the variable.
    The memory address is the location of where the variable is stored on the computer.
    To access it, use the reference operator (&).
    To print pointer values, we use the %p format specifier in printf.

    Two ways to declare a pointer:
    int* myNum;
    int *myNum;
    */

    return 0;
}