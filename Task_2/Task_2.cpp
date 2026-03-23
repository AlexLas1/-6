#include <iostream>
#include <string>

using namespace std;

void lower_string(string& Text) {
	for (int i = 0; i < Text.length(); i++) {
		Text[i] = tolower(Text[i]);
	}
}

void find_word(string Text, string word) {
	int count_find_word = 0;
	int word_len = word.length();

	for (int i = 0; i <= Text.length() - word_len; i++) {
		if (Text.substr(i, word_len) == word) {
			bool left_boundary = (i == 0) || !isalpha(Text[i - 1]);
			bool right_boundary = (i + word_len == Text.length()) || !isalpha(Text[i + word_len]);

			if (left_boundary && right_boundary) {
				count_find_word++;
			}
		}
	}

	if (count_find_word != 0) {
		cout << "Успешно Найдено: " << count_find_word << " слов(a) - " << word << endl;
	}
	else {
		cout << "Введенное слово - " << word << " не найдено" << endl;
	}
}

void test_data(string text, string word) {
	string test = text;
	string test_word = word;
	lower_string(test);
	lower_string(test_word);
	find_word(test, test_word);
}

int main() {
	setlocale(LC_ALL, "");

	string Text{ "Dog dog dog Hamster cat cat Hamster" };
	string word;

	lower_string(Text);

	cout << "Дан текст: \n" << Text << endl << "Введите слово, которое хотите найти: ";
	cin >> word;
	cin.ignore();

	lower_string(word);

	find_word(Text, word);

	cout << "\nАвтоматические тесты:" << endl;
	test_data(Text, "dog");
	test_data(Text, "cat");
	test_data(Text, "hamster");
	test_data(Text, "elephant");
}