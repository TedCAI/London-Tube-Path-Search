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
	Station();
	Station(const int &, const string &, const vector<int> &, const vector<int> &);
	Station(const Station &);
	int get_station_index() const;
	vector<int> get_station_lines() const;
	vector<int> get_station_next_station() const;
	string get_station_name() const;
	string line_name(const int &);
	vector<string> line_names();
	Station & operator=(const Station & rhs){
		if(this != &rhs){
			int index1 = rhs.get_station_index();
			string name1 = rhs.get_station_name();
			vector<int> next_station1 = rhs.get_station_next_station();
			vector<int> lines1 = rhs.get_station_lines();
			index = index1;
			name = name1;
			next_station = next_station1;
			lines = lines1;
		}
		return *this;
	}
	bool operator==(const Station & rhs){ return (index == rhs.index && name == rhs.name);}
	string print() const{ return name;}
//	void print_station_info();
};
