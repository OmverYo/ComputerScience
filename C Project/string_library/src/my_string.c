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
    while (*src != '\0')
    {
        *dest = *src; // 한 글자 복사
        dest++;       // dest 포인터 이동
        src++;        // src 포인터 이동
    }

    *dest = '\0'; // null 문자 복사 (중요!)

    return original_dest;
}

// 3. 문자열 비교
int my_strcmp(const char *s1, const char *s2)
// s1과 s2가 같으면 0, 다르면 음수 또는 양수 반환을 하는 함수
// const인 이유: 원본 문자열을 변경하지 않기 위해
{
    if (s1 == NULL || s2 == NULL)
    // s1 또는 s2에 아무것도 안 들어왔을 때
    {
        return 0; // 또는 에러 처리
    }

    // 둘 중 하나가 끝날 때까지
    while (*s1 != '\0' && *s2 != '\0')
    // &&인 이유: 둘 중 하나라도 끝에 도달하면 논리연산자의 특성상 false가 되어 반복문 종료
    {
        if (*s1 != *s2)
        {
            // ASCII 값 차이 반환, unsigned char인 이유: 음수 값 방지
            return (unsigned char)*s1 - (unsigned char)*s2;
        }
        s1++;
        s2++;
    }

    // 여기까지 왔다면 한쪽 또는 양쪽 모두 끝남
    // "abc"와 "abcd" 비교 시 'c'-'d' = -1
    return (unsigned char)*s1 - (unsigned char)*s2;
}

// 4. 문자열 연결, 문자열 연결하는 이유: 기존 문자열 뒤에 새로운 문자열을 덧붙이기 위해
char *my_strcat(char *dest, const char *src)
{
    if (dest == NULL || src == NULL)
    {
        return NULL;
    }

    char *original_dest = dest;

    // Step 1: dest의 끝으로 이동
    while (*dest != '\0')
    {
        dest++;
    }

    // Step 2: src를 복사
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    *dest = '\0'; // null 종료

    return original_dest;
}