#include <stdio.h>
#include <stdalign.h>

// 5. 정렬 강제하기
// __attribute__((packed)) - 패딩 제거 (GCC)
// 기본 구조체
struct Normal
{
    char c;
    int i;
    char c2;
};

// 패킹된 구조체 (패딩 제거)
struct __attribute__((packed)) Packed
{
    char c;
    int i;
    char c2;
};

// _Alignas - 정렬 지정 (C11)
struct Custom
{
    _Alignas(16) char c; // 16바이트 정렬 강제
    int i;
};

int main()
{
    printf("Normal 크기: %zu바이트\n", sizeof(struct Normal)); // 12바이트
    printf("Packed 크기: %zu바이트\n", sizeof(struct Packed)); // 6바이트

    struct Packed p;
    printf("\nPacked 구조체 주소:\n");
    printf("c 주소: %p\n", (void *)&p.c);
    printf("i 주소: %p (정렬 안 맞음!)\n", (void *)&p.i);
    printf("c2 주소: %p\n", (void *)&p.c2);

    printf("\n------------------------\n\n");

    struct Custom obj;
    printf("구조체 크기: %zu바이트\n", sizeof(struct Custom));
    printf("c의 정렬: %zu바이트\n", alignof(char));
    printf("Custom의 정렬: %zu바이트\n", alignof(struct Custom));
    printf("c 주소: %p (16의 배수)\n", (void *)&obj.c);

    return 0;
}

/*
주의: packed를 사용하면:

메모리는 절약되지만
성능이 떨어질 수 있음 (CPU가 여러 번 읽어야 함)
일부 CPU에서는 크래시 발생 가능
*/