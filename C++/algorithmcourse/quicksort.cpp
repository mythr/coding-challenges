#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <cmath>

typedef typename std::vector<int>::iterator iterator;

int findMedian(int a, int b, int c)
{
	if(((b > a) && (b < c)) || ((b > c) && (b < a)))
		return b;
	else if(((c > a) && (c < b)) || ((c < a) && (c > b)))
		return c;
	else
		return a;
}

iterator partition(iterator l, iterator r)
{
	/*
	iterator middle = l;
	if(std::distance(l,r) % 2 != 0)
		middle += std::distance(l,r)/2;
	else
		middle += std::distance(l,r)/2 - 1;
	int a = *l;
	int b = *(r - 1);
	int c = *middle;
	int median = findMedian(a,b,c);
	if(median == c)
		std::swap(*l,*middle);
	else if(median == b)
		std::swap(*l,*(r - 1));
	*/
	// Using the last element as pivot.
	std::swap(*l,*(r-1));
	iterator i = l + 1;
	int p = *l;

	for(iterator j = l + 1; j < r; j++)
	{
		if(*j < p)
		{
			std::swap(*j, *i);
			i++;
		}
	}
	std::swap(*l,*(i-1));
	return i - 1;
}

int quicksort(iterator left, iterator right)
{
	int inversions = 0;
	if(std::distance(left,right) == 0)
		return 0;

	iterator newPivot = partition(left, right);

	iterator r = newPivot;
	iterator l = newPivot + 1;
	inversions += std::distance(left, r);
	inversions += std::distance(l,right);
	
	inversions += quicksort(left, r);
	inversions += quicksort(l, right);
	
	return inversions;
}

int main()
{
	std::vector<int> inputVec;
	//std::vector<int> test = {7,5,1,4,8,3,10,2,6,9};  
	std::fstream input;
	input.open("QuickSort.txt");
	int x;
	while(input >> x)
		inputVec.push_back(x);

	iterator left = inputVec.begin();
	iterator right = inputVec.end();
	int result = quicksort(left,right);
	for(int i : inputVec)
		std::cout << i << std::endl;
	std::cout << "Number of inversions: " << result << std::endl;
}