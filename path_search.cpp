#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
//#include "functions.h"
//#include "fileIO.h"
#include <algorithm>
#include "path_search.h"
//#include "station.h"

using namespace std;

void random_search(const vector<Station *> & station_list, vector<int> & reached_list, vector<int> & path, const int & end){
	int tail = path.back();
	cout<<"tail = "<<tail<<endl;
	Station * tail_station;
	find_index(station_list, tail_station, tail);
	/**/
	vector<int> stations = tail_station->get_station_next_station();
	for(vector<int>::iterator it=stations.begin();it != stations.end(); ++it){
		if(*it == end){
			path.push_back(end);
			reached_list.push_back(end);
			break;
		}
		else{	
			if(find(path.begin(), path.end(), *it) == path.end() && find(reached_list.begin(), reached_list.end(), *it) == reached_list.end()){
				path.push_back(*it);
				//reached_list.push_back(*it);
				break;
			}
			else{
				if(it == (stations.end() - 1)){
					path.pop_back();
					reached_list.push_back(tail);
					//dfs(station_list, reached_list, path, end);
				}
			}
		}
	}
	if(path.back() != end)
		random_search(station_list, reached_list, path, end);
//		path.push_back(tail);
//		dfs(path, end);
	
}

vector<int> random_search_start(const vector<Station *> & station_list, const int & start, const int & end){
	vector<int> path, reached_list;
	path.push_back(start);
	reached_list.push_back(start);
//	if(start->get_next_station()[0] != end->get_index())
	random_search(station_list, reached_list, path, end);
	return path;
}
