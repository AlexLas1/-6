#include <iostream>
#include <ctime>

using namespace std;

void create_matrix_and_average(double* matrix, double& average, int& zero_el, int size, int max_number, int min_number, double& summ_matrix) {
    summ_matrix = 0;
    for (int i = 0; i < size; i++) {    
        matrix[i] = rand() % (max_number - min_number + 1) + min_number;
        summ_matrix += matrix[i];
        if (matrix[i] == 0) {
            zero_el += 1;
        }
    }
    average = summ_matrix / size;
}

void change_matrix(double* matrix_original, double* matrix_new, double average_initial, double& average_new, double& average_orig_modified, int size, int new_size, double summ_initial, int zero_el) {
    int index_for_matrix_new = 0;
    double summ_new = 0;
    for (int i = 0; i < size; i++) {
        if (matrix_original[i] != 0) {
            matrix_new[index_for_matrix_new] = matrix_original[i];
            summ_new += matrix_original[i];
            index_for_matrix_new += 1;
        }
        else {
            matrix_original[i] = average_initial;
        }
    }
    if (new_size > 0) {
        average_new = summ_new / new_size;
    }
    else {
        average_new = 0;
    }
    double summ_orig_modified = summ_initial + zero_el * average_initial;
    average_orig_modified = summ_orig_modified / size;
}

void compare_matrix(double average_orig, double average_new) {
    double compare = average_orig - average_new;
    cout << "\nРазница между оригинальным и новым массивом состалвяет: " << compare << endl;
}

void check_matrix(double* matrix, int size) {
    cout << "Ваш массив действительных чисел: \n";
    for (int i = 0; i < size; i++) {
        cout << matrix[i] << " ";
    }
    cout << "\nКонец массива действительных чисел" << endl;
}


int main() {
    setlocale(LC_ALL, "ru");
    srand(time(0));

    int size = 0;
    cout << "Введите размерность массива действительных чисел: ";
    while (!(cin >> size) || size <= 0) {
        cin.clear();
        cin.ignore(32767, '\n');
        cout << "Неверный ввод. Введите положительное число: ";
    }

    double average = 0;
    double average_new = 0;
    double average_orig_modified = 0;
    int max_number = 10;
    int min_number = -10;
    int zero_el = 0;
    double summ_matrix = 0;

    double* matrix_orig = new double[size];

    create_matrix_and_average(matrix_orig, average, zero_el, size, max_number, min_number, summ_matrix);
    check_matrix(matrix_orig, size);

    int new_size = size - zero_el;
    double* matrix_new = nullptr;

    if (new_size > 0) {
        matrix_new = new double[new_size];
        change_matrix(matrix_orig, matrix_new, average, average_new, average_orig_modified, size, new_size, summ_matrix, zero_el);
        check_matrix(matrix_orig, size);
        check_matrix(matrix_new, new_size);
        compare_matrix(average_orig_modified, average_new);
        delete[] matrix_new;
    }
    else {
        for (int i = 0; i < size; i++) {
            matrix_orig[i] = average;
        }
        average_orig_modified = average;
        check_matrix(matrix_orig, size);
        cout << "\nНовый массив пуст (все элементы были нулевыми)" << endl;
        compare_matrix(average_orig_modified, average_new);
    }

    delete[] matrix_orig;
    return 0;
}
