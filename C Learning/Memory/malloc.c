#include <stdio.h>
#include <stdlib.h>

/*
메모리 관리 전체 개념
컴퓨터 메모리를 아파트 건물이라고 생각해보자.
스택(Stack) : 자동으로 관리되는 임대 아파트 (함수가 끝나면 자동 반환)
힙(Heap) : 직접 관리해야 하는 분양 아파트 (우리가 직업 할당/해제)
*/

int main()
{
    // 기본 메모리 사용법
    int x = 5; // 스택: 함수 끝나면 자동 사라짐

    int *ptr = malloc(sizeof(int)); // 힙: 우리가 직접 관리해야 함!
    *ptr = 10;
    free(ptr); // 직접 반환해야 함!

    printf("--------------------\n");

    // malloc - 메모리 할당 (방 빌리기), malloc은 Memory Allocation의 줄임말, 힙 메모리에 공간을 빌리는 함수
    // free - 메모리 해제 (방 반납하기)
    // 빌렸으면 반납하라고!

    // 문법:
    // 포인터 = malloc(바이트_크기);

    // 예시 1: 정수 하나 저장
    // 1. int 하나를 저장할 공간 요청
    int *ptr1 = malloc(sizeof(int)); // 4바이트 할당

    // 2. 할당 성공 여부 확인 (중요!)
    if (ptr1 == NULL)
    {
        printf("메모리 할당 실패!\n");
        return 1;
    }

    // 3. 값 저장
    *ptr1 = 42;

    // 4. 값 사용
    printf("값: %d\n", *ptr1); // 42

    // 5. 메모리 반환 (필수!)
    free(ptr1);

    printf("--------------------\n");

    // 예시 2: 배열 만들기
    int size = 5;

    // int 5개짜리 배열 공간 할당
    int *arr = malloc(size * sizeof(int)); // 20바이트

    if (arr == NULL)
    {
        printf("할당 실패!\n");
        return 1;
    }

    // 배열처럼 사용
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 10; // 0, 10, 20, 30, 40
    }

    // 출력
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    free(arr); // 반환!

    return 0;

    /*
    malloc의 특징:
    초기화 안 됨: 쓰레기 값이 들어있을 수 있음
    void 반환*: 어떤 타입으로든 변환 가능
    실패 시 NULL 반환: 항상 확인 필요
    */
}