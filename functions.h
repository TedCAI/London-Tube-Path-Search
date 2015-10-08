#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include "fileIO.h"
//#include "station.h"
//#include "fileIO.h"

bool sort_by_name (Station* const (&p1), Station* const (&p2));
void find_index(const vector<Station *> & station_list, Station * &station, int index);
Station * station_index_to_name(const vector<Station *> & station_list, int index);
vector<string> next_stations(const vector<Station *> & station_list, const vector<int> & index);
void print_station_info(const vector<Station *> & station_list, Station * station, int mode = 0);
void print_all(const vector<Station *> & print_list, const vector<Station *> & original_list, int mode = 0);
void match_name(const string & name, Station* const &station, vector<Station *> & result_station_list);
void match_all(const string & name, vector<Station *> & result_station_list, const vector<Station *> & station_list);
vector <Station *> station_search_by_name(const string & name, const vector<Station *> & station_list);
void search_by_keyword(const vector<Station *> & search_list, const vector<Station *> & original_list);
void station_at(const int & line, Station* const &station, vector<Station *> & result_station_list);
void all_station_at(const int & line, vector<Station *> & match_station_list, const vector<Station *> & search_list);
vector<Station *> station_search_by_line(const int & line, const vector<Station *> & search_list);
void search_by_line(const vector<Station *> & search_list, const vector<Station *> & original_list);
void mode_selection(const vector<Station *> & search_list, const vector<Station *> & original_list);
