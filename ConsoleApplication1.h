#pragma once

void InitializeTheSizeOfArray(int& sizeOfArray);

void InitializeTheElementsOfArray(int& input, std::unique_ptr<int[]>& array, int& index, int& counter, int sizeOfArray);

void FindPeakElements(std::unique_ptr<int[]>& array, size_t i);

static bool CheckHorizontally(const char  board[6][7], char player, bool& retFlag);

void WinMessage(int currentPlayer, bool& gameOver);

void DrawMessagge(bool& gameOver);

void CheckDrawCondition(char  board[6][7], bool& draw);

void TakeInputsFromPlayer(int currentPlayer, char  board[6][7], int& retFlag);

void InitializeTheBoard(char  board[6][7]);

static bool CheckVertically(const char  board[6][7], char player, bool& retFlag);

static bool CheckDiagonally(const char  board[6][7], char player, bool& retFlag);
