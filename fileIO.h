#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "station.h"

using namespace std;

class FileIO
{
private:
	string filename;
public:
	FileIO(string);
//	void create_new_station(const string &);
	vector<Station *> & create_new_station(const string &, vector<Station *> &);
//	void read_file();
	vector<int> & additional_infos(const string &, vector<int> &);
//	void create_new_station(const vector<string> &, Station *);
	vector<Station *> read_file_to_station_list();
	vector<Station *> & read_file(vector<Station *> & station_list);
	Station * add_new_station_infos(const vector<string> &, Station *);
	vector<string> & split(const string &, char, vector<string> &);
	vector<string> split(const string &, char);
	//~FileIO(){delete filename;};
};
