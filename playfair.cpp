#include <iostream>
#include <string>
#include <cctype>
using namespace std;

const string all_letters = "abcdefghijklmnopqrstuvwxyz";
string matrix[5][5];

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

void adding_letters_to_matrix(string str,string mat[5][5])//avelacnumenq tarery matrix i mej
{
	str = makeing_alphabet(str);
	int k = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[k] != 'j') mat[i][j] = str[k++];
			else {
				k += 1;
				mat[i][j] = str[k++];
			}
		}
	}
}

string dividing_sentence_in_two(string str) {
		str = lowercase(str);
		str = removespaces(str);
		if (str.size() % 2) str += 'x';
		string new_string;	
		for (int i = 0; i < str.size(); i ++) {
			if (i%2 ==0) {
				new_string += " ";
			}
			new_string += str[i];
		}
		return new_string;
}

void show_matrix(string mat[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}

bool check_if_in_line(char left, char right, string mat[5][5]) {
	int l = -1;
	int r = - 2;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			const char* charElement = mat[i][j].c_str();
			char l_mat = charElement[0];
			if (left == l_mat) l = i;
			if (right == l_mat) r = i;
		}
	}
	if (l == r) return 1;
	else return 0;
}

bool check_if_in_coloumn(char left, char right, string mat[5][5]) {
	int l = -1;
	int r = -2;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			const char* charElement = mat[i][j].c_str();
			char l_mat = charElement[0];
;			if (left == l_mat) l = j;
			if (right == l_mat) r = j;
		}
	}
	if (l == r) return 1;
	else return 0;
}
int find_index(char s, string mat[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			const char* charElement = mat[i][j].c_str();
			char l_mat = charElement[0];
			if (s == l_mat) return j;
		}
	}
}
int find_row(char s, string mat[5][5]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			const char* charElement = mat[i][j].c_str();
			char l_mat = charElement[0];
			if (s == l_mat) return i;
		}
	}
}
string encrypt(string str,string mat[5][5]) {

	str = dividing_sentence_in_two(str);
	string new_string = str + "    ";
	int k = 1;
	for (int i = 1; i < str.size(); i += 3) {
		if (check_if_in_coloumn(str[i], str[i + 1],matrix) == 0 && check_if_in_line(str[i], str[i + 1],matrix) == 0) {
			unsigned new_l_index = find_index(str[i + 1], matrix);
			unsigned new_r_index = find_index(str[i], matrix);
			unsigned l_row = find_row(str[i], matrix);
			unsigned r_row = find_row(str[i + 1], matrix);

			const char* char_l_elem = mat[l_row][new_l_index].c_str();
			//str[i] = char_l_elem[0];
			new_string[k] = char_l_elem[0];
			const char* char_r_elem = mat[r_row][new_r_index].c_str();
			//str[i+1] = char_r_elem[0];
			new_string[k+1] = char_r_elem[0];
			k += 3;
		}
		else if (check_if_in_coloumn(str[i], str[i + 1], matrix) == 1 && check_if_in_line(str[i], str[i + 1], matrix) == 0) {
			unsigned l_row = find_row(str[i], matrix);
			unsigned r_row = find_row(str[i + 1], matrix);
			unsigned colomn = find_index(str[i], matrix);
			if (l_row + 1 == 5) {
				l_row = 0;
				r_row += 1;
			}
			else if (r_row + 1 == 5) {
				r_row = 0;
				l_row += 1;
			}
			else {
				l_row += 1;
				r_row += 1;
			}
			const char* char_l_elem = mat[l_row][colomn].c_str();
			//str[i] = char_l_elem[0];
			new_string[k] = char_l_elem[0];
			const char* char_r_elem = mat[r_row][colomn].c_str();
			//str[i + 1] = char_r_elem[0];
			new_string[k+1] = char_r_elem[0];
			k += 3;

		}
		else if (check_if_in_coloumn(str[i], str[i + 1], matrix) == 0 && check_if_in_line(str[i], str[i + 1], matrix) == 1) {
			unsigned l_col = find_index(str[i],matrix);
			unsigned r_col = find_index(str[i + 1], matrix);
			unsigned row = find_row(str[i], matrix);

			if (l_col + 1 == 5) {
				l_col = 0;
				r_col += 1;
			}
			else if (r_col + 1 == 5) {
				r_col = 0;
				l_col += 1;
			}
			else {
				l_col += 1;
				r_col += 1;
			}
			const char* char_l_elem = mat[row][l_col].c_str();
			//str[i] = char_l_elem[0];
			new_string[k] = char_l_elem[0];
			const char* char_r_elem = mat[row][r_col].c_str();
			//str[i + 1] = char_r_elem[0];
			new_string[k + 1] = char_r_elem[0];
			k += 3;
		}
		else {
			str[i + 1] = 'x';
			unsigned new_l_index = find_index(str[i + 1], matrix);
			unsigned new_r_index = find_index(str[i], matrix);
			unsigned l_row = find_row(str[i], matrix);
			unsigned r_row = find_row(str[i + 1], matrix);

			const char* char_l_elem = mat[l_row][new_l_index].c_str();
			//str[i] = char_l_elem[0];
			new_string[k] = char_l_elem[0];
			const char* char_r_elem = mat[r_row][new_r_index].c_str();
		//	str[i + 1] = char_r_elem[0];
			new_string[k + 1] = char_r_elem[0];
			k += 3;
			new_string[k] = char_l_elem[0];
			new_string[k+1] = char_r_elem[0];
			k += 3;
		}
	}
	return new_string;
}
int main()
{
	string code, unconvert;
	cout << "Greq skzbnakan naxadasutyuny vorpes klyuch: ";
	getline(cin, code);
	cout << "Greq ayn naxadasutyuny vory uzumeq kodavorel: ";
	getline(cin, unconvert);

	adding_letters_to_matrix(code, matrix);
	cout << endl;
	show_matrix(matrix);
	
	cout <<endl << endl << encrypt(unconvert,matrix);


}