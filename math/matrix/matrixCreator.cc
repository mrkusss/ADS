//// A matrix is a rectangular arrangement of numbers, symbols, or expressions
// organized in rows and columns. It is used to represent and manipulate
// data in mathematics, physics, computer graphics, and many other fields.

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixCreator(int rows, int columns)
{
    vector<vector<int>> matrix(rows, vector<int>(columns));

    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            cin >> matrix[row][column];
        }
    }

    return matrix;
}

void print(vector<vector<int>> matrix, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        cout << "[ ";
        for (int column = 0; column < columns; column++)
        {
            cout << matrix[row][column] << " ";
        }
        cout << "]\n";
    }
}

int main()
{
    int rows,columns;

    cin >> rows >> columns;

    vector<vector<int>> matrix = matrixCreator(rows,columns);

    print(matrix, rows, columns);

    return 0;
}