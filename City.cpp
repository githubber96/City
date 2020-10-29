#include "City.h"
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <stdlib.h>

using namespace std;

string choseCity()
{
	string input;
	cin >> input;
	return input;
}

void printTable()
{
	cout << "Disctricts \t\t Residents" << endl;
	cout << "---------- \t\t ---------\n" << endl;
}

City::City(string name) :
	m_name(name)
{
	transform(begin(m_name), end(m_name), begin(m_name), tolower);
	if (!m_name.empty())
	{
		m_name[0] = toupper(m_name[0]);
	}

	auto path = name + ".txt";
	loadInfo(path);
}

string City::getName()
{
	if (m_name == "Munich")
	{
		return m_name;
	}
	if (m_name == "Berlin")
	{
		return m_name;
	}
	if (m_name == "Hamburg")
	{
		return m_name;
	}
	else
	{
		cout << "invalid input";
		exit(1);
	}
}

string City::getFootballclub(bool print)
{
	if (print)
	{
		cout << "\n" << m_footballClub << "\n" << endl;
	}
	return m_footballClub;
}

void City::getDistricts()
{
	for (int i = 0; i < m_districts.size(); i++)
	{
		cout << m_districts[i].name << " \t ";
		cout.imbue(locale(""));
		cout << m_districts[i].population << endl;
	}
}

void City::population()
{
	int sum = 0;
	for (int i = 0; i < m_districts.size(); i++)
	{
		sum += m_districts[i].population;
	}
	cout.imbue(locale(""));
	cout << "\n" << m_name << " has " << sum << " residents" <<  endl;
}

void City::loadInfo(string path)
{
	//LOAD DISTRICTS
	ifstream file(path, ios::in);
	string temp;
	while (getline(file, temp, '\n'))
	{
		Dist d;
		d.name = temp.substr(0, temp.find('\t'));
		d.population = stoi(temp.substr(temp.find('\t') + 1));
		m_districts.push_back(d);
		//m_population
	}

	//LOAD FOOTBALL CLUB
	if (m_name == "Munich")
	{
		m_footballClub = "Munich has two major football clubs: TSV 1860 and FC Bayern Muenchen";
	}
	if (m_name == "Hamburg")
	{
		m_footballClub = "Hamburg has two major football clubs: Hamburger SV and 1.FC St. Pauli";
	}
	if (m_name == "Berlin")
	{
		m_footballClub = "Berlin has two major football clubs: Hertha BSC and Union Berlin";
	}
}

//void District::seperateStrings(string path)
//{
//
//	ifstream file(path, ios::in);
//	vector<string> district;
//	vector<int> populations;
//	string temp;
//	while (getline(file, temp, '\n'))
//	{
//		district.push_back(temp.substr(0, temp.find('\t')));
//		populations.push_back(stoi(temp.substr(temp.find('\t') + 1)));
//	}
//
//	int sum = 0;
//	for (int i = 0; i < district.size(); ++i)
//	{
//		cout << district[i] << "\t" << populations[i] << endl;
//		sum += populations[i];
//	}
//	string ext(".txt");
//	if (path != ext &&
//		path.size() > ext.size() &&
//		path.substr(path.size() - ext.size()) == ".txt")
//	{
//		// if so then strip them off
//		path = path.substr(0, path.size() - ext.size());
//	}
//	cout << "\n" << path << " has " << sum << " residents" << endl;
//	cout << "\n" << path << " has " << district.size() << " districts" << endl;
//}
