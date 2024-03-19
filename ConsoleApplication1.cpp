#include <iostream>
#include "ConsoleApplication1.h"

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

// Function to initialize game board
void InitializeTheBoard(char  board[6][7])
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            board[i][j] = '-';
        }
    }
}

// Function to take input from Player
void TakeInputsFromPlayer(int currentPlayer, char  board[6][7], int& retFlag)
{
    retFlag = 1;
    std::cout << "Player " << currentPlayer << "'s turn. Enter number of column (from 1 to 7): ";
    int column{};
    std::cin >> column;
    column--;

    // Check if the column is valid and not full
    if (column < 0 || column >= columns || board[0][column] != '-') {
        std::cout << "Invalid move! Try again." << std::endl;
        { retFlag = 3; return; };
    }

    // Find the lowest empty row in the selected column
    int row{};
    for (row = rows - 1; row >= 0; --row) {
        if (board[row][column] == '-') {
            board[row][column] = (currentPlayer == 1) ? 'R' : 'B';
            break;
        }
    }
}

// Function to control win condition
static bool checkWinCondition(const char board[rows][columns], char player) {
    // Check for horizontal
    bool retFlag;
    bool retVal = CheckHorizontally(board, player, retFlag);
    if (retFlag) return retVal;

    // Check for vertical
    bool retFlag;
    bool retVal = CheckVertically(board, player, retFlag);
    if (retFlag) return retVal;

    // Check for diagonal
    bool retFlag;
    bool retVal = CheckDiagonally(board, player, retFlag);
    if (retFlag) return retVal;

    return false;
}

// Function to control draw condition
void CheckDrawCondition(char  board[6][7], bool& draw)
{
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (board[i][j] == '-') {
                draw = false;
                break;
            }
        }

        if (!draw) break;
    }
}

// Function to control 4 in a row diagonally
bool CheckDiagonally(const char  board[6][7], char player, bool& retFlag)
{
    retFlag = true;
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
    retFlag = false;
    return {};
}

// Function to control 4 in a row vertically
bool CheckVertically(const char  board[6][7], char player, bool& retFlag)
{
    retFlag = true;
    for (int j = 0; j < columns; ++j) {
        for (int i = 0; i <= rows - 4; ++i) {
            if (board[i][j] == player && board[i + 1][j] == player &&
                board[i + 2][j] == player && board[i + 3][j] == player) {
                return true;
            }
        }
    }
    retFlag = false;
    return {};
}

// Function to control 4 in a row horizontally
bool CheckHorizontally(const char  board[6][7], char player, bool& retFlag)
{
    retFlag = true;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j <= columns - 4; ++j) {
            if (board[i][j] == player && board[i][j + 1] == player &&
                board[i][j + 2] == player && board[i][j + 3] == player) {
                return true;
            }
        }
    }
    retFlag = false;
    return {};
}

// Function to print win messagge
void WinMessage(int currentPlayer, bool& gameOver)
{
    std::cout << "Player " << currentPlayer << " wins!" << std::endl;
    std::cout << "Thanks for playing!" << std::endl;
    gameOver = true;
}

// Function to print draw messagge
void DrawMessagge(bool& gameOver)
{
    std::cout << "It's a draw!" << std::endl;
    gameOver = true;
}

int main() {
    char board[rows][columns]{};

    // Initialize the board with '-'
    InitializeTheBoard(board);

    int currentPlayer = 1;
    bool gameOver = false;

    while (!gameOver) {
        printBoard(board);

        int retFlag{};
        TakeInputsFromPlayer(currentPlayer, board, retFlag);
        if (retFlag == 3) 
            continue;

        // Check for a win
        if (checkWinCondition(board, (currentPlayer == 1) ? 'R' : 'B')) {
            printBoard(board);
            WinMessage(currentPlayer, gameOver);
        }
        else {
            // Check for a draw
            bool draw = true;
            CheckDrawCondition(board, draw);

            if (draw) {
                printBoard(board);
                DrawMessagge(gameOver);
            }
            else {
                // Switch player
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
            }
        }
    }

    return 0;
}