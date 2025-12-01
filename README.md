# ComputerScience
반도체 공부 이해를 위한 리포

📚 Phase 1: C언어 기초 (Month 1-2)
Month 1: 프로그래밍 기본
Week 1-2: C언어 기초

개발 환경 세팅

Visual Studio Code + GCC 설치
Linux 환경 익숙해지기 (Ubuntu 권장)
Git 기초 배우기


기본 문법

변수, 자료형 (int, char, float, double)
표준 입출력 (printf, scanf)
연산자 (산술, 관계, 논리, 비트)
조건문 (if-else, switch)
반복문 (for, while, do-while)



Week 3-4: 함수와 배열

함수

함수 정의와 호출
매개변수와 반환값
재귀함수
함수 프로토타입


배열과 문자열

1차원/2차원 배열
문자열 처리
배열과 함수
문자열 라이브러리 함수



실습 프로젝트:

계산기 프로그램
학생 성적 관리 시스템
간단한 텍스트 게임

학습 목표 체크리스트:

 기본 문법을 보지 않고 작성 가능
 배열과 함수를 자유롭게 활용
 100줄 이상의 프로그램 작성 경험


Month 2: 포인터 마스터 (가장 중요!)
Week 1-2: 포인터 기초

메모리 개념

메모리 주소와 변수
스택 vs 힙
메모리 레이아웃 이해


포인터 기본

포인터 선언 (* 연산자)
주소 연산자 (&)
포인터 연산
포인터와 배열의 관계
문자열 포인터



Week 3-4: 고급 포인터

복잡한 포인터

포인터의 포인터 (**)
함수 포인터
void 포인터
const 포인터
포인터 배열 vs 배열 포인터


Call by Value vs Reference

값에 의한 호출
참조에 의한 호출
포인터를 이용한 함수 설계



실습 프로젝트:

포인터를 이용한 문자열 처리 라이브러리 구현
동적 배열 구현
함수 포인터를 이용한 콜백 시스템

학습 목표 체크리스트:

 포인터의 개념을 완벽히 이해
 다중 포인터 자유롭게 사용
 함수 포인터 활용 가능


📚 Phase 2: 고급 C & 자료구조/알고리즘 (Month 3-4)
Month 3: 고급 C 프로그래밍
Week 1-2: 동적 메모리와 구조체

동적 메모리 관리

malloc, calloc, realloc, free
메모리 누수 방지
Valgrind로 메모리 검사
메모리 정렬 (alignment)


구조체와 공용체

struct 정의와 사용
typedef
구조체 포인터
구조체 배열
union (공용체)
enum (열거형)
비트 필드 (bit field)



Week 3-4: 파일 처리와 전처리

파일 입출력

fopen, fclose, fread, fwrite
fprintf, fscanf
바이너리 파일 처리
파일 포인터 제어 (fseek, ftell)


전처리기와 모듈화

