#include <iostream>
#include <string>

using namespace std;

bool checkPermutation(string a, string b)
{
	if (a.size() != b.size())
	{
		return false;
	}

	char countA[256] = { 0 };
	char countB[256] = { 0 };

	for (unsigned int i = 0; i < a.size(); ++i)
	{
		countA[a[i]]++;
		countB[b[i]]++;
	}

	for (int i = 0; i < 256; ++i)
	{
		if (countA[i] != countB[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	string a = "Hello";
	string b = "ellHo";
	cout << checkPermutation(a, b) << endl;
	system("pause");
}