#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
// #include "my_string.h" 포함은 my_string.h에서 설명했듯 이미 되어 있으므로 중복 포함 방지됨

// 1. 문자열 길이 구하기
size_t my_strlen(const char *str)
{
    // NULL 체크 (방어적 프로그래밍)
    // 주어진 문자열이 NULL일 경우 길이는 0으로 간주
    if (str == NULL)
    {
        printf("[my_strlen] NULL input\n");
        return 0;
    }

    size_t len = 0;
    const char *ptr = str; // 포인터를 문자열의 시작 위치로 초기화

    while (*ptr != '\0') // 포인터가 가리키는 값이 널 문자('\0')가 아닐 때까지 반복
    {
        printf("[my_strlen] ptr=%p, char='%c'\n", ptr, *ptr);
        ptr++; // 포인터를 다음 문자로 이동
        len++; // 길이 증가
    }

    printf("[my_strlen] Final length: %zu\n", len);
    return len;
}

// 2. 문자열 복사
char *my_strcpy(char *dest, const char *src)
{
    // dest는 복사될 목적지, src는 복사할 원본
    // NULL 체크
    if (dest == NULL || src == NULL)
    {
        return NULL;
    }

    // dest의 시작 주소 저장 (반환용)
    char *original_dest = dest;

    // src가 끝날 때까지 복사
    // while (*src != '\0')
    // {
    //     *dest = *src; // 한 글자 복사
    //     dest++;       // dest 포인터 이동
    //     src++;        // src 포인터 이동
    // }

    // 복사와 증가를 한 줄에!
    while ((*dest++ = *src++) != '\0')
    {
        // 이 줄 하나가 위의 while 블록 전체를 대체
    }

    *dest = '\0'; // null 문자 복사 (중요!)

    return original_dest;
}