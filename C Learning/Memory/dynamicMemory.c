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
    int x = 5; // 스택: 함수 끝나면 자동 사라짐

    int *ptr = malloc(sizeof(int)); // 힙: 우리가 직접 관리해야 함!
    *ptr = 10;
    free(ptr); // 직접 반환해야 함!

    return 0;
}