#include <stdio.h>

// A function pointer is a normal pointer but instead of pointing to a data value,
// it points to a function in memory.

// This is simple function pointer exmaple:
int add(int a, int b)
{
    return a + b;
}

// Passing a Function as an Argument
void greetMorning() { printf("Good morning!\n"); }
void greetEvening() { printf("Good evening!\n"); }

void greet(void (*func)())
{
    func();
}

int main()
{
    // Function Pointer
    int (*ptr)(int, int) = add; // ptr is a pointer to the function add().
    int result = ptr(5, 3);     // prt(5, 3) calls the function using the pointer.
    printf("Result: %d\n", result);

    printf("\n------------------------\n\n");

    // Passing a Function as an Argument
    greet(greetMorning);
    greet(greetEvening);

    return 0;
}