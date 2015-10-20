#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include "functions.h"

using namespace std;

bool sort_by_name (Station* const (&p1), Station* const (&p2)){
	return p1->get_station_name()<p2->get_station_name();
}

void find_index(const vector<Station *> & station_list, Station * &station, int index){
	size_t size = station_list.size();
//	cout<<"a"<<size<<endl;
	if(size > 0){
		if(size == 1){
//		cout<<"b"<<endl;
			if(station_list[0]->get_station_index() == index)
				station = station_list[0];
		}
		else{
			size_t mid = size / 2;
//		cout<<"c "<<mid<<endl;
//		cout<<station_list[mid]->get_station_index()<<endl;
			if(station_list[mid]->get_station_index() == index)
        	                station = station_list[mid];
			else if(station_list[mid]->get_station_index() > index){
				vector<Station *> left(station_list.begin(), station_list.begin() + mid);
				find_index(left, station, index);
			}
			else{
				vector<Station *> right(station_list.begin() + mid + 1, station_list.end());
				find_index(right, station, index);
			}
		}
//	cout<<"resutlt: "<<station->get_station_index()<<endl;
	}
}

Station * station_index_to_name(const vector<Station *> & station_list, int index){
	Station * station;
	find_index(station_list, station, index);
	return station;
} 

vector<string> next_stations(const vector<Station *> & station_list, const vector<int> & index){
        vector<string> stations;
        vector<int> indice = index;
        for(vector<int>::const_iterator it = indice.begin();it != indice.end();++it){
//                Station * station = station_list[*it];
//                string name = station->get_station_name();
//		cout<<"original "<<*it<<endl;
		Station * station = station_index_to_name(station_list, *it);
		string name = (station) ? station->get_station_name() : "Error!";
                stations.push_back(name);
        }
        return stations;
}

void print_station_info(const vector<Station *> & station_list, Station * station, int mode){
        vector<string> lines, next_station_str;
        lines = station->line_names();
        next_station_str = next_stations(station_list, station->get_station_next_station());
	
	if(mode == 0){
        	cout<<"======================================="<<endl;
	        cout<<"Index: "<<station->get_station_index()<<endl;
        	cout<<"Station Name: "<<station->get_station_name()<<endl;
	        cout<<"Located At: ";

        	for(vector<string>::iterator it = lines.begin();it != lines.end();++it)
                	cout<<"\""<<*it<<"\""<<" ";
        	cout<<endl;
	        cout<<"Next Station: ";
        	for(vector<string>::iterator it = next_station_str.begin();it != next_station_str.end();++it)
                	cout<<"\""<<*it<<"\""<<" ";
	        cout<<endl;
	}
	else if(mode == 1){
		cout<<"Index: "<<station->get_station_index()<<"\t"<<"Station Name: "<<station->get_station_name()<<endl;
	}
}

void print_all(const vector<Station *> & print_list, const vector<Station *> & original_list, int mode){
	for(vector<Station *>::const_iterator it = print_list.begin();it != print_list.end();++it)
                print_station_info(original_list, *it, mode);
}

void match_name(const string & name, Station* const &station, vector<Station *> & result_station_list){
	string station_name = station->get_station_name();
	transform(station_name.begin(), station_name.end(), station_name.begin(), ::tolower);
	size_t found = station_name.find(name);
	if(found!=string::npos)
		result_station_list.push_back(station);
}

void match_all(const string & name, vector<Station *> & result_station_list, const vector<Station *> & station_list){
	for(vector<Station *>::const_iterator it = station_list.begin();it != station_list.end();++it){
		match_name(name, *it, result_station_list);
	}
}

vector <Station *> station_search_by_name(const string & name, const vector<Station *> & station_list){
	vector <Station *> match_station_list;
	string name_lowercase = name;
	transform(name_lowercase.begin(), name_lowercase.end(), name_lowercase.begin(), ::tolower);
	match_all(name_lowercase, match_station_list, station_list);
	return match_station_list;
}

