//Emma Dreier 10/2/21 This program is meant to store student registration data in a file.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int getTuition(int& count, string& campus);

void main()
{
	char start, again, another;
	int number, count, tuition;
	string fn, ln, campus, course1, course2, course3, course4, sp;

	cout << "This program allows the user to input at least one student record and save that data to a file. Would you like to proceed? (y/n): ";
	cin >> start;

	if (start == 'Y' || start == 'y')
	{
		ofstream DataFile;

		DataFile.open("cop2224_proj1.txt");

		do
		{
			cout << "Firstly, enter the student number: ";
			cin >> number;

			cin.ignore();

			while (number > 999999 || number < 100000)
			{
				cout << "Error! The student number should be a six digit number. Please enter it again: ";
				cin >> number;

				cin.ignore();
			}

			cout << "Enter the student's first name: ";
			getline(cin, fn);

			cin.ignore();

			cout << "Enter the student's last name: ";
			getline(cin, ln);

			cin.ignore();

			cout << "Choose a campus.\n";
			cout << "1. North Campus\n";
			cout << "2. South Campus\n";
			cout << "3. City Campus\n";
			cout << "4. Seaside Campus\n";
			cout << "Enter your choice (1-4): ";
			cin >> campus;

			cin.ignore();

			while (campus != "1" && campus != "2" && campus != "3" && campus != "4")
			{
				cout << "Error! An invalid value was entered. Please try again.\n";
				cout << "1. North Campus\n";
				cout << "2. South Campus\n";
				cout << "3. City Campus\n";
				cout << "4. Seaside Campus\n";
				cout << "Enter your choice (1-4): ";
				cin >> campus;

				cin.ignore();
			}

			if (campus == "1")
				campus = "North";

			else if (campus == "2")
				campus = "South";

			else if (campus == "3")
				campus = "City";

			else
				campus = "Seaside";

			cout << "Enter the course number of the class the student is registering for: ";
			getline(cin, course1);

			cin.ignore();
			
			while (course1 == "" || course1 == " ")
			{
				cout << "Error! Course number entered incorrectly. Please reenter the course number: ";
				getline(cin, course1);

				cin.ignore();
			}

			count = 1;

			cout << "Would you like to register for another class? (y/n): ";
			cin >> another;

			cin.ignore();

			if (another == 'y' || another == 'Y')
			{
				cout << "Enter the course number of the second class you would like to register for: ";
				getline(cin, course2);

				cin.ignore();

				while (course2 == "" || course2 == " ")
				{
					cout << "Error! Course number entered incorrectly. Please reenter the course number: ";
					getline(cin, course2);

					cin.ignore();
				}

				count++;

				cout << "Would you like to register for another class? (y/n): ";
				cin >> another;

				cin.ignore();

				if (another == 'y' || another == 'Y')
				{
					cout << "Enter the course number of the third class you would like to register for: ";
					getline(cin, course3);

					cin.ignore();

					while (course3 == "" || course3 == " ")
					{
						cout << "Error! Course number entered incorrectly. Please reenter the course number: ";
						getline(cin, course3);

						cin.ignore();
					}

					count++;

					cout << "Would you like to register for another class? (y/n): ";
					cin >> another;

					cin.ignore();

					if (another == 'y' || another == 'Y')
					{
						cout << "Enter the course number of the fourth class you would like to register for: ";
						getline(cin, course4);

						cin.ignore();

						while (course4 == "" || course4 == " ")
						{
							cout << "Error! Course number entered incorrectly. Please reenter the course number: ";
							getline(cin, course4);

							cin.ignore();
						}

						count++;
					}
					else
					{
						course4 = " ";
					}
				}
				else
				{
					course3 = " ";

					course4 = " ";
				}
			}
			else
			{
				course2 = " ";

				course3 = " ";

				course4 = " ";
			}

			cout << "Is the student classified as a senior? (y/n): ";
			cin >> sp;

			cin.ignore();

			while (sp != "y" && sp != "Y" && sp != "n" && sp != "N")
			{
				cout << "Error! An invalid value was entered. Please try again.\n";
				cout << "Is the student classified as a senior? (y/n): ";
				cin >> sp;

				cin.ignore();
			}

			if (sp == "y"|| sp == "Y")
				sp = "Y";
			else
				sp == "N";

			tuition = getTuition(count, campus);

			DataFile << number << ", " << fn << ", " << ln << ", " << campus << ", " << course1 << ", " << course2 << ", " << course3 << ", " << course4 << ", " << sp << ", " << tuition << endl;

			cout << "Data saved. Would you like add another student record? (y/n): ";
			cin >> again;

			cin.ignore();

		} while (again == 'Y' || again == 'y');

		DataFile.close();

		cout << "You have to decided to quit the program.\n";
	}
	else
	{
		cout << "You have to decided to quit the program.\n";
	}

	system("pause");
}

int getTuition(int& count, string& campus)
{
	int costper;

	if (campus == "North")
		costper = 510;

	else if (campus == "South")
		costper = 500;

	else if (campus == "City")
		costper = 525;

	else
		costper = 550;

	return count * costper;
}