#include <stdio.h>
#include <stdlib.h>

// 4. 패딩 최소화하기
// 규칙: 큰 것부터 작은 것 순으로 배치

// 나쁜 예 - 패딩 많음
struct Unoptimized
{
    char c1;  // 1
    double d; // 8
    char c2;  // 1
    int i;    // 4
};

// 좋은 예 - 패딩 최소화
struct Optimized
{
    double d; // 8
    int i;    // 4
    char c1;  // 1
    char c2;  // 1
    // [2바이트 패딩]
};

int main()
{
    printf("Unoptimized: %zu바이트\n", sizeof(struct Unoptimized)); // 32바이트
    printf("Optimized: %zu바이트\n", sizeof(struct Optimized));     // 16바이트
    printf("절약: %zu바이트 (33.3%%)\n", sizeof(struct Unoptimized) - sizeof(struct Optimized));

    /*
    메모리 비교:
    Unoptimized (24바이트):
    [c1][XXXXXXX][d       ][c2][XXX][i   ][XXXX]
     1    패딩7    8         1  패딩3 4     패딩4

    Optimized (16바이트):
    [d       ][i   ][c1][c2][XX]
    8           4    1   1 패딩2
    */

    return 0;
}