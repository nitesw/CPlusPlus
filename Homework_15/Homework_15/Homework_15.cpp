#include <iostream>
using namespace std;

int main()
{
    const int n = 3;
    const int ROW = n, COL = n;

    int matrix[ROW][COL];
    int num = 1;
    int row_start = 0, row_end = n - 1;
    int col_start = 0, col_end = n - 1;

    while (row_start <= row_end && col_start <= col_end) {
        
        for (int i = col_start; i <= col_end; i++) {
            matrix[row_start][i] = num;
            num++;
        }
        row_start++;

        
        for (int i = row_start; i <= row_end; i++) {
            matrix[i][col_end] = num;
            num++;
        }
        col_end--;

        
        if (row_start <= row_end) {
            for (int i = col_end; i >= col_start; i--) {
                matrix[row_end][i] = num;
                num++;
            }
            row_end--;
        }

        
        if (col_start <= col_end) {
            for (int i = row_end; i >= row_start; i--) {
                matrix[i][col_start] = num;
                num++;
            }
            col_start++;
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
