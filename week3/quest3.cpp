#include<iostream>

using namespace std;

int main() {
	int input;
	cin >> input;

	for (int i = 0; i < input * 2-1; i++) {
		if (i < input) {
			for (int j = 0; j < input - i - 1; j++) {
				cout << " ";
			}
			cout << "*";
			for (int k = 0; k < i * 2 - 1; k++) {
				cout << " ";
			}
		}
		else {
			for (int j =0; j <i-input+1  ;j++) {
				cout << " ";
			}
			cout << "*";
			for (int k = 0; k < ((input-1)*2-1)-((i-input+1)*2); k++) {
				cout << " ";
			}
		}
		if (i != 0 && i != input * 2 - 2) {
			cout << "*";
		}
		cout << "\n";
	}
}