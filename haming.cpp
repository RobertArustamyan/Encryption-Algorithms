#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool check_deg(int x) // stuguma 2 i astichana te che ete true return 1 else 0
{
	for (int i = 0; i < 10; i++) {
		if (x == pow(2, i)) return 1;
	}
	return 0;
}

string keterov_string(string str) // string a sarqum bayc 2 i astichanneri texy keta dnum
{
	string new_string;
	int k = 0;
	for (int i = 1; str[k]; i++) {
		if (check_deg(i)) new_string.push_back('.');
		else new_string.push_back(str[k++]);
	}
	return new_string;
}

char for_one(string str)
{
	string new_string;
	for (int i = 0; i < str.size(); i++) {
		if (i % 2 == 0 && i != 0) new_string.push_back(str[i]);
	}
	int return_num = 0;
	for (int i = 0; new_string[i]; i++)if (new_string[i] == '1')return_num++;
	if (return_num % 2 == 0) return '0';
	else return '1';
}
char for_two(string str)
{
	string new_string;
	for (int i = 0; i < str.size(); i++)
	{
		if (i % 4 == 1) {
			if (i != 1)new_string.push_back(str[i]);
			if (str[i + 1] != '\0')new_string.push_back(str[i + 1]);
		}
	}
	int return_num = 0;
	for (int i = 0; new_string[i]; i++)if (new_string[i] == '1')return_num++;
	if (return_num % 2 == 0) return '0';
	else return '1';
}
char for_four(string str)
{
	string new_string;
	for (int i = 0; i < str.size(); i++)
	{
		if (i % 8 == 3) {
			if (i != 3)new_string.push_back(str[i]);
			if (i + 1 < str.size())new_string.push_back(str[i + 1]);
			if (i + 2 < str.size())new_string.push_back(str[i + 2]);
			if (i + 3 < str.size())new_string.push_back(str[i + 3]);
		}
	}

	int return_num = 0;
	for (int i = 0; new_string[i]; i++)if (new_string[i] == '1')return_num++;
	if (return_num % 2 == 0) return '0';
	else return '1';
}
char for_eight(string str)
{
	string new_string;
	for (int i = 0; i < str.size(); i++)
	{
		if (i % 16 == 7) {
			if (i != 7)new_string.push_back(str[i]);
			if (i + 1 < str.size())new_string.push_back(str[i + 1]);
			if (i + 2 < str.size())new_string.push_back(str[i + 2]);
			if (i + 3 < str.size())new_string.push_back(str[i + 3]);
			if (i + 4 < str.size())new_string.push_back(str[i + 4]);
			if (i + 5 < str.size())new_string.push_back(str[i + 5]);
			if (i + 6 < str.size())new_string.push_back(str[i + 6]);
			if (i + 7 < str.size())new_string.push_back(str[i + 7]);

		}
	}

	int return_num = 0;
	for (int i = 0; new_string[i]; i++)if (new_string[i] == '1')return_num++;
	if (return_num % 2 == 0) return '0';
	else return '1';
}
string making_new_string(string str)
{
	str = keterov_string(str);
	char array[4] = { for_one(str),for_two(str),for_four(str),for_eight(str) };
	int k = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '.')str[i] = array[k++];
	}
	return str;
}

int main()
{
	string start, test_str;
	cout << "Greq Dzer tivy(0 ev 1 ov): ";
	getline(cin, start);

	cout << making_new_string(start) << endl;
	cout << "Greq vor tivna dzez ekel(vor petqa stugvi): ";
	getline(cin, test_str);
	start = making_new_string(start);
	if (start == test_str) cout << "NO ERROR";
	else {
		int index_of_error = 0;
		if (for_one(start) != for_one(test_str)) index_of_error += 1;
		if (for_two(start) != for_two(test_str)) index_of_error += 2;
		if (for_four(start) != for_four(test_str)) index_of_error += 4;
		if (for_eight(start) != for_eight(test_str)) index_of_error += 8;

		cout << "Error is in index: " << index_of_error;
	}
}