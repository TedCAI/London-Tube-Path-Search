#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include "path_search.h"
#include <set>
#include <map>

using namespace std;

int main(){
	FileIO * file = new FileIO("tube.txt");
	vector<Station *> station_list = file->read_file_to_station_list();
	vector<Station *> sorted_list = file->read_file_to_station_list();
	std::sort(sorted_list.begin(), sorted_list.end(), sort_by_name);
//	print_all(sorted_list, station_list);
//set code test

	bool (*fpt)(Station * const &, Station * const &) = sort_by_name;
/*	set<Station *, bool(*)(Station * const &, Station * const &)> test(station_list.begin(), station_list.end(), fpt);
	for(set<Station *, bool(*)(Station * const &, Station * const &)>::iterator it = test.begin(); it != test.end(); ++it)
		cout<<(*it)->get_station_name()<<endl;
*/

//map code test
	map<int, Station *> map_test;
	map<string, Station *> map_test1;
//	map<int, Station *, bool(*)(Station * const &, Station * const &)> map_test(fpt);
	for(vector<Station *>::iterator it=station_list.begin(); it != station_list.end();++it){
		int ind = (*it)->get_station_index();
		string name = (*it)->get_station_name();
		map_test[ind]=(*it);
		map_test1[name]=(*it);
	}
	cout<<"size of map_test1 is "<<map_test1.size()<<endl;
//	for(map<int, Station *>::iterator it = map_test.begin(); it != map_test.end(); ++it)
	for(map<string, Station *>::iterator it = map_test1.begin(); it != map_test1.end(); ++it)
		cout<<(it)->first<<endl;
//	search_by_keyword(sorted_list, station_list);
//	mode_selection(sorted_list, station_list);
	//test section
/*
	int start, end;
	Station * result_station, *start_p, *end_p;
	cout<<"Start: ";
	cin>>start;
	cout<<"End: ";
	cin>>end;

	if(station_validation(station_list, start) && station_validation(station_list, end)){
	cout<<endl;
	find_index(station_list, start_p, start);
	find_index(station_list, end_p, end);
	cout<<"Start from "<<start_p->get_station_name()<<" to "<<end_p->get_station_name()<<endl;

	vector<int> result_path = A_star_start(station_list, start, end);
	for(vector<int>::iterator it = result_path.begin();it != result_path.end() - 1;++it){
		find_index(station_list, result_station, *it);
		cout<<result_station->get_station_name()<<"->";
	}
	
	cout<<end_p->get_station_name()<<endl;
	cout<<result_path.size()<<" stations in total."<<endl;

	}
*/
	return 0;
}
