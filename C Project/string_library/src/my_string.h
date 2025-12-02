#ifndef MY_STRING_H
#define MY_STRING_H

/*
왜 이 헤더 파일이 필요함?
1. 컴파일러 지시문: 중복 포함 방지
헤더 파일에 대해 이해가 잘 없었는데, 중복 포함 방지를 위해 꼭 필요하다는 것을 알게 되었다.
아니 대체 이런걸 왜 넣는거임? 프로젝트가 커지면 #include가 여러번 중복될 수 있는데, 이걸 방지해주는 역할을 한다고 한다.
예를 들어 A헤더가 있고 B헤더가 있는데 B헤더에서 A헤더를 또 포함시켜 C파일에서 A, B헤더를 모두 포함시키면 A헤더가 두번 포함되는 상황이 발생할 수 있다.
이럴 때 #ifndef, #define, #endif 지시문을 사용하면 A헤더가 한번만 포함되도록 보장할 수 있다.
*/

#include <stddef.h> // size_t 사용

// 기본 함수들
char *my_strcpy(char *dest, const char *src);
// strcpy의 긴 말: string copy (문자열 복사), dest는 목적지, src는 원본
char *my_strcat(char *dest, const char *src);
// strcat의 긴 말: string concatenate (문자열 이어붙이기)
int my_strcmp(const char *s1, const char *s2);
// strcmp의 긴 말: string compare (문자열 비교), s1과 s2가 같으면 0, 다르면 음수 또는 양수 반환
size_t my_strlen(const char *str);
// strlen의 긴 말: string length (문자열 길이), str의 길이를 반환

// 고급 함수들
char *my_strstr(const char *haystack, const char *needle);
// strstr의 긴 말: string string (문자열 내 문자열 찾기), haystack에서 needle을 찾음
void my_strrev(char *str);
// strrev의 긴 말: string reverse (문자열 뒤집기), str을 뒤집음
char **my_split(const char *str, char delim, int *count);
// split의 긴 말: string split (문자열 나누기), str을 delim 구분자로 나누어 토큰 배열 반환, count에 토큰 개수 저장
void free_split(char **tokens, int count);
// free_split의 긴 말: free split (나눈 문자열 메모리 해제), tokens 배열과 count 개수로 메모리 해제

#endif