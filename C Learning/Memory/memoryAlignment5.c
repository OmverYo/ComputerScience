#include <stdio.h>
#include <stdint.h>

// 6. 실전 활용 예제
// 네트워크 프로토콜 구조체
// 네트워크 패킷은 packed로 정의 (바이트 순서 중요)
struct __attribute__((packed)) Packet
{
    uint8_t type;      // 1바이트
    uint16_t length;   // 2바이트
    uint32_t id;       // 4바이트
    uint8_t data[100]; // 100바이트
};

// 나쁜 예 - 캐시 라인 낭비
struct BadNode
{
    char data;            // 1바이트
    struct BadNode *next; // 8바이트
}; // 16바이트 (패딩 포함)

// 좋은 예 - 캐시 효율적
struct GoodNode
{
    struct GoodNode *next; // 8바이트
    char data;             // 1바이트
    char padding[7];       // 명시적 패딩 (나중에 사용 가능)
}; // 16바이트

int main()
{
    printf("패킷 크기: %zu바이트\n", sizeof(struct Packet)); // 정확히 107바이트

    struct Packet pkt = {
        .type = 1,
        .length = 100,
        .id = 12345};

    // 네트워크로 전송 시 정확한 크기
    printf("전송할 바이트: %zu\n", sizeof(pkt));

    printf("\n------------------------\n\n");

    printf("BadNode: %zu바이트\n", sizeof(struct BadNode));
    printf("GoodNode: %zu바이트\n", sizeof(struct GoodNode));

    // 1000개 할당 시
    printf("\n1000개 노드 메모리:\n");
    printf("BadNode: %zu바이트\n", sizeof(struct BadNode) * 1000);
    printf("GoodNode: %zu바이트\n", sizeof(struct GoodNode) * 1000);

    return 0;
}