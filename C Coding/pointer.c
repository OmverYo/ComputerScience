#include <stdio.h>

int main()
{
    // Memory Address

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

    printf("\n------------------------\n\n");

    // Pointers and Arrays

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

    printf("\n------------------------\n\n");

    // Pointer Arithmetic

    int myNumbers1[4] = {10, 20, 30, 40};
    int *p1 = myNumbers1; // Points to myNumbers[0]

    printf("%d\n", *p1);       // Outputs 10
    printf("%d\n", *(p1 + 1)); // Outputs 20
    printf("%d\n", *(p1 + 2)); // Outputs 30
    printf("%d\n", *(p1 + 3)); // Outputs 40

    printf("\n------------------------\n\n");

    // Moving the pointer with increment and decrement operators

    int myNumbers2[3] = {10, 20, 30};
    int *p2 = myNumbers2; // myNumbers[0]

    printf("%d\n", *p2); // 10
    p2++;                // move to myNumbers[1]
    printf("%d\n", *p2); // 20
    p2--;                // back to myNumbers[0]
    printf("%d\n", *p2); // 10
    p2 += 2;             // jump to myNumbers[2]
    printf("%d\n", *p2); // 30

    printf("\n------------------------\n\n");

    // Pointer subtraction

    int myNumbers3[5] = {10, 20, 30, 40, 50};
    int *start = &myNumbers3[1]; // points to 20
    int *end = &myNumbers3[4];   // points to 50

    printf("%ld\n", end - start); // 3 elements apart

    printf("\n------------------------\n\n");

    // Pointer Arithmetic with Different Data Types

    /*
    An int pointer increases by 4 bytes (size of int)
    A char pointer increases by 1 byte (size of char)
    */

    int myNumbers4[2] = {1, 2};
    char letters[] = "Hi"; // 'H', 'i', '\0'

    int *pi = myNumbers4; // int pointer
    char *pc = letters;   // char pointer

    printf("%p\n", (void *)pi);
    printf("%p\n", (void *)(pi + 1)); // moves by sizeof(int) (4 bytes)
    printf("%p\n", (void *)(pi + 2)); // moves by sizeof(int) (4 bytes)

    printf("%p\n", (void *)pc);
    printf("%p\n", (void *)(pc + 1)); // moves by 1 byte

    printf("\n------------------------\n\n");

    // Looping with pointers

    int myNumbers5[4] = {25, 50, 75, 100};
    int *p5 = myNumbers5; // start of array

    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", *p5);
        p5++; // move to next element
    }

    printf("\n------------------------\n\n");

    // Pointer to Pointer
    int myNum = 10;
    int *myNumPtr = &myNum;
    int **myNumPtrPtr = &myNumPtr;

    printf("myNum = %d\n", myNum);
    printf("*myNumPtr = %d\n", *myNumPtr);
    printf("**myNumPtrPtr = %d\n", **myNumPtrPtr);

    **myNumPtrPtr = 20; // change myNum via pointer to pointer
    printf("myNum = %d\n", myNum);

    return 0;
}