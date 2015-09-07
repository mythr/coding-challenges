#include <iostream>
#include <vector>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

int countDecimalPoints(double num){
	int count = 0;
	num = num - (int) num;
	while(num >= .000001){
		num *= 10;
		count++;
		num -= int(num);
		cout << num << endl;
	}
	return count;
}

int main(){
	int k, j, dig;
	string digits;
	int p, q;
	int run = 1;
	while(cin >> j){
		double num = 0.0F;
		cin >> digits;
		digits.erase(digits.find('.'),1);
		digits.erase(0,1);
		k = digits.size() - j;
		for(int i = 0; i < digits.size(); i++){
			num += pow(10,-(i+1))*(int)digits[i];
		}
		p = pow(10,k+j)*num - pow(10,k)*num;
		q = pow(10,k+j) - pow(10,k);
		cout << "Case " << run << ": " << p << "/" << q << endl;

	}
}