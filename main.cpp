#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "fileIO.h"
//#include "station.h"

using namespace std;

vector<string> next_stations(const vector<Station *> & station_list, const vector<int> & index){
	vector<string> stations;
	vector<int> indice = index;
	for(vector<int>::const_iterator it = indice.begin();it != indice.end();++it){
		Station * station = station_list[*it];
		string name = station->get_station_name();
		stations.push_back(name);
	}
	return stations;
}

void print_station_info(const vector<Station *> & station_list, Station * station){
	vector<int> next_station;
	vector<string> lines, next_station_str;
	lines = station->line_names();
//	next_station = station->get_station_next_station();
	next_station_str = next_stations(station_list, station->get_station_next_station());

        cout<<"======================================="<<endl;
        cout<<"Index: "<<station->get_station_index()<<endl;
        cout<<"Station Name: "<<station->get_station_name()<<endl;
        cout<<"Located At: ";
	
        for(vector<string>::iterator it = lines.begin();it != lines.end();++it)
                cout<<*it<<" ";
//              cout<<*it<<" ";
        cout<<endl;
        cout<<"Next Station: ";
//        for(vector<int>::iterator it = next_station.begin();it != next_station.end();++it)
	for(vector<string>::iterator it = next_station_str.begin();it != next_station_str.end();++it)
                cout<<*it<<" ";
        cout<<endl;
}

int main(){
	FileIO * file = new FileIO("tube.txt");
	vector<Station *> station_list = file->read_file_to_station_list();
	for(vector<Station *>::iterator it = station_list.begin();it != station_list.end();++it)
		print_station_info(station_list, *it);

//	station_list[0]->print_station_info();
	
	return 0;
}
