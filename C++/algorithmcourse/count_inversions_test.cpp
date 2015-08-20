#include <iostream>
#include "count_inversions.cpp"


int main()
{
	std::vector<int> first = {1, 2, 3, 4, 6, 5};
	std::vector<int> second = {1, 2, 3, 4, 5};
	std::vector<int> third = {3, 1, 2, 20, 5};
	std::vector<int> fourth = {3, 2, 55, 151, 12, 4, 9119, 1, 7};
	std::vector<int> fifth = { 4, 80, 70, 23, 9, 60, 68, 27, 66, 78, 12, 40, 52, 53, 44, 8, 49, 28, 18, 46, 21, 39, 51, 7, 87, 99, 69, 62, 84, 6, 79, 67, 14, 98, 83, 0, 96, 5, 82, 10, 26, 48, 3, 2, 15, 92, 11, 55, 63, 97, 43, 45, 81, 42, 95, 20, 25, 74, 24, 72, 91, 35, 86, 19, 75, 58, 71, 47, 76, 59, 64, 93, 17, 50, 56, 94, 90, 89, 32, 37, 34, 65, 1, 73, 41, 36, 57, 77, 30, 22, 13, 29, 38, 16, 88, 61, 31, 85, 33, 54 };
	std::vector<int> sixth = { 37, 7, 2, 14, 35, 47, 10, 24, 44, 17, 34, 11, 16, 48, 1, 39, 6, 33, 43, 26, 40, 4, 28, 5, 38, 41, 42, 12, 13, 21, 29, 18, 3, 19, 0, 32, 46, 27, 31, 25, 15, 36, 20, 8, 9, 49, 22, 23, 30, 45 };

	if (count_inversions(first) == 1)
		std::cout << "First is ok!\n";
	if (count_inversions(second) == 0)
		std::cout << "Second is ok!\n";
	if (count_inversions(third) == 3)
		std::cout << "Third is ok!\n";
	if (count_inversions(fourth) == 17)
		std::cout << "Fourth is ok!\n";
	if (count_inversions(fifth) == 2372)
		std::cout << "Fifth is ok!\n";
	if (count_inversions(sixth) == 590)
		std::cout << "Sixth is ok!\n";
	return 0;
}