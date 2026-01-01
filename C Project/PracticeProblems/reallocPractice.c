#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numbers = malloc(3 * sizeof(int));
    if (numbers == NULL)
        return 1;

    // 1. 값 저장: 5, 10, 15
    numbers[0] = 5;
    numbers[1] = 10;
    numbers[2] = 15;

    // 2. 6개로 확장
    printf("확장 전: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // 2. 6개로 확장
    int *temp = realloc(numbers, 6 * sizeof(int));
    if (temp == NULL)
    {
        free(numbers);
        return 1;
    }
    numbers = temp;

    // 3. 새로운 값 추가: 20, 25, 30
    numbers[3] = 20;
    numbers[4] = 25;
    numbers[5] = 30;

    // 4. 출력
    printf("확장 후: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    free(numbers);
    return 0;
}