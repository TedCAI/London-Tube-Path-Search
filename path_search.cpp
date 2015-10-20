#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include "path_search.h"

using namespace std;
//A star function with BUG
//SHOULD NOT USE RECURSION
/*
void A_star_single_node(const vector<Station *> & station_list, vector< vector<int> > & total_path, vector<int> & return_path, vector<int> & reached_list, const int & previous_node, const int & start, const int & end){
	
}
*/

void A_star(const vector<Station *> & station_list, vector< vector<int> > & total_path, vector<int> & return_path, vector<int> & reached_list, const vector<int> & previous_nodes, const int & start, const int & end){
	vector<int> next_nodes;
	for(vector<int>::const_iterator it_n = previous_nodes.begin(); it_n != previous_nodes.end(); ++it_n){
//		 if(find(reached_list.begin(), reached_list.end(), *it_n) == reached_list.end()){
			//reached_list.push_back(*it_n);
			Station * previous_node_p;
			find_index(station_list, previous_node_p, *it_n);
			vector<int> next_stations = previous_node_p->get_station_next_station();
			vector<int> current_path = total_path[*it_n];
			current_path.push_back(*it_n);
			for(vector<int>::iterator it = next_stations.begin();it != next_stations.end();++it){
				if(find(reached_list.begin(), reached_list.end(), *it) == reached_list.end()){
					reached_list.push_back(*it);
					next_nodes.push_back(*it);
					if(*it == end && return_path.size() <= 0){
						return_path = current_path;
						return_path.push_back(*it);
						total_path[*it] = current_path;

						cout<<" return_path size :"<<return_path.size()<<endl;
						break;
					}
					else if(return_path.size() > 0){
						total_path[*it] = current_path;
						//total_path[*it].push_back(*it);
						break;
					}
					else{
						//reached_list.push_back(*it);
						total_path[*it] = current_path;
						//total_path[*it].push_back(*it);
					}
				}
			}
			
			if(/*it == next_stations.end() - 1 &&*/ return_path.size() > 0)
				//next_nodes.insert(next_nodes.end(), next_stations.begin(), next_stations.end());
			//else
				break;
//		}
	}
	if(return_path.size() <= 0){
//		for(vector<int>::iterator it = next_nodes.begin(); it != next_nodes.end(); ++it)
//			cout<<*it<<" ";
//		cout<<endl;
		A_star(station_list, total_path, return_path, reached_list, next_nodes, start, end);
	}
}

vector<int> A_star_start(const vector<Station *> & station_list, const int & start, const int & end){
	vector< vector<int> > total_path;
	vector<int> empty, return_path, reached_list, start_node;
	Station * last_station = station_list.back();
	int last_index = last_station->get_station_index();
	for(int i = 0; i <= last_index; i++)
		total_path.push_back(empty);

	reached_list.push_back(start);
	start_node.push_back(start);
	A_star(station_list, total_path, return_path, reached_list, start_node, start, end);
//	return_path.insert(return_path.begin(), start);
	return return_path;
}

void random_search(const vector<Station *> & station_list, vector<int> & reached_list, vector<int> & path, const int & end){
	int tail = path.back();
//	cout<<"tail = "<<tail<<endl;
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
