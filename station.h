#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>

using namespace std;

class Station
{
private:
	int index;
	string name;
	vector<int> next_station, lines;
public:
	Station(const int &, const string &, const vector<int> &, const vector<int> &);
	string get_station_name();
	string line_name(const int &);
	void print_station_info();
};
