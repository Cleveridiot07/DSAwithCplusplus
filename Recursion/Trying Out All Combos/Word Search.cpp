#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    bool helper(vector<vector<char>>& board, string &word, int i, int j, int wi) {
        if (wi >= word.size()) return true; // Word is found
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return false; // Out of bounds
        if (board[i][j] != word[wi]) return false; // Mismatch in character

        char original = board[i][j]; // Save original character
        board[i][j] = '*'; // Mark as visited

        // Explore all directions
        bool up = helper(board, word, i - 1, j, wi + 1);
        bool left = helper(board, word, i, j - 1, wi + 1);
        bool down = helper(board, word, i + 1, j, wi + 1);
        bool right = helper(board, word, i, j + 1, wi + 1);

        board[i][j] = original; // Backtrack to restore the original character
        return up || left || down || right;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) { // Start search if the first character matches
                    if (helper(board, word, i, j, 0)) return true;
                }
            }
        }
        return false; // Word not found
    }
};

// Main Function
int main() {
    Solution solution;

    // Test case
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";

    if (solution.exist(board, word)) {
        cout << "The word \"" << word << "\" exists in the board." << endl;
    } else {
        cout << "The word \"" << word << "\" does not exist in the board." << endl;
    }

    return 0;
}
