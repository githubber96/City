#pragma once

#include <string>
#include <vector>

using namespace std;
enum class Base {MUNICH, BERLIN, HAMBURG, INVALID};

string choseCity();
void printTable();

struct Dist
{
	string name;
	int population = 0;
};

class City
{
public:
	City(string name);
	string getName();
	string getFootballclub(bool print = false);
	void getDistricts();
	void population();

private:
	void loadInfo(string path);
	string m_name;
	string m_footballClub;
	vector<Dist> m_districts;
};

//class District
//{
//public:
//	void seperateStrings(string path);
//};

