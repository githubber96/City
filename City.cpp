#include "City.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string in()
{
	string input;
	cin >> input;
	return input;
}
City::City()
{

}

string City::choseCity(string name)
{
	if (name == "Munich" || name == "munich")
	{
		cout << "Chosen City is Munich\n" << endl;
	}
	else if (name == "Hamburg" || name == "hamburg")
	{
		cout << "Chosen City is Hamburg\n" << endl;
	}
	else if (name == "Berlin" || name == "berlin")
	{
		cout << "Chosen City is Berlin\n" << endl;
	}
	return name;
}



void City::footballclub(string city)
{

	if (city == "Munich" || city == "munich")
	{
		cout << "Munich has two major football clubs: TSV 1860 and FC Bayern Muenchen\n" << endl;
	}
	else if (city == "Hamburg" || city == "hamburg")
	{
		cout << "Hamburg has two major football clubs: Hamburger SV and 1.FC St. Pauli\n" << endl;
	}
	else if (city == "Berlin" || city == "berlin")
	{
		cout << "Berlin has two major football clubs: Hertha BSC and Union Berlin\n" << endl;
	}
}

string City::getDistrict(string name)
{
	string newName;
	if (name == "Munich" || name == "munich")
	{
		newName = "Munich.txt";
	}
	else if (name == "Hamburg" || name == "hamburg")
	{
		newName = "Hamburg.txt";
	}
	else if (name == "Berlin" || name == "berlin")
	{
		newName = "Berlin.txt";
	}
	return newName;
}

void District::seperateStrings(string path)
{

	ifstream file(path, ios::in);
	vector<string> district;
	vector<int> populations;
	string temp;
	while (getline(file, temp, '\n'))
	{
		district.push_back(temp.substr(0, temp.find('\t')));
		populations.push_back(stoi(temp.substr(temp.find('\t') + 1)));
	}

	int sum = 0;
	for (int i = 0; i < district.size(); ++i)
	{
		cout << district[i] << endl;
		//cout << populations[i] << endl;
		sum += populations[i];
	}
	string ext(".txt");
	if (path != ext &&
		path.size() > ext.size() &&
		path.substr(path.size() - ext.size()) == ".txt")
	{
		// if so then strip them off
		path = path.substr(0, path.size() - ext.size());
	}
	cout << "\n" << path << " has " << sum << " residents" << endl;
	cout << "\n" << path << " has " << district.size() << " districts" << endl;
}
