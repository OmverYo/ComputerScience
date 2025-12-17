#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    When a variable is created in C, C will automatically allocate
    a certain amount of memory for that variable based on its data type.
    For example: 'int' variables typically occupy 4 bytes of memory,
    while 'float' variables also occupy 4 bytes,
    'double' variables occupy 8 bytes,
    and 'char' variables occupy 1 byte.

    Use sizeof() to find out the size of difference data types.
    */

    int myInt;
    float myFloat;
    double myDouble;
    char myChar;

    printf("Size of int: %zu bytes\n", sizeof(myInt));       // 4 bytes
    printf("Size of float: %zu bytes\n", sizeof(myFloat));   // 4 bytes
    printf("Size of double: %zu bytes\n", sizeof(myDouble)); // 8 bytes
    printf("Size of char: %zu bytes\n", sizeof(myChar));     // 1 byte

    printf("--------------------------\n");

    /*
    C has two types of memory: Static and Dynamic memory.

    Static Memory:
    Static memory is memory that is reserved for variables 'before' the program runs.
    Allocation of static memory is also known as compile-time memory allocation.
    C automatically allocates memory for every variable when the program is compiled.
    For example, integer array of 20 studenst, C will allocate 20 * 4 = 80 bytes of memory.
    */

    int students[20];
    printf("Size of students array: %zu bytes\n", sizeof(students)); // 80 bytes

    /*
    Story: When the semester starts, it turns out that only 12 students have enrolled in the class.
    So, allocating memory for 20 students is wasteful.
    You are not able to change the size of the arrray.
    The program will still run correctly and it is not damaged in any way.
    But if your program contains a lot of this kind of wasteful memory allocation,
    it can lead to inefficient memory usage and potentially exhaust available memory. (Slower performance)
    */

    /*
    Dynamic Memory:
    Dynamic memory is memory that is allocated 'after' the program starts running.
    Allocation of dynamic memory is also known as run-time memory allocation.
    Unlike static memory, you have full control over dynamic memory allocation in C.
    You can determine how much memory to allocate and when to allocate or free it.
    To allocate dynamic memory, you can use functions like malloc(), calloc(), realloc() from the stdlib.h library.
    The malloc() and calloc() functions allocate some memory and return a pointer to its address.
    */

    // int *prt1 = malloc(size);
    // int *ptr2 = calloc(amount, size);

    /*
    The malloc() function has one parameter, size, which specifies how much memory to allocate, measured in bytes.
    The calloc() function has two parameters:
    amount - Specifies the amount of items to allocate
    size - Specifies the size of each item measured in bytes

    The data in the memory allocated by malloc() is not unpredictable. Make sure to write something into the memory before reading it.
    Unlike malloc(), the calloc() function writes zeroes into all of the allocated memory. However, this makes calloc() slightly less efficient.
    */

    printf("--------------------------\n");

    int *ptr1, *ptr2;
    ptr1 = malloc(sizeof(*ptr1));
    ptr2 = calloc(1, sizeof(*ptr2));
    printf("Size allocated by malloc: %zu bytes\n", sizeof(*ptr1)); // 4 bytes
    printf("Size allocated by calloc: %zu bytes\n", sizeof(*ptr2)); // 4 bytes

    int *myStudents;
    int numStudents = 12;
    myStudents = calloc(numStudents, sizeof(*myStudents));
    printf("%d", numStudents * sizeof(*myStudents)); // 48 bytes

    return 0;
}