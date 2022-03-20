#include <iostream>
#include <vector>
using namespace std;
namespace ariel
{
    string mat(int col, int row, char first, char second)
    {
        int x = row;
        int y = col;
        int flag = 1;
        int r = 0;
        int c = 0;
        int i = 0;
        string ans;
        /* explanation about the paramaters in order to make it clear for us:
        c - the starting column index (we will use it to move forward in the matrix).
        col - the ending column indx (given to us from the user).
        r - the starting row index (we will use it to move forward in the matrix).
        row - the ending row index (given to us from the user).
        ** the row and the col index must be odd by definition.
        */
        if (row <= 0 || col <= 0 || row % 2 == 0 || col % 2 == 0)
        { /* not a valid code*/
            throw runtime_error("mat size is allways odd");
        }
        if (first == '\t' || first == '\n' || first == '\r' || first == ' ')
        { /* not a valid char*/
            throw runtime_error("not a valid char");
        }

        if (second == '\t' || second == '\n' || second == '\r' || second == ' ')
        { /* not a valid char*/
            throw runtime_error("not a valid char");
        }
        vector<vector<char>> matrix(row, vector<char>(col));
        // char matrix[row][col];

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                matrix[i][j] = ' ';
            }
        }

        /* while we didn't reach to the middle of the mat */
        while (r < row && c < col)
        {

            /* Print the first row from the remaining rows */
            for (i = c; i < col; i++)
            {
                if (flag == 1)
                {
                    matrix[r][i] = first;
                }
                else
                {
                    matrix[r][i] = second;
                }
            }
            r++; /* we add to the starting row index in order to make it's range smaller - we don't
            want to reapet this row */

            /* print the last column from the remaining columns */
            for (i = r; i < row; i++)
            {
                if (flag == 1)
                {
                    matrix[i][col - 1] = first;
                }
                else
                {
                    matrix[i][col - 1] = second;
                }
            }
            col--; /* we reduce from the ending column index in order to make it's range smaller - we don't
            want to reapet this column */

            /* Print the last row from the remaining rows */
            for (i = col - 1; i >= c; i--)
            {
                if (flag == 1)
                {
                    matrix[row - 1][i] = first;
                }
                else
                {
                    matrix[row - 1][i] = second;
                }
            }
            row--; /* we reduce from the ending row index in order to make it's range smaller - we don't
            want to reapet this row */

            /* Print the first column from the remaining columns */
            for (i = row - 1; i >= r; i--)
            {
                if (flag == 1)
                {
                    matrix[i][c] = first;
                }
                else
                {
                    matrix[i][c] = second;
                }
            }
            flag = flag * -1;
            c++; /* we add to the starting column index in order to make it's range smaller - we don't
            want to reapet this column */
        }

        for (i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                ans += matrix[i][j];
            }
            ans += '\n';
        }
        return ans;
    }
}