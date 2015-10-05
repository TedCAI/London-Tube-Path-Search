#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include "fileIO.h"
//#include "station.h"

using namespace std;

int main(){
	FileIO * file = new FileIO("tube.txt");
	vector<Station *> station_list = file->read_file_to_station_list();
	for(vector<Station *>::iterator it = station_list.begin();it != station_list.end();++it)
		(*it)->print_station_info();

//	station_list[0]->print_station_info();
	
	return 0;
}
