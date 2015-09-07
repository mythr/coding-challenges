#include <vector>
#include <iostream>
#include <string>

using namespace std;

const string undetermined = "UNDETERMINED";

struct Car{
	int low, high;
	string name;
	Car(int l, int h, string n) : low(l), high(h), name(n){}
};

int main(){
	int testcases, q;
	long int d,p;
	cin >> testcases;
	vector<Car> cars;
	for(int k = 0; k < testcases; k++){
		cars.clear();
		cin >> d;
		for(int i = 0; i < d; i++){
			string carName;
			long int low, high;
			cin >> carName >> low >> high;
			cars.push_back(Car(low,high,carName));
		}
		cin >> q;
		for(int i = 0; i < q; i++){
			string out = undetermined;
			cin >> p;
			bool carFound = false;
			for(Car c : cars){
				if(p <= c.high && p >= c.low){
					if(carFound){
						out = undetermined;
					}
					else{
						out = c.name;
						carFound = true;
					}
				}
			}
			cout << out << endl;
			p = 0;
		}
		if(k != testcases - 1)
			cout << endl;
	}

	return 0;
}