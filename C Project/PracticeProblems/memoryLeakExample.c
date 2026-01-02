#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 예시
typedef struct
{
    char *name;
    int *scores;
    int score_count;
} Student;

// 학생 생성 (메모리 할당)
Student *create_student(const char *name, int score_count)
{
    // 1. 구조체 할당
    Student *student = malloc(sizeof(Student));
    if (student == NULL)
        return NULL;

    // 2. 이름 할당
    student->name = malloc(strlen(name) + 1);
    if (student->name == NULL)
    {
        free(student); // 이미 할당한 것 해제
        return NULL;
    }
    strcpy(student->name, name);

    // 3. 점수 배열 할당
    student->scores = malloc(score_count * sizeof(int));
    if (student->scores == NULL)
    {
        free(student->name); // 이미 할당한 것들 해제
        free(student);
        return NULL;
    }
    student->score_count = score_count;

    return student;
}

// 학생 삭제 (메모리 해제)
void destroy_student(Student *student)
{
    if (student == NULL)
        return;

    // 할당한 순서의 역순으로 해제
    free(student->scores);
    free(student->name);
    free(student);
}

int main()
{
    Student *s = create_student("홍길동", 5);
    if (s == NULL)
    {
        printf("학생 생성 실패\n");
        return 1;
    }

    // 학생 정보 사용...
    for (int i = 0; i < s->score_count; i++)
    {
        s->scores[i] = 90 + i;
    }

    // 반드시 해제
    destroy_student(s);

    return 0;
}