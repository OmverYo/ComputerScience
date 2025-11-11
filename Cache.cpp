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
        data[0] = value; // 일단 첫 칸에 넣기
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

    cache.access(10); // Miss → insert(10)
    cache.access(20); // Miss → insert(20) 하지만 현재 insert는 0번째에 덮어씀
    cache.access(10); // Miss -> insert(10)

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