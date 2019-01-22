#include <vector>
#include <string>

using namespace std;

int pow(int number, int power)
{
    int result = number;
    for (int i = 0; i < power; ++i)
    {
        result *= number;
    }
    return result;
}

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {

    int zero[255] = { -1 };
    
    for (int i = 0; i < 256; ++i)
    {
        zero[i] = -1;
    }

    if (solution.size() < 1)
    {
        return true;
    }
    
    
    for (int i = 0; i < solution.size(); ++i)
    {
        
    
    
            zero[solution[i][0]] = solution[i][1] - '0';
    }
    
    if ( (zero[crypt[0][0]] == 0 && crypt[0].size() > 1)
        || (zero[crypt[1][0]] == 0 && crypt[1].size() > 1)
        || zero[crypt[2][0]] == 0 && crypt[2].size() > 1)
    {
        return false;
    }
    
    // CONVERT TO NUMBER

    int word[3] = { 0 };
    word[0] = 0;
    word[1] = 0;
    word[2] = 0;

    for (int i = 0; i < crypt.size();++i)
    {
        int multiplier = pow(10,crypt[i].size() - 2);
        
        for ( int j = 0; j < crypt[i].size(); ++j)
        {
            
            word[i] += (zero[crypt[i][j]] * multiplier);
            multiplier /= 10;
        }
    }
    
    return((word[0] + word[1]) == word[2]);
    
    
}