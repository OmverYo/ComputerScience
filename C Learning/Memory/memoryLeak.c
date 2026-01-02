#include <stdio.h>
#include <stdlib.h>

/*
메모리 누수 예시:
// 나쁜 예 - 메모리 누수 발생
void bad_example() {
    int *ptr = malloc(100 * sizeof(int));
    // ptr 사용...
    // free를 안 함! -> 메모리 누수
}

// 좋은 예 - 메모리 해제
void good_example() {
    int *ptr = malloc(100 * sizeof(int));
    if (ptr == NULL) return;
    // ptr 사용...
    free(ptr);  // 반드시 해제
    ptr = NULL; // 안전을 위해 NULL 대입
}
*/

int goodMemoryManagementExample()
{
    // 1. 메모리 할당
    int *numbers = malloc(5 * sizeof(int));

    // 2. NULL 체크 (할당 실패 가능성)
    if (numbers == NULL)
    {
        printf("메모리 할당 실패\n");
        return 1;
    }

    // 3. 메모리 사용
    for (int i = 0; i < 5; i++)
    {
        numbers[i] = i * 10;
    }

    // 4. 반드시 해제
    free(numbers);
    numbers = NULL; // 댕글링 포인터 방지

    return 0;
}

// 메모리 누수 패턴 예시 시작

// 패턴 1: 조기 return으로 인한 누수
int process_data(int size)
{
    int *data = malloc(size * sizeof(int));
    if (data == NULL)
        return -1;

    if (size <= 0)
    {
        return -1; // 여기서 return하면 free 못함! 누수 발생
    }

    // 올바른 방법
    if (size <= 0)
    {
        free(data); // return 전에 해제
        return -1;
    }

    // 데이터 처리...
    free(data);
    return 0;
}

// 패턴 2: 반복문에서의 누수
void loop_leak()
{
    for (int i = 0; i < 10; i++)
    {
        int *temp = malloc(100 * sizeof(int));
        // 사용...
        // free를 안 하면 10번 누수!
    }
}

// 올바른 방법
void loop_correct()
{
    for (int i = 0; i < 10; i++)
    {
        int *temp = malloc(100 * sizeof(int));
        if (temp == NULL)
            continue;
        // 사용...
        free(temp); // 반복문 안에서 해제
    }
}

// 패턴 3: 재할당으로 인한 누수
void realloc_leak()
{
    int *ptr = malloc(10 * sizeof(int));
    ptr = malloc(20 * sizeof(int)); // 이전 메모리 주소 잃어버림! 누수!
}

// 올바른 방법
void realloc_correct()
{
    int *ptr = malloc(10 * sizeof(int));
    free(ptr); // 먼저 해제
    ptr = malloc(20 * sizeof(int));
    free(ptr);
}

// 메모리 누수 패턴 예시 끝