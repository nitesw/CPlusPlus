#include <iostream>
using namespace std;

void fill_matrix(int** matrix, int row, int col)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            matrix[i][j] = rand() % (10 - 0 + 1) + 0;
        }
    }
}

void print_matrix(int** matrix, int row, int col) 
{
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void shift_rowsR(int** matrix, int row, int col, int k) 
{
    for (int i = 0; i < row; i++)
    {
        int* temp = new int[col];
        for (int j = 0; j < col; j++)
        {
            temp[(j + k) % col] = matrix[i][j];
        }
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = temp[j];
        }
        delete[] temp;
    }
}
void shift_rowsL(int** matrix, int row, int col, int k)
{
    for (int i = 0; i < row; i++)
    {
        int* temp = new int[col];
        for (int j = 0; j < col; j++)
        {
            temp[j] = matrix[i][(j + k) % col];
        }
        for (int j = 0; j < col; j++)
        {
            matrix[i][j] = temp[j];
        }
        delete[] temp;
    }
}

void shift_colsD(int** matrix, int row, int col, int k)
{
    for (int j = 0; j < col; j++)
    {
        int* temp = new int[row];
        for (int i = 0; i < row; i++)
        {
            temp[(i + k) % row] = matrix[i][j];
        }
        for (int i = 0; i < row; i++)
        {
            matrix[i][j] = temp[i];
        }
        delete[] temp;
    }
}
void shift_colsU(int** matrix, int row, int col, int k)
{
    for (int j = 0; j < col; j++)
    {
        int* temp = new int[row];
        for (int i = 0; i < row; i++)
        {
            temp[i] = matrix[(i + k) % row][j];
        }
        for (int i = 0; i < row; i++)
        {
            matrix[i][j] = temp[i];
        }
        delete[] temp;
    }
}

int main()
{
    int row = 3, col = 3;
    int** matrix = new int* [row];
    for (size_t i = 0; i < row; i++)
    {
        matrix[i] = new int[col] {};
    }

    fill_matrix(matrix, row, col);
    print_matrix(matrix, row, col);
    cout << endl << endl;
    shift_rowsR(matrix, row, col, 2);
    print_matrix(matrix, row, col);
    cout << endl << endl;
    shift_rowsL(matrix, row, col, 1);
    print_matrix(matrix, row, col);
    cout << endl << endl;
    shift_colsU(matrix, row, col, 2);
    print_matrix(matrix, row, col);
    cout << endl << endl;
    shift_colsD(matrix, row, col, 1);
    print_matrix(matrix, row, col);
}