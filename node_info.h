#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class NodeInfo{
private:
	vector<int> stations;
	int current_line;
	int scores;
public:
	vector & get_stations(){ return stations;}
	void add_station(const int & station){ stations.push_back(station); }
	int & get_current_line(){ return current_line;}
	void set_current_line(const int & line){ current_line = line; }
	int & get_scores(){ return scores; }
	void set_scores(const int & new_scores){ scores = new_scores; } 
};
