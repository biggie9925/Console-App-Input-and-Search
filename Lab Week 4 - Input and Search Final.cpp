// Lab Week 4 - Input and Search Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

void addContact() {

	ofstream contactsFile("clients.txt", ios::app);

	string fname;
	string lname;
	string address;
	string phone;

	cout << "\n\tEnter First Name : ";
	cin >> fname;
	cin.ignore();
	cout << "\tEnter Last Name : ";
	getline(cin, lname);
	cout << "\tEnter Address : ";
	getline(cin, address);
	cout << "\tEnter Phone Number : ";
	getline(cin, phone);

	if (contactsFile.is_open()) {
		contactsFile << fname << " " << lname << " " << address << " " << phone << endl;
		cout << "\n\tContact saved successfully" << endl << endl;
	}

	contactsFile.close();
}

void searchContact() {

	ifstream contactsFile("clients.txt");

	string firstWord;
	string fname;
	string lname;
	string address;
	string phone;
	string keyword;
	string line;
	bool match = false;

	cout << "\n\tPlease enter the name you would like to search for: ";
	cin >> keyword;
	cin.ignore();

	if (contactsFile.is_open()) {
		while (contactsFile >> firstWord) {
			getline(contactsFile, line);
			if (firstWord == keyword) {
				cout << "\n\tContact details: " << firstWord << line;
				match = true;
			}
		}
		if (match != true) {
			cout << "\n\tNo results found";
		}
		cout << endl << endl;
	}

	contactsFile.close();

}

int main()
{
	int option;
	bool loop = true;

	while (loop) {
		cout << "Welcome to Contacts List:\n\n";
		cout << "\t1. Add contact to file\n";
		cout << "\t2. Search contact in file\n";
		cout << "\t3. Quit\n\n";
		cout << "Please select an option from the menu: ";
		cin >> option;

		if (cin.fail())
		{
			cout << "\nIncorrect input, please try again\n\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		else if (option == 1) {
			addContact();
		}

		else if (option == 2) {
			searchContact();
		}

		else if (option == 3) {
			cout << "\nExiting the search program...";
			break;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
