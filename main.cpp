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
    auto name = choseCity();
    City city(name);
    city.getName();
    city.getFootballclub(true);
    printTable();
    city.getDistricts();
    city.population();

}
