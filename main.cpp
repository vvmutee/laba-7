#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long matrix[100][100];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    bool all_diag_max = true;
    long long diag_product = 1;

    for (int i = 0; i < n; ++i) {
        long long max_in_row = matrix[i][i];
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] > max_in_row) {
                max_in_row = matrix[i][j];
            }
        }
        if (matrix[i][i] != max_in_row) {
            all_diag_max = false;
            break;
        }
        diag_product *= matrix[i][i]; //Вычисляем произведение диагональных элементов
    }

    if (all_diag_max) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) { //Проверяем наличие 0 в числе
                string s = to_string(matrix[i][j]);
                bool contains_zero = false;
                for (char c : s) {
                    if (c == '0') {
                        contains_zero = true;
                        break;
                    }
                }
                if (contains_zero) {
                    matrix[i][j] = diag_product;
                }
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matrix[i][j] << (j == n - 1 ? "" : " ");
        }
        cout << endl;
    }

    return 0;
}



