#include <iostream>
#include <string>
#include <cctype>	
using namespace std;

const string all_letters = "abcdefghijklmnopqrstuvwxyz";

string removespaces(string str) // jnjuma space ery str naxadasutyan mejic
{
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

string lowercase(string str) // str naxadasutyan sax tarery sarquma poratar
{
	for (int i = 0; str[i]; i++) str[i] = tolower(str[i]);
	return str;
}

string removing_same(string str) // jnjuma str i meji bolor krknutyunnery
{
	string diff = "";
	diff = str.at(0);
	for (int i = 1; i < str.length(); i++) {
		if (!(diff.find(str.at(i)) < diff.length()))
			diff = diff + str.at(i);
	}
	diff = removespaces(diff);
	return diff;
}
string add_letters(string str) // veradardznuma naxadasutyun vorum klinen ayn tarery voronq chkain skzbanakan naxadasutyan mej
{
	string ret_str = "";
	for (int i = 0; all_letters[i]; i++) {
		bool fnd = false;
		for (int j = 0; str[j]; j++) {
			if (all_letters[i] == str[j]) fnd = true;
		}
		if (fnd == false) {
			ret_str.push_back(all_letters[i]);
		}
	}
	return ret_str;
}

string makeing_alphabet(string str) // sarquma nor tarer
{
	string new_letters;

	str = lowercase(str);
	str = removing_same(str);
	str = removespaces(str);
	string missing_letters = add_letters(str);
	string alphabet;
	for (int i = 0; str[i]; i++) {
		alphabet.push_back(str[i]);
	}
	for (int i = 0; missing_letters[i]; i++) {
		alphabet.push_back(missing_letters[i]);
	}

	return alphabet;
}

string encrypt(string str, string key)
{
	str = lowercase(str);
	for (int i = 0; str[i]; i++) {
		if (isalpha(str[i])) {
			str[i] = key[(int)str[i] - 97];
		}
		else if (str[i] == ' ') str[i] = ' ';
	}
	return  str;
}
int find_index(char let, string str) // mana galis u charuma indexy let i str[] array i mej
{
	for (int i = 0; str[i]; i++) {
		if (let == str[i]) return i;
		else if (let == ' ') return -1;
	}
}
string descrypt(string str, string key) // talises kodavorvac text mekel klyuchy inqy heta sarqum skzbnakan naxadasutyuny
{
	string descrypt_string = str;
	for (int i = 0; str[i]; i++) {
		if (find_index(str[i], key) != -1) descrypt_string[i] = static_cast<char>(find_index(str[i], key) + 97);
		else descrypt_string[i] = ' ';
	}
	return descrypt_string;
}
int main()
{
	string code, unconvert;
	cout << "Greq skzbnakan naxadasutyuny vorpes klyuch: ";
	getline(cin, code);
	cout << "Greq ayn naxadasutyuny vory uzumeq kodavorel: ";
	getline(cin, unconvert);

	string key = makeing_alphabet(code);
	cout << "Ayn aybenarany vorov kodavorvelu e: " << key << "\n";
	
	string result = encrypt(unconvert, key);
	cout << "Verjnakan resultaty: " << result;

	cout << "\nSkzbakan texy (discrypt): " << descrypt(result,key);
}