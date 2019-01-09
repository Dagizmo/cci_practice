#include <iostream>
#include <vector>
#include <string>

using namespace std;

string check_compression(const string input)
{
	if (input.size() == 1)
	{
		return input;
	}

	string result = "";
	

	char check = input[0];
	int count = 1;
	for (int i = 1; i < input.size(); ++i)
	{
		if (check != input[i])
		{
			result.push_back(check);
			result.append(to_string(count));
			check = input[i];
			count = 0;
		}
		count++;
	}
	result.push_back(check);
	result.append(to_string(count));
	if (input.size() <= result.size())
	{
		return input;
	}
	return result;
}


int main()
{
	string test = "aaabccdddddddder";

	cout << test << endl;

	string result = check_compression(test);
	cout << result << endl;
	system("pause"); 
}
