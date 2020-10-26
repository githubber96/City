// Info about a City.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include "City.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <vector>
#include <sstream>


using namespace std;

int main()
{
    cout << "Chose your city from the following: Munich, Berlin, Hamburg" << endl;
    City city;
    string name = city.choseCity(in());
    city.footballclub(name);
    string newName = city.getDistrict(name);

    District district;
    district.seperateStrings(newName);

}
