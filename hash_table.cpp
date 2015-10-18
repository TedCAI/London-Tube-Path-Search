#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "path_search.h"

using namespace std;


template<typename T>
struct Element{
	int key;
	T value;
};


//template<typename T>
ostream & operator<<(ostream & out, const Station & t){
	string s = t.print();
	return out<<s;
}

template<typename T>
class hash_table{
/*
struct Element{
        int key;
        T value;
};*/

private:
	Element<T> *elem;
	int count;
	int size;
	int search_count;
public:
	hash_table(){
		size = 10;
		count = 0;
		elem = new Element<T>[size];
		if(!elem){
			cout<<"Memory allocation failed"<<endl;
			exit(0);
		}
		for(int i = 0;i<size;i++)
			elem[i].key = -1;
	}

	void destroy_hash_table(){
		delete[] elem;
		elem = NULL;
		count = 0;
		size = 0;
	}

	~hash_table(){
		delete[] elem;
		elem = NULL;
	}

	unsigned Hash(const int & key){
		return key%size;
	}

	void collision(int & position, int search_count){
		position = (position + search_count)%size;
	}

	bool search_hash(int key, int & position){
		search_count = 0;
		position = Hash(key);
		while(elem[position].key != -1 && elem[position].key != key){
			search_count++;
			if(search_count<size)
				collision(position, search_count);
			else
				return 0;
		}
		if(elem[position].key == key)
			return 1;
		else
			return 0;
	}

	int insert_hash(Element<T> new_elem){
//		cout<<new_elem.key<<endl;
		int position;
		if(search_hash(new_elem.key, position))
			return -1;
		else if(search_count < size / 2){
			elem[position] = new_elem;
			count++;
			return 1;
		}
		else{
			recreate_hashtable();
//			insert_hash(new_elem);
		}
		return 0;
	}

	void recreate_hashtable(){
		cout<<"a"<<endl;
		int count2 = count;
		int new_size = size * 10;
		int old_size = size;
		int position;
		//Element *new_elem = new Element[new_size];
		Element<T> *current_elem = new Element<T>[size];
		cout<<"b"<<endl;
		for(int i = 0;i<size;i++)
			if(elem[i].key != -1){
				int k = elem[i].key;
				T v = elem[i].value;
				Element<T> e = {k, v};
				current_elem[i] = e;
			}
		cout<<"c"<<endl;
		Element<T> *new_elem = new Element<T>[new_size];
		if(!new_elem){
			cout<<"Memory allocation for hashtable recreation failed"<<endl;
			exit(0);
		}
		elem = new_elem;
		size = new_size;
		cout<<"d"<<endl;
		for(int i = 0;i<new_size;i++)
			elem[i].key = -1;
		cout<<"e "<<size<<" "<<new_size<<endl;
//		cout<<current_elem[0].value.get_station_name()<<endl;
		for(int i = 0;i<old_size;i++)
			insert_hash(current_elem[i]);
		size = new_size;
		cout<<"f"<<endl;
	}

	void traverse_hashtable(){
		cout<<"Hashtable address from 0 to "<<size<<endl;
		for(int i=0;i<size;i++)
			if(elem[i].key != -1)
				get_data(i);
	}

	void get_data(int i){
		cout<<"Key: "<<elem[i].key<<" Value: "<<elem[i].value<<endl;
	}
};

int main(){
	FileIO * file = new FileIO("tube.txt");
	vector<Station *> station_list = file->read_file_to_station_list();
        vector<Station *> sorted_list = file->read_file_to_station_list();
        std::sort(sorted_list.begin(), sorted_list.end(), sort_by_name);
	hash_table<Station> *ht = new hash_table<Station>();
	for(vector<Station *>::iterator it=sorted_list.begin();it != sorted_list.end(); ++it){
		Station new_station(*(*it));
		int ind = new_station.get_station_index();
		Element<Station> new_elem = { ind, new_station};
		int returned = ht->insert_hash(new_elem);
		cout<<new_station.get_station_name()<<" "<<returned<<endl;
		while(returned == 0)
			returned = ht->insert_hash(new_elem);
	}

	ht->traverse_hashtable();
	return 0;
}
