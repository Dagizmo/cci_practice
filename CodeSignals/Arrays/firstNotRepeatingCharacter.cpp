#include <string>

using namespace std;

char firstNotRepeatingCharacter(std::string s) {
    int count[255] = { 0 };
    int pos[255] = {0};
    
    for (int i = 0; i < s.size(); ++i)
    {
        if (count[s[i]] == 0)
        {
            pos[s[i]] = i;
        }
        count[s[i]]++;
    }
    char answer = '_';
    
    for (int i = 0; i < 255; ++i)
    {
        if (count[i] == 1 && answer == '_')
        {
            answer = i;
        }
        else if (count[i] == 1)
        {
            if (pos[i] < pos[answer])
            {
                answer = i;
            }
        }
    }
    
    return answer;
}
