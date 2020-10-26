#pragma once
#include <string>

using namespace std;

string in();


class City
{
public:
	City();
	string choseCity(string name);
	void footballclub(string city);
	string getDistrict(string name);

};

class District
{
public:
	void seperateStrings(string path);
};

