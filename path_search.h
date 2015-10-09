#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include "functions.h"
#include <algorithm>
//#include "fileIO.h"
//#include "station.h"

//using namespace std;
void A_star(const vector<Station *> & station_list, vector< vector<int> > & total_path, vector<int> & return_path, vector<int> & reached_list, const vector<int> & previous_nodes, const int & start, const int & end);
vector<int> A_star_start(const vector<Station *> & station_list, const int & start, const int & end);
void random_search(const vector<Station *> & station_list, vector<int> & reached_list, vector<int> & path, const int & end);
vector<int> random_search_start(const vector<Station *> & station_list, const int & start, const int & end);
