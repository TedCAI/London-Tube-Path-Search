#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "fileIO.h"
//#include "station.h"

using namespace std;

FileIO::FileIO(string name){
	filename = name;
}

vector<string> & FileIO::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> FileIO::split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

vector<int> & FileIO::additional_infos(const string & infos, vector<int> & list){
	vector<string> strs = split(infos, ',');
	for(vector<string>::iterator it = strs.begin();it != strs.end();++it)
		list.push_back(atoi((*it).c_str()));
	return list;
}

Station * FileIO::add_new_station_infos(const vector<string> & infos, Station * new_station){
	vector<int> next_stations, lines;
	int index = atoi(infos[0].c_str());
	next_stations = additional_infos(infos[2], next_stations);
        lines = additional_infos(infos[3], lines);
	new_station = new Station(index, infos[1], next_stations, lines);
	return new_station;
}

vector<Station *> & FileIO::create_new_station(const string & line, vector<Station *> & station_list){
	vector<string> strs = split(line, '\t');
	vector<Station *>::iterator it;
	Station * new_station; //= new Station(strs[0], next_stations, lines);
	new_station = add_new_station_infos(strs, new_station);
	it = station_list.end();
	station_list.insert(it, new_station);
	cout<<new_station->get_station_name()<<" is added."<<endl;
	
	return station_list;
}

vector<Station *> FileIO::read_file_to_station_list(){
	vector<Station *> station_list;
	swap(read_file(station_list), station_list);
	cout<<"Reading file into station list accomplished."<<endl;
	return station_list;
}

vector<Station *> & FileIO::read_file(vector<Station *> & station_list){
	string line;
	const char *c_filename = filename.c_str();
	ifstream openfile(c_filename);
	if(openfile.is_open()){
		while (getline (openfile, line)){
			station_list = create_new_station(line, station_list);
		}
		openfile.close();
	}
	else cout << "Unable to open file";
	
	return station_list;
}
