#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "station.h"

Station::Station(){}

Station::Station(const int & index, const string & station_name, const vector<int> & next,const vector<int> & in_lines){
	this->index = index;
	name = station_name;
	next_station = next;
	lines = in_lines;
}

Station::Station(const Station & s){
	index = s.get_station_index();
	name = s.get_station_name();
	next_station = s.get_station_next_station();
	lines = s.get_station_lines();
}

string Station::get_station_name() const{
	return name;
}

string Station::line_name(const int & line){
	switch(line){
		case 1:
			return "Bakerloo";
		case 2:
			return "Central";
		case 3:
			return "Circle";
		case 4:
			return "District";
		case 5:
			return "Hammersmith & City";
		case 6:
			return "Jubilee";
		case 7:
			return "Metropolitan";
		case 8:
			return "Northern";
		case 9:
			return "Piccadilly";
		case 10:
			return "Victoria";
		case 11:
			return "Waterloo & City";
		case 12:
			return "DLR";
		case 13:
			return "Emirates Air Line";
		case 14:
			return "London Overground";
		case 15:
			return "TfL Rail";
		default:
			return "Error!";
	}
}

vector<string> Station::line_names(){
	vector<string> names;
	for(vector<int>::iterator it = lines.begin();it != lines.end();++it)
                names.push_back(line_name(*it));
	return names;
}
/*
Station * Station::get_station_at(const vector<Station *> & station_list, const int & index){
	return station_list[index];
}
*/
int Station::get_station_index() const{
	return index;
}

vector<int> Station::get_station_lines() const{
	return lines;
}

vector<int> Station::get_station_next_station() const{
        return next_station;
}
/*
void Station::print_station_info(){
	cout<<"======================================="<<endl;
	cout<<"Index: "<<index<<endl;
	cout<<"Station Name: "<<name<<endl;
	cout<<"Located At: ";
	for(vector<int>::iterator it = lines.begin();it != lines.end();++it)
		cout<<line_name(*it)<<" ";
//		cout<<*it<<" ";
	cout<<endl;
	cout<<"Next Station: ";
	for(vector<int>::iterator it = next_station.begin();it != next_station.end();++it)
		cout<<*it<<" ";
	cout<<endl;
}*/
