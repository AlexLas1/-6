#include <iostream>

using namespace std;

void lower_string(string& Text) {
	for (int i = 0; i < Text.length(); i++) {
		Text[i] = tolower(Text[i]);
	}
}
void find_word(string Text, string word) {
	int count_find_word = 0;
	for (int i = 0; i < Text.length() - word.length(); ) {
		int position = Text.find(word, i);
		if (position == string::npos) break;
		count_find_word += 1;
		i += position + 1;
	}
	cout << "Найдено: " << count_find_word << " слов(a) - " << word << endl;
}

int main() {
	setlocale(LC_ALL, "");

	int count = 0;
	string Text{ "Dog dog dog Hamster cat cat Hamster" };
	string word;

	lower_string(Text);

	cout << "Дан текст: \n" << Text << endl << "Введите слово, которое хотите найти: ";

	cin >> word;

	lower_string(word);

	find_word(Text, word);
}
