#include <iostream>

using namespace std;

const char END = '\0';

char *encode(const char *word, const int size_n)
{
	int size = 0;
	while (word[size++] != NULL) { }

	char *result = new char[size];
	int insertIndex = 0;

	for (int i = 0; i < size_n; ++i)
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
	result[insertIndex] = END;
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