void search_by_keyword(const vector<Station *> & search_list, const vector<Station *> & original_list){
	string keyword;
        do{
                cout<<"//////////Search a station by keyword//////////"<<endl;
                cout<<"You can enter \'exit\' to terminate this programme"<<endl;
                cout<<"Please enter a keyword: ";
                cin>>keyword;
                vector<Station *> result = station_search_by_name(keyword, search_list);
                print_all(result, original_list);
        }while(keyword !="exit");
}

void station_at(const int & line, Station* const &station, vector<Station *> & result_station_list){
        vector<int> line_list = station->get_station_lines();
	if(find(line_list.begin(), line_list.end(), line) != line_list.end())
                result_station_list.push_back(station);
}

void all_station_at(const int & line, vector<Station *> & match_station_list, const vector<Station *> & search_list){
	for(vector<Station *>::const_iterator it = search_list.begin();it != search_list.end();++it)
		station_at(line, *it, match_station_list);
}

vector<Station *> station_search_by_line(const int & line, const vector<Station *> & search_list){
	vector <Station *> match_station_list;
        all_station_at(line, match_station_list, search_list);
        return match_station_list;
}

void search_by_line(const vector<Station *> & search_list, const vector<Station *> & original_list){
	int line;
	do{
                cout<<"//////////Find a station from a specific line//////////"<<endl;
                cout<<"1. Bakerloo Line"<<endl;
		cout<<"2. Central Line"<<endl;
		cout<<"3. Circle Line"<<endl;
		cout<<"4. District Line"<<endl;
		cout<<"5. Hammersmith & City Line"<<endl;
		cout<<"6. Jubilee Line"<<endl;
                cout<<"7. Metropolitan Line"<<endl;
                cout<<"8. Northern Line"<<endl;
                cout<<"9. Piccadilly Line"<<endl;
                cout<<"10. Victoria Line"<<endl;
		cout<<"11. Waterloo & City Line"<<endl;
                cout<<"12. DLR"<<endl;
                cout<<"13. Emirates Air Line"<<endl;
                cout<<"14. London Overground"<<endl;
                cout<<"15. TfL Rail"<<endl;
		cout<<"16. Exit"<<endl;
                cout<<"Please select a line: ";
                cin>>line;
                vector<Station *> result = station_search_by_line(line, search_list);
                print_all(result, original_list, 1);
        }while(line != 16);
}

void tube_path_search(const vector<Station *> & station_list){
	int start, end;
        Station * result_station, *start_p, *end_p;
        cout<<"Start: ";
        cin>>start;
        cout<<"End: ";
        cin>>end;

        if(station_validation(station_list, start) && station_validation(station_list, end)){
        
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
	else{
		cout<<"Invalid station index, please try again."<<endl;
		tube_path_search(station_list);
	}
}

void mode_selection(const vector<Station *> & search_list, const vector<Station *> & original_list){
//	int mode;
	cout<<"//////////London Tube Station Search//////////"<<endl;
	while(1){
		int mode;
//		cout<<"//////////London Tube Station Search//////////"<<endl;
		cout<<"1. Search a station by keyword"<<endl;
		cout<<"2. Find a station from a specific line"<<endl;
		cout<<"3. Tube path search"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Please select a mode: ";
		cin>>mode;
		if(mode == 1)
			search_by_keyword(search_list, original_list);
		else if(mode == 2)
			search_by_line(search_list, original_list);
		else if(mode == 3)
			tube_path_search(original_list);
		else if(mode == 4)
			break;
		else
			cout<<"Please enter a proper number."<<endl;
	}
}

bool station_validation(const vector<Station *> station_list, const int & station_index){
	Station * station_p = NULL;
	find_index(station_list, station_p, station_index);
//	cout<<"station_p "<<endl;	
	return (station_p != NULL) ? true : false;
}


