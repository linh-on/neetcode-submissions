class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> cols;
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> squares;

        for (int r = 0; r < 9; r++){
            for (int c = 0; c < 9; c++){

                char val = board[r][c];
                if (val == '.') continue;

                int box = (c / 3) * 3 + (r / 3); // label box from 1 to 8

                if (rows[r].count(val) || cols[c].count(val) || squares[box].count(val))
                    return false;

                rows[r].insert(val);
                cols[c].insert(val);
                squares[box].insert(val);

        }
        

        
        }
        return true;
    }
};
