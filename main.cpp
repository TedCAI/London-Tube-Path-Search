#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include "path_search.h"

using namespace std;

int main(){
	FileIO * file = new FileIO("tube.txt");
	vector<Station *> station_list = file->read_file_to_station_list();
	vector<Station *> sorted_list = file->read_file_to_station_list();
	std::sort(sorted_list.begin(), sorted_list.end(), sort_by_name);
//	print_all(sorted_list, station_list);

//	search_by_keyword(sorted_list, station_list);
	mode_selection(sorted_list, station_list);
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
