#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> initial_state_vector() {
	vector<int> state;
	for (int i = 0; i <= 255; i++) {
		state.push_back(i);
	}

	return state;
}

vector<char> temp_vector(string str) {
	int k = 0;
	vector<char> temp;
	for (int i = 0; i <= 255; i++) {
		if (k == str.size()) k = 0;
		temp.push_back(str[k++]);
	}
	return temp;
}

vector<int> permuted_vector(string key) {
	vector<char> char_vector = temp_vector(key);
	vector<int> ret_vector = initial_state_vector();
	int j = 0;
	for (int i = 0; i <= 255; i++) {
		j = (j + ret_vector[i] + (int)char_vector[i]) % 256;
		swap(ret_vector[i], ret_vector[j]);
	}
	return ret_vector;
}

vector<int>pseudo_rand_keystream(vector<int>permuted,int size) {
	int i = 0, j = 0;
	vector<int> ret_vect;
	while (size > 0) {
		i = (i + 1) % 256;
		j = (j + permuted[i]) % 256;
		swap(permuted[i], permuted[j]);
		ret_vect.push_back(permuted[(permuted[i] + permuted[j]) % 256]);
		size--;
	}
	return ret_vect;
}

vector<int>encrypt(vector<int>pseudo_rand, string text) {
	for (int i = 0; i < text.size(); i++) {
		pseudo_rand[i] = pseudo_rand[i] ^ (int)text[i];
	}
	return pseudo_rand;
}

vector<char>discrypt(vector<int>pseudo_rand, vector<int> ciphertext) {
	vector<char>disc_text;
	for (int i = 0; i < pseudo_rand.size(); i++) {
		disc_text.push_back(pseudo_rand[i] ^ ciphertext[i]);
	}

	return disc_text;
}


int main()
{
	// Skzbnakan inputnery: 
	string key, plain_text;
	cout << "Enter key: ";
	getline(cin, key);
	cout << "Enter text: ";
	getline(cin, plain_text);

	//Sarquma state vector(0ic 255 arjeqov)
	vector<int> initial_st_vect = initial_state_vector();
	//for (int i = 0; i <= 255; i++) cout << initial_st_vect[i] << "|";

	//key ov vectori sarqum
	vector<char>temp_char_vect = temp_vector(key);
	//for (int i = 0; i <= 255; i++) cout << temp_char_vect[i] << "|";


	//intializing permuted state vector
	vector<int> permuted_vect = permuted_vector(key);
	//for (int i = 0; i <= 255; i++) cout << permuted_vect[i] << "|";
	

	//pseudo rand keystream
	vector<int> pseudo_rand = pseudo_rand_keystream(permuted_vect,plain_text.size());
	//for (int i = 0; i < plain_text.size(); i++) cout << pseudo_rand[i] << "|";

	//encrypt
	vector<int>ciphertext = encrypt(pseudo_rand, plain_text);
	cout << "ENCRYPT: ";
	for (int i = 0; i < plain_text.size(); i++) cout << ciphertext[i] << "|";
	cout << endl<< endl;

	//discrypt
	vector<char>disc_text = discrypt(pseudo_rand, ciphertext);
	cout << "DISCRIPT: ";
	for (int i = 0; i < plain_text.size(); i++) cout << disc_text[i] << "|";
}