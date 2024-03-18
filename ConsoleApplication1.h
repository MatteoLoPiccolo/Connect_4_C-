#pragma once

void InitializeTheSizeOfArray(int& sizeOfArray);

void InitializeTheElementsOfArray(int& input, std::unique_ptr<int[]>& array, int& index, int& counter, int sizeOfArray);

void FindPeakElements(std::unique_ptr<int[]>& array, size_t i);
