#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "fileIO.h"
#include <algorithm>
#include "functions.h"

using namespace std;

int main(){
	FileIO * file = new FileIO("tube.txt");
	vector<Station *> station_list = file->read_file_to_station_list();
	vector<Station *> sorted_list = file->read_file_to_station_list();
	std::sort(sorted_list.begin(), sorted_list.end(), sort_by_name);
	print_all(sorted_list, station_list);

//	search_by_keyword(sorted_list, station_list);
	mode_selection(sorted_list, station_list);

	return 0;
}
