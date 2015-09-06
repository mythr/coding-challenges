#include <iostream>
#include <vector>

using namespace std;


int main(){
	vector<pair<int,int> > spendings;
	int n;
	while(cin >> n){
		if(n == 0)
			break;
		int dollar, cent = 0;
		int firstDig, secondDig;
		for(int i = 0; i < n; i++){
			cin.get(firstDig);
			cin.get(secondDig);
			dollar = firstDig * 10 + secondDig;
			cin.ignore()
			cin.get(firstDig);
			cin.get(secondDig);
			cent = firstDig * 10 + secondDig;
			spendings.push_back(pair<int,int>(dollar, cent));
		}
		int totalDollars, totalCents = 0;
		for(pair<int,int> p : spendings){
			totalDollars += p.first;
			totalCents += p.second;
		}
		totalDollars += totalCents % 100;
		totalCents = totalCents / 100;
		int centsPer = totalCents / n;
		int dollarsPer = totalDollars / n + centsPer % 100;
		centsPer = centsPer / 100;
		int total = 0;
		for(pair<int,int> p : spendings){
			p.first -= dollarsPer;
			if(p.second - centsPer < 0){
				p.first--;
				p.second = 100 - p.second - centsPer;
			}
			else{
				p.second -= centsPer;
			}
		}
		

	}

	return 0;
}