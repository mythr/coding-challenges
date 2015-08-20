#include <vector>
#include <iostream>
#include <fstream>

typedef typename std::vector<int>::iterator vecit;

long long int merge(vecit arr_start, vecit arr_end, vecit left_start, vecit left_end, vecit right_start, vecit right_end)
{
	static int counter = 0;
	long long int inversions = 0;
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
				inversions += left_end - left_start;
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
	//std::cout << "Number of inversions at count " << counter << " is: " << inversions << std::endl;
	counter++;
	return inversions;
}

long long int count_inversions(std::vector<int>& vec)
{
	long long int inversions = 0;
	
	if(vec.size() == 1)
		return 0;

	vecit middle = vec.begin() + vec.size()/2;
	std::vector<int> left(vec.begin(), middle);
	std::vector<int> right(middle, vec.end());

	inversions += count_inversions(left);
	inversions += count_inversions(right);
	inversions += merge(vec.begin(), vec.end(), left.begin(), left.end(), right.begin(), right.end());
	return inversions;
}

int main()
{
	int num = 0;
	long long int inversions = 0;
	std::vector<int> input_vec;
	std::ifstream input_file ("IntegerArray.txt");
	if(input_file.is_open())
	{
		while(input_file >> num)
		{
			input_vec.push_back(num);
		}
	}
	else std::cout << "Unable to open file.\n";

	inversions = count_inversions(input_vec);
	std::cout << inversions << '\n';

	return 0;
}