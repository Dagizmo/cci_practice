#include<iostream>
#include<map>
#include<string>
#include<set>

using namespace std;

int main()
{
	map<string, int> hash_table;
	hash_table.insert(pair<string,int>("test", 2));

	cout << hash_table["test"] << endl;
	hash_table.erase("test");
	cout << hash_table["test"] << endl;

	multiset<string> counter;

	counter.insert("pasta");
	counter.insert("shallot");
	counter.insert("pasta");
	counter.insert("tomato");

	cout << counter.count("pasta") << endl;
	cout << counter.count("tomato") << endl;
	cout << counter.count("pepperoni") << endl;
 	
	system("pause");
	return 0;
}