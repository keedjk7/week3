#include<iostream>
#include<string>
#include<ctype.h>
#include<algorithm>

using namespace std;

int main() {
	int num_fruit_stock;
	int week,K;
	bool check = false;

	//Stock
	cout<<"> IN STOCK <\n\n"<<"Number type fruit : ";
	cin >> num_fruit_stock;

	string name_fruit_stock[100];
	int stock[100] = { 0 };		
	
	cout << "Number of Import week : ";
	cin>> week;

	for (int i = 0; i < num_fruit_stock; i++) {
		cout << "Name of the fruit in stock "<<i+1<<": ";
		cin >> name_fruit_stock[i];
		std::for_each(name_fruit_stock[i].begin(), name_fruit_stock[i].end(), [](char& c) {
			c = ::tolower(c);
		});

		for (int j = 0; j < week; j++) {
			cout << "Import Week " << j + 1 << " (KG) : ";
			cin >> K;
			stock[i] += K;
		}
	}

	//Order
	int num_fruit_order;

	cout << "\n\n> ORDER <\n\n"<<"Number type of fruit : " ;
	cin >> num_fruit_order;

	string name_fruit_order[100];
	int order[100];

	for (int i = 0; i < num_fruit_order; i++) {
		cout << "Name of the fruit to order " << i + 1 << ": ";
		cin >> name_fruit_order[i];
		std::for_each(name_fruit_order[i].begin(), name_fruit_order[i].end(), [](char& c) {
			c = ::tolower(c);
			});
		cout << "Buy (KG) : ";
		cin >> order[i];
	}

	//After
	cout << "\n\n> After order in stock <\n\n";
	for (int i = 0; i < num_fruit_order; i++) {
		check = false;
		for (int j = 0; j<num_fruit_stock; j++) {
			if (name_fruit_stock[j].compare(name_fruit_order[i]) == 0 && check == false&&stock[j]!=0&&order[i]!=0) {
				if (stock[j] >= order[i]) {
					cout <<"Order "<<i+1<<" : "<<name_fruit_order[i] << "   --->   Can be sold according to your order "<<order[i]<<" KG\n";
					stock[j] -= order[i];
				}
				else  {
					cout <<"Order "<<i+1<<" : "<< name_fruit_order[i] << "   --->   There isn't enough for your order to be able to sell for just " <<stock[j]<<" KG\n";
					stock[j] = 0;
				}
				check = true;
			}
		}
		if (check == false) {
			cout <<"Order "<<i+1<<" : "<< name_fruit_order[i] << "   --->   This product is not available in stock\n";
		}
	}
	return 0;
}
