#include <vector>
#include <iostream>
using namespace std;

std::vector<std::vector<int>> rotate(std::vector<std::vector<int>> map, int depth, int size) 
{
    cout << "depth : " << depth << "  ";
    cout << "size : " << size << endl;
    int offset = 0;
    for (int i = depth; i < size; ++i)
    {
        int temp = map[depth][i];
        map[depth][i] = map[size - offset][depth];
        map[size - offset][depth]  = map[size][size-offset];
        map[size][size-offset] = map[i][size];
        map[i][size] = temp;
        offset ++;
    }
    
    return map;
}

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
    
    int times = a[0].size() / 2;
    int max = a[0].size() - 1;
    for (int i = 0; i < times; ++i)
    {
        a = rotate(a, i, max);            
        max--;
    }
    
    return a;
}
