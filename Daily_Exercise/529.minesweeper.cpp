/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution
{
public:
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> click)
    {
        int row = click[0];
        int col = click[1];
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || (board[row][col] != 'E' && board[row][col]!='M'))
            return board;
        if (board[row][col] == 'M')
        {
            board[row][col] = 'X';
            return board;
        }

        int count = count_adj(board, row, col);
        if (count > 0)
        {
            board[row][col] = '0' + count;
            return board;
        }
        else
        {
            board[row][col] = 'B';
            click[0] = row - 1;
            click[1] = col - 1;
            updateBoard(board, click);
            click[1] = col;
            updateBoard(board, click);
            click[1] = col + 1;
            updateBoard(board, click);
            click[0] = row;
            click[1] = col - 1;
            updateBoard(board, click);
            click[1] = col + 1;
            updateBoard(board, click);
            click[0] = row + 1;
            click[1] = col - 1;
            updateBoard(board, click);
            click[1] = col;
            updateBoard(board, click);
            click[1] = col + 1;
            updateBoard(board, click);
            return board;
        }
    }

    int count_adj(const vector<vector<char>> &board, int row, int col)
    {
        int count = 0;
        int row_up = (row - 1 >= 0);
        int row_down = (row + 1 <= board.size() - 1);
        int col_left = (col - 1 >= 0);
        int col_right = (col + 1 <= board[0].size() - 1);
        if (row_up)
        {
            if (col_left)
                count += (board[row - 1][col - 1] == 'M');
            count += (board[row - 1][col] == 'M');
            if (col_right)
                count += (board[row - 1][col + 1] == 'M');
        }
        if (col_left)
            count += (board[row][col - 1] == 'M');
        if (col_right)
            count += (board[row][col + 1] == 'M');
        if (row_down)
        {
            if (col_left)
                count += (board[row + 1][col - 1] == 'M');
            count += (board[row + 1][col] == 'M');
            if (col_right)
                count += (board[row + 1][col + 1] == 'M');
        }
        return count;
    }
};
// @lc code=end
