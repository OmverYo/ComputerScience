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

    int myNumbers[4] = {10, 20, 30, 40};
    int i;

    for (i = 0; i < 4; i++)
    {
        printf("%p\n", &myNumbers[i]); // Outputs the memory addresses of each element
    }

    int myInt;
    printf("Size of myInt: %zu bytes\n", sizeof(myInt));   // Outputs size of int (typically 4 bytes)
    printf("Size of myNumbers: %zu\n", sizeof(myNumbers)); // Outputs size of the entire array (16 bytes for 4 ints)
    printf("%p\n", myNumbers);                             // Outputs the memory address of the array (same as &myNumbers[0])
    printf("%p\n", &myNumbers[0]);                         // Outputs the memory address of the first element
    printf("%d\n", *myNumbers);                            // Outputs the value of the first element (10)
    printf("%d\n", *(myNumbers + 1));                      // Outputs the value of the second element (20)
    printf("%d\n", *(myNumbers + 2));                      // Outputs the value of the third element (30)
    printf("%d\n", *(myNumbers + 3));                      // Outputs the value of the fourth element (40)

    int *pointer = myNumbers;
    for (i = 0; i < 4; i++)
    {
        printf("%d\n", *(pointer + i)); // Outputs each element of the array using pointer arithmetic
    }

    *myNumbers = 13;
    *(myNumbers + 1) = 17;
    printf("%d\n", *myNumbers);       // Outputs 13
    printf("%d\n", *(myNumbers + 1)); // Outputs 17

    return 0;
}