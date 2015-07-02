#include <vector>
#include <iostream>

typedef typename std::vector<int>::iterator vecit;

int merge(vecit arr_start, vecit arr_end, vecit left_start, vecit left_end, vecit right_start, vecit right_end)
{
	int inversions = 0;
	while(arr_start != arr_end)
	{
		while(left_start != left_end and right_start != right_end)
		{
			if(*left_start < *right_start)
			{
				*arr_start = *left_start;
				arr_start++;
				left_start++;
			}
			else if(*right_start < *left_start)
			{
				*arr_start = *right_start;
				arr_start++;
				right_start++;
				inversions++;
			}
		}
		while(left_start != left_end)
		{
			*arr_start = *left_start;
			arr_start ++;
			left_start++;
		}
		while(right_start != right_end)
		{
			*arr_start = *right_start;
			arr_start++;
			right_start++;
		}
	}
	return inversions;
}

int mergesort(std::vector<int>& vec)
{
	int inversions = 0;
	
	if(vec.size() == 1)
		return 0;

	vecit middle = vec.begin() + vec.size()/2;
	std::vector<int> left(vec.begin(), middle);
	std::vector<int> right(middle, vec.end());

	inversions += mergesort(left);
	inversions += mergesort(right);
	inversions += merge(vec.begin(), vec.end(), left.begin(), left.end(), right.begin(), right.end());

	return inversions;
}

int main()
{
	std::vector<int> input = {1, 4, 20  , 3, 5};
	std::cout << "Sorting ";
	for(int i : input)
		std::cout << i << " ";
	std::cout << std::endl;
	int inversions = mergesort(input);
	std::cout << "\nResult: ";
	for(int i : input)
		std::cout << i << " ";
	std::cout << std::endl;
	std::cout << "Number of inversions is: " << inversions << std::endl;

	return 0;
}