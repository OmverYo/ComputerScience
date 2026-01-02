// test_memory.c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 의도적인 메모리 누수
    int *leak = malloc(100 * sizeof(int));
    // free를 안 함!

    // 정상적인 사용
    int *normal = malloc(50 * sizeof(int));
    free(normal);

    // 이중 해제 (double free)
    int *ptr = malloc(10 * sizeof(int));
    free(ptr);
    // free(ptr);  // 주석 해제하면 에러

    return 0;
}