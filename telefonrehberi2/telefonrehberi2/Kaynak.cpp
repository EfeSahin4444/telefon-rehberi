#include "Üst Bilgi.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	TelephoneGuide* guide = new TelephoneGuide();
	int selection;



	while (true) {
		cout << endl;
		cout << endl;
		cout << "          TELEPHONE GUIDE LÝST" << endl;
		if (guide->isEmpty() == true) {
			cout << "List is empty if you want to add new number you can check operator list" << endl;
		}
		else {
			guide->printAll();
		}
		cout << "         OPERATOR LÝST" << endl;
		cout << "1.Add new number" << endl;
		cout << "2.erase number" << endl;
		cout << "3.call number" << endl;
		cout << "want do you want to do interval this operations:";
		cin >> selection;
		switch (selection) {
		case 1:
			cin.ignore();
			int choice;
			cout << "you can select index for inserting the number interval 0 to " << guide->getCount() << ":" << endl;
			cin >> choice;
			if (choice >= 0 && choice <= guide->getCount()) {
				cin.ignore();

				cout << "select telephone number for register:";

				int numbers;
				cin >> numbers;
				cin.ignore();
				string name;
				cout << "enter the owner name ";

				getline(cin, name);
				guide->insertNode(choice, numbers, name);
			}
			break;
		case 2:
			cin.ignore();
			cout << "you can select index for erasing the number interval 0 to " << guide->getCount() - 1 << ":" << endl;
			int choice1;
			cin >> choice1;
			if (choice1 >= 0 && choice1 <= guide->getCount() - 1) {
				guide->deleteNode(choice1);
			}
			cin.ignore();
			break;
		case 3:
			cout << "number is being called" << endl;
			break;
		default:
			cout << "there is not like this operations" << endl;
			break;
		}

	}
}