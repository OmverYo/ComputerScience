#define RCC_APB2ENR (*(volatile unsigned int *)0x40021018)
#define GPIOC_CRH (*(volatile unsigned int *)0x40011004)
#define GPIOC_ODR (*(volatile unsigned int *)0x4001100C)

void delay(void)
{
    for (volatile int i = 0; i < 100000; i++)
        ;
}

int main(void)
{
    // 1. GPIOC 클럭 ON
    RCC_APB2ENR |= (1 << 4);

    // 2. PC13 Output 설정
    GPIOC_CRH &= ~(0xF << 20);
    GPIOC_CRH |= (0x2 << 20);

    while (1)
    {
        GPIOC_ODR ^= (1 << 13); // 토글
        delay();
    }
}
