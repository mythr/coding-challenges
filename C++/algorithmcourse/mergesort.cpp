#include <vector>
#include <iostream>

typedef typename std::vector<int>::iterator vecit;

void merge(vecit arr_start, vecit arr_end, vecit left_start, vecit left_end, vecit right_start, vecit right_end)
{
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
}

void mergesort(std::vector<int>& vec)
{
	
	if(vec.size() == 1)
		return;

	vecit middle = vec.begin() + vec.size()/2;
	std::vector<int> left(vec.begin(), middle);
	std::vector<int> right(middle, vec.end());
	mergesort(left);
	mergesort(right);
	merge(vec.begin(), vec.end(), left.begin(), left.end(), right.begin(), right.end());

	std::cout << "After merge: ";
	for(int i : vec)
		std::cout << i << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> input = {1, 4, 20  , 3, 5};
	std::cout << "Sorting ";
	for(int i : input)
		std::cout << i << " ";
	std::cout << std::endl;
	mergesort(input);
	std::cout << "\nResult: ";
	for(int i : input)
		std::cout << i << " ";
	std::cout << std::endl;

	return 0;
}