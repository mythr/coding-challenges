#include <iostream>
#include <vector>
#include <fstream>


long long int count_inversions(std::vector<int>& vec)
{
	long long int inversions = 0;

	for(int i = 0; i < vec.size() - 1; i++)
	{
		for(int j = i + 1; j < vec.size(); j++)
		{
			if(vec.at(i) > vec.at(j))
				inversions++;
		}
	}
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