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

    bool access(int value)
    {
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == value)
            {
                cout << "Hit! " << value << " is already in cache (LRU update)" << endl;

                int temp = data[i]; // 해당 값을 저장

                // 사용했으므로 해당 값을 맨 뒤(최신 위치)로 이동
                data.erase(data.begin() + i);
                data.push_back(temp);

                return true;
            }
        }

        // Miss
        cout << "Miss! inserting " << value << " into cache (LRU)" << endl;

        insert(value);
        return false;
    }

    void insert(int value)
    {
        // 빈 공간이 있으면 거기 넣기
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == -1)
            {
                data[i] = value;
                return;
            }
        }

        // 빈 공간이 없다면 LRU 방식으로 가장 오래된 데이터를 제거하고 넣기
        data.erase(data.begin()); // 첫 번째(가장 오래된) 제거
        data.push_back(value);    // 새 값을 가장 최근 위치에 추가
    }
};

int main()
{
    Cache cache(4); // 캐시 사이즈: 4

    cache.access(10); // [10, -1, -1, -1]
    cache.access(20); // [10, 20, -1, -1]
    cache.access(30); // [10, 20, 30, -1]
    cache.access(10); // Hit! → [20, 30, 10, -1]
    cache.access(40); // [20, 30, 10, 40]
    cache.access(30); // Hit! → [20, 10, 40, 30]
    cache.access(50); // Miss → 가장 오래된 20 제거 → [10, 40, 30, 50]

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