#include <stdio.h>
#include <stdlib.h>

int reallocExample()
{
    /*
    realloc - 메모리 크기 변경 (방 확장/축소 역할)
    이미 할당된 메모리의 크기를 변경하고 싶을 때 사용

    실생활 비유:
    1. 처음에 3인실 방을 빌림
    2. 나중에 5인실 방으로 확장하고 싶음
    3. 또는 2인실 방으로 축소하고 싶음

    문법:
    새_포인터 = realloc(기존_포인터, 새로운_크기);
    */

    // 1. 처음에 3개짜리 배열 할당
    int *arr = malloc(3 * sizeof(int));
    if (arr == NULL)
    {
        printf("할당 실패!\n");
        return 1;
    }

    // 2. 값 저장
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    printf("확장 전: ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 3. 5개로 확장!
    int *temp = realloc(arr, 5 * sizeof(int));
    if (temp == NULL)
    {
        printf("재할당 실패!\n");
        free(arr); // 기존 메모리는 유지되므로 해제 필요
        return 1;
    }
    arr = temp; // 성공하면 포인터 업데이트

    // 4. 새로운 공간에 값 추가
    arr[3] = 40;
    arr[4] = 50;

    printf("확장 후: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]); // 10 20 30 40 50
    }
    printf("\n");

    free(arr);
    // free(temp); // temp는 arr과 동일한 주소를 가리키므로 중복 해제 금지

    return 0;

    /*
    잘못된 사용법:
    int *arr = malloc(3 * sizeof(int));

    // 나쁜 예: 실패 시 arr을 잃어버림!
    arr = realloc(arr, 5 * sizeof(int));
    if (arr == NULL) {
        // 여기서 원래 메모리 주소를 잃어버림!

    올바른 사용법:
    int *arr = malloc(3 * sizeof(int));

    // 좋은 예: 임시 포인터 사용
    int *temp = realloc(arr, 5 * sizeof(int));
    if (temp == NULL) {
        printf("실패!\n");
        free(arr);  // 기존 메모리는 여전히 유효
        return 1;
    }
    arr = temp;  // 성공 시에만 업데이트
    */
}

int expandReallocExample()
{
    int capacity = 2; // 초기 용량
    int size = 0;     // 현재 사용 중인 크기
    int *arr = malloc(capacity * sizeof(int));

    if (arr == NULL)
        return 1;

    // 10개의 숫자를 추가하면서 자동으로 확장
    for (int i = 0; i < 10; i++)
    {
        // 공간이 부족하면 2배로 확장
        if (size >= capacity)
        {
            capacity *= 2;
            printf("용량 확장: %d -> %d\n", capacity / 2, capacity);

            int *temp = realloc(arr, capacity * sizeof(int));
            if (temp == NULL)
            {
                free(arr);
                return 1;
            }
            arr = temp;
        }

        arr[size] = i * 10;
        size++;
    }

    // 최종 결과 출력
    printf("최종 배열: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

int reduceReallocExmaple()
{
    // 1. 10개 할당
    int *arr = malloc(10 * sizeof(int));
    if (arr == NULL)
        return 1;

    // 2. 값 저장
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
    }

    printf("원래 크기: 10개\n");

    // 3. 5개로 축소
    int *temp = realloc(arr, 5 * sizeof(int));
    if (temp == NULL)
    {
        free(arr);
        return 1;
    }
    arr = temp;

    printf("축소 후: ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]); // 1 2 3 4 5
    }
    printf("\n");

    free(arr);
    return 0;
}

int main()
{
    /*
    realloc의 특별한 경우들:
    1. NULL을 전달하면 malloc과 동일
    int *arr = realloc(NULL, 5 * sizeof(int));
    // 이것은 malloc(5 * sizeof(int))와 같음

    2. 크기 0을 전달하면 free와 동일 (구현에 따라 다름)
    arr = realloc(arr, 0);
    // 많은 구현에서 free(arr)와 같음

    핵심 정리:
    함수 / 용도 / 기존 데이터 / 주의사항
    malloc / 새로 할당 / 없음 / 초기화 안됨
    calloc / 0으로 초기화하여 할당 / 없음 / 초기화 됨
    realloc / 크기 변경 / 유지됨 / 임시 포인터 사용!
    */
    printf("=== realloc 예제 ===\n");
    reallocExample();

    printf("\n=== 자동 확장 예제 ===\n");
    expandReallocExample();

    printf("\n=== 축소 예제 ===\n");
    reduceReallocExmaple();

    return 0;
}