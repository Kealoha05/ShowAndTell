//Emma Dreier 11/21/21 Project 2

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Revenue
{
private: //variables
	static int divnum, quarter;
	string divname, divid, company;
	int empnum;
	double sales, costs;
public:
	Revenue(int q, string dn, string did, string comp, int en, double s, double c) //constructors
	{
		quarter = q;
		divname = dn;
		divid = did;
		company = comp;
		empnum = en;
		sales = s;
		costs = c;
	}
	Revenue()
	{
		divname = " ";
		divid = "0000";
		company = "National";
		empnum = 0;
		sales = 0;
		costs = 0;
	}
	void setDivNum(int dn) { divnum = dn; } //setters
	void setQuarter(int q) { quarter = q; }
	void setDivName(string dn) { divname = dn; }
	void setDivID(string did){ divid = did;	}
	void setCompany(string comp) { company = comp; }
	void setEmpNum(int en) { empnum = en; }
	void setSales(double s) { sales = s; }
	void setCosts(double c) { costs = c; }

	int getDivNum() { return divnum; } //getters
	int getQuarter() { return quarter; }
	string getDivName() { return divname; }
	string getDivID() { return divid; }
	string getCompany() { return company; }
	int getEmpNum() { return empnum; }
	double getSales() { return sales; }
	double getCosts() { return costs; }
	double getProfit() { return sales - costs; }
	double getEmpCost() { return costs / empnum; }
};

int Revenue::divnum, Revenue::quarter;

void main()
{
	char choice, again;
	int recnum, quarter, count = 0, empnum, company;
	string name, id;
	double sales, costs;

	cout << "This program accepts the revenue records from the user for any number of divisions and saves them to an XML file. Would you like to proceed? (y/n): ";
	cin >> choice;

	if (choice == 'y' || choice == 'Y')
	{
		cout << "Enter the number of records you would like to input: ";
		cin >> recnum;

		cout << "Enter the quarter for which these records apply (1-4): ";
		cin >> quarter;

		while (quarter != 1 && quarter != 2 && quarter != 3 && quarter != 4)
		{
			cout << "Error! An invalid value was entered. Please enter a number between 1-4 to represent a fiscal quarter: ";
			cin >> quarter;
		}

		Revenue* ptr = new Revenue[recnum];

		do
		{
			cout << "Enter the name of the division: ";
			cin.ignore();
			getline(cin, name);
			ptr[count].setDivName(name);

			cout << "Enter the ID number of the division: ";
			getline(cin, id);
			
			while (id.size() != 4)
			{
				cout << "Error! Division ID must be 4 digits long. Please reenter the ID: ";
				getline(cin, id);
			}

			ptr[count].setDivID(id);

			cout << "Companies:\n1. National\n2. European\n3. Pacific\n4. Asia\nEnter which company corresponds with this division (1-4): ";
			cin >> company;

			while (company != 1 && company != 2 && company != 3 && company != 4)
			{
				cout << "Error! An invalid value was entered. Please enter a number between 1-4 based on which company you would like: ";
				cin >> company;
			}
			
			if (company == 1)
			{
				ptr[count].setCompany("National");
			}
			else if (company == 2)
			{
				ptr[count].setCompany("European");
			}
			else if (company == 3)
			{
				ptr[count].setCompany("Pacific");
			}
			else
			{
				ptr[count].setCompany("Asia");
			}

			cout << "Enter the number of employees: ";
			cin >> empnum;
			ptr[count].setEmpNum(empnum);

			cout << "Enter the sales of the division: ";
			cin >> sales;
			ptr[count].setSales(sales);

			cout << "Enter the costs of the division: ";
			cin >> costs;
			ptr[count].setCosts(costs);
	
			count += 1;

			cout << "Would you like to enter another record? (y/n): ";
			cin >> again;

		} while ((again == 'y' || again == 'Y') && count < recnum);

		if (count == recnum)
			cout << "You have entered the number of records previously specified. The data will now be written to an XML file and the program closed.\n";
		else
			cout << "You have chosen to exit the program. The data will now be written to an XML file and the program closed.\n";

		ptr[0].setDivNum(count);
		ptr[0].setQuarter(quarter);

		fstream DivisionRevenue;
		DivisionRevenue.open("cop2224_proj2.xml");

		DivisionRevenue << "<revenue>\n";
		
		for (int x = 0; x < count+1; x++)
		{
			DivisionRevenue << fixed << setprecision(5) << "<division>\n";
			DivisionRevenue << fixed << setprecision(10) << "<DivisionName>" << ptr[x].getDivName() << "</DivisionName>\n";
			DivisionRevenue << fixed << setprecision(10) << "<DivisionNumber>" << ptr[x].getDivID() << "</DivisionNumber>\n";
			DivisionRevenue << fixed << setprecision(10) << "<Company>" << ptr[x].getCompany() << "</Company>\n";
			DivisionRevenue << fixed << setprecision(10) << "<NumberofEmployees>" << ptr[x].getEmpNum() << "<\numberofEmployees>\n";
			DivisionRevenue << fixed << setprecision(10) << "<TotalSales>" << ptr[x].getSales() << "</TotalSales>\n";
			DivisionRevenue << fixed << setprecision(10) << "<TotalCosts>" << ptr[x].getCosts() << "</Costs>\n";
			DivisionRevenue << fixed << setprecision(10) << "<Profit>" << ptr[x].getProfit() << "</Profit>\n";
			DivisionRevenue << fixed << setprecision(10) << "<CostPerEmployee>" << ptr[x].getEmpCost() << "</CostPerEmployee>\n";
			DivisionRevenue << fixed << setprecision(5) << "</division>\n";
		}

		DivisionRevenue << fixed << setprecision(5) << "<Quarter>" << ptr[0].getQuarter() << "</Quarter>\n";
		DivisionRevenue << fixed << setprecision(5) << "<TotalDivisions>" << ptr[0].getDivNum() << "</TotalDivisions>\n";
		DivisionRevenue << "</revenue>\n";

		DivisionRevenue.close();

		delete[] ptr;
	}
	else
		cout << "You have chosen to exit the program." << endl;

	system("pause");
}