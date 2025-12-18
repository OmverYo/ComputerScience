#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 핵심 개념:
    // 할당된 메모리는 포인터를 통해 접근

    // 방법 1: 포인터 역참조 (*)
    int *ptr = malloc(sizeof(int));
    *ptr = 100;           // 값 저장
    printf("%d\n", *ptr); // 값 읽기: 100
    free(ptr);

    printf("--------------------\n");

    // 방법 2: 배열처럼 접근 ([])
    int *arr = malloc(5 * sizeof(int));

    // 이 두 가지는 같은 의미:
    arr[0] = 10;     // 배열 방식
    *(arr + 0) = 10; // 포인터 방식

    arr[1] = 20;
    *(arr + 1) = 20;
    free(arr);

    printf("--------------------\n");

    // 실전 예시:
    // 5개 정수 배열 할당
    int *numbers = malloc(5 * sizeof(int));

    if (numbers == NULL)
        return 1;

    // 방법 1: 배열처럼 접근
    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;

    // 방법 2: 포인터 연산으로 접근
    *(numbers + 3) = 40;
    *(numbers + 4) = 50;

    // 어차피 같은 메모리 공간이므로 둘 다 가능

    // 읽기
    for (int i = 0; i < 5; i++)
    {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    free(numbers);

    printf("--------------------\n");

    /*
    메모리 구조 시각화:
    malloc(5 * sizeof(int)) 실행 후:

    메모리 주소:  0x1000   0x1004   0x1008   0x100C   0x1010
    값:          [  ?   ] [  ?   ] [  ?   ] [  ?   ] [  ?   ]
    인덱스:        [0]      [1]      [2]      [3]      [4]

    numbers → 0x1000 (첫 번째 요소의 주소)

    numbers[0]     = *(numbers + 0) = 0x1000의 값
    numbers[1]     = *(numbers + 1) = 0x1004의 값
    numbers[2]     = *(numbers + 2) = 0x1008의 값
    */

    // 연습 문제:

    // 1. 학생 3명의 점수 배열 만들기
    int *scores = calloc(3, sizeof(int));

    // 2. NULL 체크
    if (scores == NULL)
    {
        return 1;
    }

    // 3. 점수 입력
    scores[0] = 85;
    scores[1] = 90;
    scores[2] = 78;

    // 4. 평균 계산
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += scores[i];
    }
    printf("평균: %.2f\n", sum / 3.0);

    // 5. 메모리 해제
    free(scores);
    return 0;
}