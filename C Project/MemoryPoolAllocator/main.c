/*
1단계: 정적 메모리 영역 확보
먼저 큰 배열을 정적으로 선언해서 메모리 풀로 사용할 영역을 확보합니다.

#define POOL_SIZE 65536  // 64KB
static char memory_pool[POOL_SIZE];
이 배열이 할당기가 관리할 전체 메모리 영역입니다.
2단계: 메모리 블록 구조 설계
각 메모리 블록의 메타데이터를 저장할 구조체가 필요합니다.
typedef struct Block {
    size_t size;           // 블록 크기
    int is_free;           // 사용 가능 여부 (1: 사용가능, 0: 사용중)
    struct Block* next;    // 다음 블록 포인터
} Block;

3단계: 초기화 함수 구현
메모리 풀을 초기화하고 첫 블록을 설정합니다.
static Block* free_list = NULL;

void pool_init(void) {
    free_list = (Block*)memory_pool;
    free_list->size = POOL_SIZE - sizeof(Block);
    free_list->is_free = 1;
    free_list->next = NULL;
}

4단계: 메모리 할당 함수 (pool_alloc)
요청한 크기만큼 메모리를 찾아서 할당합니다.
void* pool_alloc(size_t size) {
    Block* current = free_list;

    // 적절한 크기의 free 블록 찾기
    while (current != NULL) {
        if (current->is_free && current->size >= size) {
            // 블록 분할 여부 결정
            if (current->size >= size + sizeof(Block) + 1) {
                // 분할 가능: 새 블록 생성
                Block* new_block = (Block*)((char*)current + sizeof(Block) + size);
                new_block->size = current->size - size - sizeof(Block);
                new_block->is_free = 1;
                new_block->next = current->next;

                current->size = size;
                current->next = new_block;
            }

            current->is_free = 0;
            return (void*)((char*)current + sizeof(Block));
        }
        current = current->next;
    }

    return NULL;  // 할당 실패
}

5단계: 메모리 해제 함수 (pool_free)
할당된 메모리를 다시 풀로 반환합니다.
void pool_free(void* ptr) {
    if (ptr == NULL) return;

    Block* block = (Block*)((char*)ptr - sizeof(Block));
    block->is_free = 1;
}

6단계: 인접 블록 병합 (Coalescing)
메모리 단편화를 방지하기 위해 인접한 free 블록들을 병합합니다.
void pool_coalesce(void) {
    Block* current = free_list;

    while (current != NULL && current->next != NULL) {
        if (current->is_free && current->next->is_free) {
            // 두 블록 병합
            current->size += sizeof(Block) + current->next->size;
            current->next = current->next->next;
        } else {
            current = current->next;
        }
    }
}

7단계: 테스트 코드 작성
#include <stdio.h>

int main(void) {
    pool_init();

    int* arr1 = (int*)pool_alloc(10 * sizeof(int));
    int* arr2 = (int*)pool_alloc(5 * sizeof(int));

    if (arr1 != NULL) {
        arr1[0] = 100;
        printf("arr1[0] = %d\n", arr1[0]);
    }

    pool_free(arr1);
    pool_coalesce();

    int* arr3 = (int*)pool_alloc(20 * sizeof(int));

    return 0;
}
*/