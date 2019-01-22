#include <vector>

using namespace std;


int firstDuplicate(std::vector<int> a) {
    std::vector<bool>check (a.size() + 1);
    
    for(int i = 0; i < a.size(); ++i)
    {
        if (!check[a[i]])
        {
            check[a[i]] = true;    
        }
        else
        {
            return a[i];
        }
    }

    return -1;
}
