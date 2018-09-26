#include <iostream>

using namespace std;


char* encode(const char *word, int n)
{
	int size = 0;
	while (word[size] != NULL)
	{
		size++;
	}

	char *result = new char[size];
	int insertIndex = 0;
	for (int i = 0; i < n; ++i)
	{
		if (word[i] == ' ')
		{
			result[insertIndex++] = '%';
			result[insertIndex++] = '2';
			result[insertIndex++] = '0';
		}
		else
		{
			result[insertIndex++] = word[i];
		}
	}
	result[insertIndex] = '\0';
	return result;
}

int main()
{
	const char *phrase = "My Name is Jose      ";

	cout << phrase << endl;
	char *result = encode(phrase, 15);
	cout << result << endl;
	system("pause");
}