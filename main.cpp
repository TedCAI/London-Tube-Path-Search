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
	print_all(sorted_list, station_list);

//	search_by_keyword(sorted_list, station_list);
//	mode_selection(sorted_list, station_list);
	//test section
/*
	int start, end;
	Station * result_station;
	cout<<"Start: ";
	cin>>start;
	cout<<"End: ";
	cin>>end;
	vector<int> result_path = random_search_start(station_list, start, end);
	for(vector<int>::iterator it = result_path.begin();it != result_path.end();++it){
		find_index(station_list, result_station, *it);
		cout<<"\""<<result_station->get_station_name()<<"\" ";
	}
	cout<<endl;
*/
	return 0;
}
