#include <iostream>
#include <vector>
#include <string>

std::string check_compression(const std::string input)
{
	if (input.size() == 1)
	{
		return input;
	}

	std::string result = "";

	char check = input[0];
	int count = 1;
	unsigned int inputSize = input.size();
	for (unsigned int i = 1; i < inputSize; ++i)
	{
		if (check != input[i])
		{
			result.push_back(check);
			result.append(std::to_string(count));
			check = input[i];
			count = 0;
		}
		count++;
	}
	result.push_back(check);
	result.append(std::to_string(count));

	if (inputSize <= result.size())
	{
		return input;
	}
	return result;
}

int main()
{
	std::string test = "aaabccdddddddd";
	std::cout << test << std::endl;

	std::string result = check_compression(test);
	std::cout << result << std::endl;
	system("pause");
}