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
	int get_station_index();
	const vector<int> & get_station_lines();
	const vector<int> & get_station_next_station();
	string get_station_name();
	string line_name(const int &);
	vector<string> line_names();
//	void print_station_info();
};
