#include <stdio.h>

// Function Pointer Array
void add(int a, int b) { printf("Result: %d\n", a + b); }
void subtract(int a, int b) { printf("Result: %d\n", a - b); }
void multiply(int a, int b) { printf("Result: %d\n", a * b); }

// Callback function example
void sayHello()
{
    printf("Hello from the callback!\n");
}

void runCallback(void (*callback)())
{
    printf("Before calling the callback...\n");
    callback();
    printf("After calling the callback.\n");
}

int main()
{
    // Function Pointer Array
    int choice, x = 10, y = 5; // choice is only declared and x and y are initialized with values.

    void (*operations[3])(int, int) = {add, subtract, multiply}; // operation is an array of function pointers.

    printf("x = %d, y = %d\n\n", x, y);
    printf("Choose an operation:\n");
    printf("0: Add\n1: Subtract\n2: Multiply\n");
    scanf("%d", &choice);

    if (choice >= 0 && choice < 3)
    {
        operations[choice](x, y);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    printf("\n------------------------\n\n");

    // Callback function example
    runCallback(sayHello);
}