#define, #include
매크로 함수
조건부 컴파일 (#ifdef, #ifndef)
헤더 가드
다중 파일 프로그래밍
static, extern 키워드
Makefile 작성



실습 프로젝트:

파일 기반 학생 관리 시스템
모듈화된 라이브러리 제작


Month 4: 자료구조 & 알고리즘
Week 1-2: 기본 자료구조

선형 자료구조

연결 리스트 (단일, 이중, 원형)
스택 (Stack)
큐 (Queue, 원형 큐)
덱 (Deque)


비선형 자료구조

트리 (이진 트리)
이진 탐색 트리
힙 (Heap)
해시 테이블 기초



Week 3-4: 알고리즘

정렬 알고리즘

버블, 선택, 삽입 정렬
퀵 정렬, 머지 정렬
시간 복잡도 분석


검색 알고리즘

선형 검색
이진 검색
BFS, DFS 기초



실습 프로젝트:

각 자료구조를 C로 직접 구현
백준/프로그래머스 문제 100개 풀기

학습 목표 체크리스트:

 모든 기본 자료구조를 구현 가능
 Big-O 표기법 이해
 알고리즘 문제 해결 능력 보유


📚 Phase 3: 임베디드 시스템 기초 (Month 5-7)
Month 5: 디지털 논리 & 컴퓨터 구조
Week 1-2: 디지털 시스템 기초

수 체계와 논리

2진수, 8진수, 16진수
2의 보수
논리 게이트 (AND, OR, NOT, XOR)
불 대수


비트 연산 마스터

비트 AND, OR, XOR, NOT
비트 시프트 (<<, >>)
비트 마스킹 기법
비트 필드 조작
엔디안 (Big/Little Endian)



Week 3-4: 컴퓨터 구조

CPU와 메모리

CPU 동작 원리
레지스터 개념
메모리 계층 구조 (캐시, RAM, ROM)
버스 시스템


ARM 아키텍처 기초

ARM Cortex-M 개요
레지스터 구조
명령어 세트 기초
어셈블리 기초



실습 프로젝트:

비트 연산 라이브러리 구현
간단한 어셈블리 코드 작성


Month 6: 임베디드 C 프로그래밍
Week 1-2: 임베디드 C 핵심

임베디드 C 특징

volatile 키워드 완벽 이해
const 활용
레지스터 맵핑
구조체를 이용한 레지스터 제어
인라인 어셈블리


메모리 관리

링커 스크립트 기초
메모리 섹션 (.text, .data, .bss)
스택과 힙 관리
메모리 정렬



Week 3-4: 하드웨어 인터페이스

GPIO (General Purpose I/O)

디지털 입출력
Pull-up/Pull-down
레지스터 직접 제어


인터럽트

인터럽트 개념과 종류
ISR (Interrupt Service Routine)
인터럽트 우선순위
Nested 인터럽트



실습 환경:

Arduino Uno 또는 STM32 Nucleo 보드 구매
LED, 버튼, 센서 실습

실습 프로젝트:

LED 깜빡이기 (레지스터 직접 제어)
버튼 인터럽트 처리
디바운싱 구현


Month 7: 통신 프로토콜 & 타이머
Week 1-2: 통신 프로토콜

UART (Serial)

UART 동작 원리
보레이트, 패리티, 스톱 비트
송수신 구현
링 버퍼 구현


SPI (Serial Peripheral Interface)

SPI 동작 원리
마스터/슬레이브
센서/메모리와 통신


I2C (Inter-Integrated Circuit)

I2C 프로토콜
주소 지정
다중 디바이스 통신



Week 3-4: 타이머 & PWM

타이머/카운터

타이머 동작 원리
주기적인 인터럽트
시간 측정


PWM (Pulse Width Modulation)

PWM 원리
듀티 사이클 제어
모터/LED 밝기 제어



실습 프로젝트:

UART 통신 프로그램
센서 데이터 SPI/I2C로 읽기
PWM으로 LED 밝기 조절

학습 목표 체크리스트:

 레지스터 직접 제어 가능
 인터럽트 자유롭게 활용
 기본 통신 프로토콜 구현 가능


📚 Phase 4: 반도체 펌웨어 핵심 (Month 8-10)
Month 8: RTOS (Real-Time Operating System)
Week 1-2: RTOS 기초

RTOS 개념

RTOS vs 일반 OS
태스크(Task)와 스케줄링
컨텍스트 스위칭
우선순위 기반 스케줄링


FreeRTOS 시작

FreeRTOS 설치와 설정
태스크 생성과 관리
태스크 상태 (Ready, Running, Blocked)
vTaskDelay vs vTaskDelayUntil



Week 3-4: RTOS 고급

동기화 메커니즘

Semaphore (Binary, Counting)
Mutex
Queue
Event Group
우선순위 역전 문제


메모리 관리

힙 관리 방식
스택 오버플로 검사
메모리 풀



실습 프로젝트:

다중 태스크 LED 제어
Queue를 이용한 센서 데이터 처리
Mutex로 공유 자원 보호


Month 9: 메모리 시스템 심화
Week 1-2: Flash 메모리

Flash 메모리 원리

NAND vs NOR Flash
SLC, MLC, TLC, QLC
페이지, 블록, 플레인 구조
읽기/쓰기/지우기 동작


Flash 관리

Wear Leveling (마모 평준화)
Garbage Collection
Bad Block 관리
ECC (Error Correction Code)



Week 3-4: DRAM & 메모리 컨트롤러

DRAM 기초

DRAM 동작 원리
DDR, DDR2, DDR3, DDR4, DDR5
리프레시(Refresh)
타이밍 파라미터


메모리 컨트롤러

메모리 초기화 시퀀스
캘리브레이션
파워 관리



실습 프로젝트:

Flash 메모리 시뮬레이터 구현
Wear Leveling 알고리즘 구현


Month 10: SSD/스토리지 펌웨어
Week 1-2: SSD 아키텍처

SSD 구조

호스트 인터페이스 (SATA, PCIe, NVMe)
컨트롤러 (프로세서, 코프로세서)
DRAM 캐시
NAND Flash 배열


FTL (Flash Translation Layer)

논리 주소 → 물리 주소 매핑
페이지 매핑, 블록 매핑, 하이브리드 매핑
매핑 테이블 관리



Week 3-4: 펌웨어 최적화

성능 최적화

캐싱 전략
Prefetching
병렬 처리
인터리빙


신뢰성

SMART 모니터링
파워 로스 보호
데이터 무결성 검사



실습 프로젝트:

간단한 FTL 시뮬레이터
매핑 테이블 구현

학습 목표 체크리스트:

 RTOS 기반 프로그램 개발 가능
 Flash 메모리 동작 원리 이해
 SSD 아키텍처 전반 이해


📚 Phase 5: 실전 & 전문화 (Month 11-18)
Month 11-12: 실전 프로젝트
종합 프로젝트 선택 (택 1)
Option 1: 미니 SSD 펌웨어

UART/SPI Flash를 이용한 간단한 스토리지 시스템
FTL 구현
Wear Leveling
SMART 정보 제공

Option 2: IoT 센서 노드

다중 센서 데이터 수집
RTOS 기반 태스크 관리
무선 통신 (WiFi/BLE)
저전력 모드 구현

Option 3: 모터 컨트롤러

PWM 기반 모터 제어
PID 제어 알고리즘
실시간 피드백 처리
안전 기능 구현


Month 13-15: 추가 전문 지식
고급 주제 (필요에 따라 선택)
1. 저전력 설계

파워 모드 관리
클럭 게이팅
파워 게이팅
동적 전압/주파수 조절

2. 보안

Secure Boot
암호화 (AES, RSA)
펌웨어 무결성 검증
하드웨어 보안 모듈

3. 디버깅 & 테스트

JTAG/SWD 디버깅
Logic Analyzer 사용
오실로스코프 활용
단위 테스트 프레임워크

4. 통신 고급

USB (Device/Host)
Ethernet/TCP-IP
CAN Bus
NVMe 프로토콜


Month 16-18: 포트폴리오 & 취업 준비
포트폴리오 구축

GitHub 정리

3-5개의 완성된 프로젝트
README 상세 작성
코드 품질 관리


기술 블로그

학습 내용 정리
프로젝트 후기
트러블슈팅 경험


영어 실력

기술 문서 읽기
데이터시트 해석
영어 코드 작성



취업 준비

이력서/자소서

프로젝트 중심으로 작성
기술 스택 명확히
문제 해결 사례


코딩 테스트

알고리즘 복습
C언어 코딩 테스트 대비


기술 면접

CS 기초 복습
펌웨어 핵심 개념
프로젝트 설명 연습




🎯 학습 전략 & 팁
매일 해야 할 것

코딩: 최소 2-3시간
알고리즘: 문제 1-2개 (백준, 프로그래머스)
복습: 전날 배운 내용 20분

주 단위

프로젝트: 작은 프로젝트 1개 완성
노트 정리: 주요 개념 정리
코드 리뷰: 자신의 코드 다시 보기

월 단위

회고: 한 달간 배운 내용 정리
목표 재설정: 다음 달 계획
포트폴리오 업데이트

핵심 학습 원칙
1. 실습 중심

이론 30% : 실습 70%
모든 개념을 직접 코딩으로 확인
보드 없으면 시뮬레이터라도 활용

2. 깊이 있는 학습

"왜?"를 항상 질문
동작 원리까지 이해
데이터시트 직접 읽기

3. 문서화 습관

코드에 주석 달기
README 자세히 작성
학습 노트 정리

4. 커뮤니티 활용

Stack Overflow
GitHub 오픈소스 참여
개발자 커뮤니티 (OKKY, 생활코딩)


📚 추천 학습 자료
책
C언어:

"C Programming Language" (K&R)
"Expert C Programming"
"C Traps and Pitfalls"

임베디드:

"임베디드 시스템 프로그래밍" (위키북스)
"ARM System Developer's Guide"
"Making Embedded Systems" (Elecia White)

반도체:

"Computer Organization and Design" (Patterson)
"SSD 구조 및 동작원리" (관련 논문)

온라인 강의

Coursera: "Embedded Systems" (University of Texas)
Udemy: "Mastering Microcontroller with Embedded Driver Development"
YouTube: "Fastbit Embedded Brain Academy"

개발 보드

Arduino Uno (~$20) - 입문용
STM32 Nucleo (~$15) - 본격 학습
Raspberry Pi Pico (~$4) - 저렴하고 강력
ESP32 (~$5) - WiFi/BLE 학습

필수 도구

Logic Analyzer (~$10) - 통신 신호 분석
Multimeter (~$20) - 기본 측정
Breadboard & Jumper Wires (~$15)


⚠️ 주의사항 & 함정
흔한 실수들
1. 포인터 대충 넘어가기
❌ 포인터는 펌웨어의 핵심입니다. 완벽히 이해할 때까지 넘어가지 마세요.
2. 이론만 공부
❌ 책만 보지 말고 무조건 코딩하세요. 손으로 익혀야 합니다.
3. 하드웨어 없이 학습
❌ 최소한 Arduino라도 구매해서 실제 하드웨어를 다뤄보세요.
4. 너무 빨리 진도 나가기
❌ 기초가 탄탄하지 않으면 나중에 무너집니다. 급하게 가지 마세요.
5. 영어 공부 미루기
❌ 데이터시트, 레퍼런스 매뉴얼은 대부분 영어입니다. 영어 실력도 함께 키우세요.
어려울 때 대처법
막힐 때

문제를 작게 나누기
간단한 예제부터 시작
디버깅 출력 활용
커뮤니티에 질문 (구체적으로!)

동기부여

작은 성공을 자주 경험하세요
LED 하나 켜도 뿌듯합니다!
동료/멘토 찾기
개발자 커뮤니티 참여


🎓 최종 체크리스트
취업 준비 완료 기준
기술 역량

 C언어로 1000줄 이상 프로그램 작성 가능
 포인터, 메모리 관리 완벽 이해
 자료구조/알고리즘 기본 구현 가능
 레지스터 직접 제어 가능
 RTOS 기반 프로그램 개발 가능
 통신 프로토콜 구현 경험
 Flash 메모리 동작 원리 이해
 SSD 아키텍처 설명 가능

프로젝트

 3개 이상의 완성된 임베디드 프로젝트
 1개 이상의 종합 프로젝트
 GitHub 포트폴리오 완성
 기술 블로그 10개 이상 포스팅

코딩 테스트

 백준 실버 이상 달성
 C언어 알고리즘 문제 200개 이상 풀이

영어

 데이터시트 읽고 이해 가능
 기술 문서 작성 가능


이 로드맵을 따라가면 SK하이닉스, 삼성전자 등 대기업 반도체 펌웨어 개발자로 취업할 수 있는 충분한 역량을 갖추게 됩니다.
핵심은 꾸준함입니다. 하루 2-3시간씩 12-18개월 투자하면 충분히 전문가 수준에 도달할 수 있습니다. 포기하지 말고 한 걸음씩 나아가세요!
질문이나 막히는 부분이 있으면 언제든 물어보세요. 화이팅! 💪