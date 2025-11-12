#include <iostream>
#include <vector>
using namespace std;

class Cache
{
public:
    vector<int> data;
    /*
    A vector in C++ is like a resizable array.
    The difference between an array and a vector,
    is that the size of an array cannot be modified.
    A vector however, can grow or shrink in size as needed.

    Data here is stored in a dynamic array, which means
    that the memory for the array is allocated at runtime.
    */

    Cache(int size)
    {
        data.resize(size, -1); // -1은 빈 공간 표시
    }

    void insert(int value)
    {
        // 빈 공간이 있으면 그 자리에 넣기
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == -1) // -1은 빈 슬롯
            {
                data[i] = value;
                return; // 삽입 완료하면 함수 종료
            }
        }

        // 빈 공간이 없다면 FIFO 방식으로 처리: 한 칸씩 밀기
        for (int i = 1; i < data.size(); i++)
        {
            data[i - 1] = data[i];
        }

        // 마지막 칸에 새 값을 넣기
        data[data.size() - 1] = value;
    }

    bool access(int value)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == value)
            {
                cout << "Hit! " << value << " is already in cache." << endl;
                return true; // 캐시 히트
            }
        }

        // 캐시 미스
        cout << "Miss! inserting " << value << " into cache." << endl;
        insert(value);

        return false;
    }
};

int main()
{
    Cache cache(4); // 캐시 사이즈: 4

    cache.access(10); // Miss → [10, -1, -1, -1]
    cache.access(20); // Miss → [10, 20, -1, -1]
    cache.access(10); // Hit →  [10, 20, -1, -1]
    cache.access(30); // Miss → [10, 20, 30, -1]
    cache.access(40); // Miss → [10, 20, 30, 40]
    cache.access(50); // Miss → FIFO 교체 → [20, 30, 40, 50]

    cout << "\nCurrent cache: ";
    for (int val : cache.data)
        cout << val << " ";
    cout << endl;

    return 0;
}

/*
컴퓨터에서 캐시는 데이터를 저장하여 나중에 해당 데이터에 대한 요청을
더 빠르게 처리할 수 있도록 하는 하드웨어 또는 소프트웨어 구성 요소이다.
캐시를 찾을 수 있을 때 캐시 히트가 발생, 찾을 수 없을 때 캐시 미스가 발생한다.
캐시에서 처리될 수 있는 요청이 많을수록 시스템 성능은 빨라진다.
*/