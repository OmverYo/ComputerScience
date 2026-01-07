#include <stdio.h>
#include <stddef.h>

// 7. 정렬 확인 도구
#define PRINT_ALIGNMENT(type) \
    printf("%-20s 크기: %2zu, 정렬: %2zu\n", #type, sizeof(type), _Alignof(type))

struct MyStruct
{
    char c;
    int i;
    double d;
};

int main()
{
    printf("=== 기본 타입 정렬 ===\n");
    PRINT_ALIGNMENT(char);
    PRINT_ALIGNMENT(short);
    PRINT_ALIGNMENT(int);
    PRINT_ALIGNMENT(long);
    PRINT_ALIGNMENT(float);
    PRINT_ALIGNMENT(double);
    PRINT_ALIGNMENT(void *);

    printf("\n=== 구조체 정렬 ===\n");
    PRINT_ALIGNMENT(struct MyStruct);

    printf("\n=== 구조체 멤버 오프셋 ===\n");
    printf("c 오프셋: %zu\n", offsetof(struct MyStruct, c));
    printf("i 오프셋: %zu\n", offsetof(struct MyStruct, i));
    printf("d 오프셋: %zu\n", offsetof(struct MyStruct, d));

    return 0;
}

/*
8. 핵시 정리
메모리 정렬 규칙
1. 각 타입은 자기 크기의 배수 주소에 저장됨
2. 구조체는 가장 큰 멤버의 정렬을 따름
3. 컴파일러가 자동으로 패딩 추가

최적화 팁
1. 큰 타입부터 작은 타입 순으로 배치 (double -> int -> char)
2. 비트필드 활용 (1~2 바이트 절약 시)
3. 네트워크/파알 I/O는 packed 사용
4. 성능이 중요하면 패딩 허용

언제 신경 써야 하나?
O 대용량 배열/구조체 (메모리 절약)
O 임베디드/게임 (메모리 제한)
O 네트워크 프로토콜 (정확한 크기)
O 캐시 최적화 (성능)
X 일반적인 코드 (컴파일러가 알아서 함)
 */