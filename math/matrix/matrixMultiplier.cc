// Matrix multiplication is an operation where two matrices are combined
// to produce a new matrix. Each element in the resulting matrix is calculated
// as the sum of products of elements from the corresponding row of the first matrix
// and the column of the second matrix.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixCreator(int rows, int columns) {
    vector<vector<int>> matrix(rows, vector<int>(columns));

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            cin >> matrix[row][column]; 
        }
    }

    return matrix;
}

vector<vector<int>> multiply(
    const vector<vector<int>>& first, int rows_first, int columns_first,
    const vector<vector<int>>& second, int rows_second, int columns_second
) {

    if (columns_first != rows_second) {
        cerr << "Invalid matrix dimensions for multiplication!" << endl;
        return {};
    }

    vector<vector<int>> result(rows_first, vector<int>(columns_second, 0));

    for (int row = 0; row < rows_first; row++) {
        for (int column = 0; column < columns_second; column++) {
            for (int i = 0; i < columns_first; i++) {
                result[row][column] += first[row][i] * second[i][column];
            }
        }
    }

    return result;
}

void print(const vector<vector<int>>& matrix, int rows, int columns) {
    for (int row = 0; row < rows; row++) {
        cout << "[ ";
        for (int column = 0; column < columns; column++) {
            cout << matrix[row][column] << " ";
        }
        cout << "]\n";
    }
}

int main() {
    int rows_first, columns_first;
    cout << "Enter the number of rows and columns of the first matrix: ";
    cin >> rows_first >> columns_first;

    cout << "Enter the first matrix:\n";
    vector<vector<int>> first = matrixCreator(rows_first, columns_first);

    int rows_second, columns_second;
    cout << "Enter the number of rows and columns of the second matrix: ";
    cin >> rows_second >> columns_second;

    cout << "Enter the second matrix:\n";
    vector<vector<int>> second = matrixCreator(rows_second, columns_second);

    // Multiply the matrices
    vector<vector<int>> result = multiply(first, rows_first, columns_first,
                                          second, rows_second, columns_second);


    if (!result.empty()) {
        cout << "Result of matrix multiplication:\n";
        print(result, rows_first, columns_second);
    }

    return 0;
}
