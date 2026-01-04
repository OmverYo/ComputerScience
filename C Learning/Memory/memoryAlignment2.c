#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// 3. 구조체에서의 패딩 (Padding)
// 컴파일러는 자동으로 패딩 (빈 공간)을 추가해서 정렬을 맞춤.

// 예시 1: 패딩이 생기는 경우
struct Bad
{
    char c; // 1바이트
    // [3바이트 패딩]
    int i;   // 4바이트
    char c2; // 1바이트
    // [3바이트 패딩]
};

struct Good
{
    int i;   // 4바이트
    char c;  // 1바이트
    char c2; // 1바이트
    // [2바이트 패딩]
};

// 예시 2: 실제 확인해보기
struct Example
{
    char a;   // 1바이트
    int b;    // 4바이트
    char c;   // 1바이트
    double d; // 8바이트
};

int main()
{
    // 예시 1 출력
    printf("Bad 크기: %zu바이트\n", sizeof(struct Bad));   // 12바이트
    printf("Good 크기: %zu바이트\n", sizeof(struct Good)); // 8바이트

    // 예시 2 출력
    struct Example ex;

    printf("구조체 전체 크기: %zu바이트\n", sizeof(struct Example));
    printf("\n각 멤버의 오프셋:\n");
    printf("a (char)   오프셋: %zu\n", offsetof(struct Example, a));
    printf("b (int)    오프셋: %zu\n", offsetof(struct Example, b));
    printf("c (char)   오프셋: %zu\n", offsetof(struct Example, c));
    printf("d (double) 오프셋: %zu\n", offsetof(struct Example, d));

    printf("\n각 멤버의 실제 주소:\n");
    printf("a 주소: %p\n", (void *)&ex.a);
    printf("b 주소: %p\n", (void *)&ex.b);
    printf("c 주소: %p\n", (void *)&ex.c);
    printf("d 주소: %p\n", (void *)&ex.d);

    /*
    예시 1 메모리 배치:
    struct Bad (12바이트):
    주소:  0    1    2    3    4    5    6    7    8    9    10   11
          [c  ][XXX][XXX][XXX][i----i----i----i] [c2 ][XXX][XXX][XXX]
          1바이트  패딩 3바이트       int 4바이트    1바이트  패딩 3바이트

    struct Good (8바이트):
    주소:  0    1    2    3    4    5    6    7
          [i----i----i----i] [c  ][c2 ][XXX][XXX]
              int 4바이트       1    1  패딩 2바이트

    예시 2 출력:
    구조체 전체 크기: 24바이트

    각 멤버의 오프셋:
    a (char)   오프셋: 0
    b (int)    오프셋: 4   ← 3바이트 패딩
    c (char)   오프셋: 8
    d (double) 오프셋: 16  ← 7바이트 패딩

    메모리 배치:
    오프셋: 0   4         8    16
          [a][XXX][b   ][c][XXXXXXX][d       ]
           1 패딩3   4    1   패딩7       8
    */

    return 0;
}
