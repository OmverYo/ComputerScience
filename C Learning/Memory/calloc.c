#include <stdio.h>
#include <stdlib.h>

int main()
{
    // malloc vs calloc 예제
    // malloc: 쓰레기 값 (초기화 안 됨)
    int *arr1 = malloc(5 * sizeof(int));
    // arr1 = [쓰레기, 쓰레기, 쓰레기, 쓰레기, 쓰레기]

    // calloc: 모두 0으로 초기화됨
    int *arr2 = calloc(5, sizeof(int));
    // arr2 = [0, 0, 0, 0, 0]

    // 문법:
    // 포인터 = calloc(개수, 각_요소_크기);

    // 학생 10명의 점수 배열 (모두 0으로 초기화)
    int *scores = calloc(10, sizeof(int));

    if (scores == NULL)
    {
        printf("할당 실패!\n");
        return 1;
    }

    // 이미 0으로 초기화되어 있음!
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", scores[i]); // 0 0 0 0 0 0 0 0 0 0
    }

    free(scores);

    return 0;
}