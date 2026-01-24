volatile unsigned int counter = 0;

int main(void)
{
    while (1)
    {
        counter++; // 디버거 / map / symbol로 확인 가능
    }
}