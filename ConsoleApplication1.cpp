#include <iostream>

const int rows = 6;
const int columns = 7;

// Function to print game board
static void printBoard(const char board[rows][columns]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << board[i][j] << " ";
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;
}

// Function to control the win condition
static bool checkWin(const char board[rows][columns], char player) {
    // Check for horizontal
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= columns - 4; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }

    // Check for vertical
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i <= rows - 4; ++i) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Check for diagonal
    for (int i = 0; i <= rows - 4; ++i) {
        for (int j = 0; j <= columns - 4; ++j) {
            if (board[i][j] == player && board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
                return true;
            }
            if (board[i][j + 3] == player && board[i + 1][j + 2] == player &&
                board[i + 2][j + 1] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    char board[rows][columns]{};

    // Initialize the board with '-'
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            board[i][j] = '-';
        }
    }

    int currentPlayer = 1;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);
        std::cout << "Player " << currentPlayer << "'s turn. Enter number of column (from 1 to 7): ";
        int column{};
        std::cin >> column;
        column--;

        // Check if the column is valid and not full
        if (column < 0 || column >= columns || board[0][column] != '-') {
            std::cout << "Invalid move! Try again." << std::endl;
            continue;
        }

        // Find the lowest empty row in the selected column
        int row{};
        for (row = rows - 1; row >= 0; --row) {
            if (board[row][column] == '-') {
                board[row][column] = (currentPlayer == 1) ? 'R' : 'B';
                break;
            }
        }

        // Check for a win
        if (checkWin(board, (currentPlayer == 1) ? 'R' : 'B')) {
            printBoard(board);
            std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            std::cout << "Thanks for playing!" << std::endl;
            gameOver = true;
        }
        else {
            // Check for a draw
            bool draw = true;
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < columns; ++j) {
                    if (board[i][j] == '-') {
                        draw = false;
                        break;
                    }
                }

                if (!draw) break;
            }

            if (draw) {
                printBoard(board);
                std::cout << "It's a draw!" << std::endl;
                gameOver = true;
            }
            else {
                // Switch player
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        }
    }

    return 0;
}