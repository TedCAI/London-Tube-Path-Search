#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include "path_search.h"

using namespace std;

template<typename T>
class node {
public:
	T data;
	int height;
	node<T> *lhs, *rhs, *father;

	node(){
		data = T();
		height = 0;
		lhs = NULL;
		rhs = NULL;
		father = NULL;
	}

	node(const T &d, const int &h = 0, node<T> * const &f = NULL, node<T> * const &l = NULL, node<T> * const &r = NULL){
		data = d;
		height = h;
//		cout<<"cons"<<endl;
		lhs = l;
//		cout<<"cons lhs"<<endl;
		rhs = r;
//		cout<<"cons rhs"<<endl;
		father = f;
//		cout<<"cons father"<<endl;
	}

	node( const node<T> & _node){
		if(&_node){
//			cout<<"copy"<<endl;
			data = _node.data;
//			cout<<"copy data "<<data<<endl;
			height = _node.height;
			lhs = _node.lhs;
//			cout<<"copy lhs"<<endl;
			rhs = _node.rhs;
//			cout<<"copy rhs"<<endl;
			father = _node.father;
//			cout<<"copy father"<<endl;
		}
		else{
			data = T();
			height = 0;
			father = lhs = rhs = NULL;
		}
	}

	node<T> & operator=(const node<T> & _node){
//		cout<<"operator"<<endl;
		if(this != &(_node)){
			data = _node.data;
//			cout<<"data"<<endl;
			height = _node.height;
//			cout<<"height"<<endl;
			lhs = _node.lhs;
//			cout<<"lhs"<<endl;
			rhs = _node.rhs;
//			cout<<"rhs"<<endl;
			father = _node.father;
//			cout<<"father"<<endl;
		}
//		cout<<"operator done"<<endl;
		return *this;
	}

	~node<T>(){
		if(this){
//			cout<<"delete node "<<data<<" "<<lhs<<" "<<rhs<<endl;
			if(lhs){
//				cout<<"lhs "<<endl;
//				cout<<"delete lhs "<<lhs->data<<endl;
				delete lhs;
			}
			if(rhs){
//				cout<<"delete rhs "<<rhs->data<<endl;
				delete rhs;
			}
			data = -1;
		}
	}
};

template<typename T>
class binary_tree{
public:
	node<T> *root;
	int tree_height, count;
	binary_tree(){
		root = NULL;
		tree_height = 0;
		count = 0;
	}
	
	binary_tree(node<T> * new_root){
		root = new_root;
		tree_height = 0;
		count = 0;
	}

	binary_tree(node<T> const &new_root){
		*root = new_root;
		tree_height = 0;
		count = 0;
	}

	void update_tree_height(const int & new_height){
		if(new_height > tree_height)
			tree_height = new_height;
	}

	node<T> * search(const T & value) {
		node<T> *_hot = new node<T>();
		node<T> *r = search_tree(value, root, _hot);
		return search_tree(value, root, _hot);
	}

	node<T> * search_tree(const T & value, node<T> *parent_node, node<T> * &_hot){
		if(!parent_node || (parent_node->data == value)){
			return parent_node;
		}
		else{
//			cout<<"parent_node father "<<parent_node->father<<endl;
			_hot = parent_node;
//			cout<<"_hot father "<<_hot->father<<endl;
			return search_tree(value, (value < parent_node->data) ? parent_node->lhs : parent_node->rhs, _hot);
		}
	}

	virtual bool insert(const T & value){
//		cout<<"BST insert"<<endl;
		node<T> *_hot = new node<T>();
		node<T> *returned_node = search_tree(value, root, _hot);
		if(returned_node)
			return false;
		else{
			returned_node = new node<T>();
			returned_node->data = value;
			returned_node->height = _hot->height + 1;
//			cout<<_hot->father<<endl;
//			returned_node->father = new node<T>(*_hot);
			if((_hot->data) < value){
				_hot->rhs = returned_node;
			}
			else
				_hot->lhs = returned_node;

			returned_node->father = _hot;
			update_tree_height(returned_node->height);
			count++;
			
			return true;
		}	
	}

	node<T> & find_max(){
                node<T> *parent = root;
                while(parent->rhs)
                        parent = parent->rhs;
                return *parent;
        }

	node<T> & find_min(){
		node<T> *parent = root;
		while(parent->lhs)
			parent = parent->lhs;
		return *parent;
	}

	void find_min_from(node<T> * start, node<T> &min){
		if(start == root){
			min = find_min();
		}
		else{
//			cout<<"find 1"<<endl;
//			node<T> *parent = start;
//			cout<<"find 2"<<endl;
			while(start->lhs){
//				cout<<start->data<<" "<<start->height<<" "<<!(start->lhs)<<endl;
				start = start->lhs;
//				cout<<start->data<<endl;
			}
//			cout<<"find 3"<<endl;
			min = *start;
		}
	}

	void find_max_from(node<T> * start, node<T> &max){
                if(start == root){
                        max = find_max();
                }
                else{
//                      cout<<"find 1"<<endl;
//                      node<T> *parent = start;
//                      cout<<"find 2"<<endl;
                        while(start->rhs){
//                              cout<<start->data<<" "<<start->height<<" "<<!(start->lhs)<<endl;
                                start = start->rhs;
//                              cout<<start->data<<endl;
                        }
//                      cout<<"find 3"<<endl;
                        max = *start;
                }
        }

	void traverse_preorder(node<T> *parent){
		if(parent){
			cout<<parent->data<<endl;
			traverse_preorder(parent->lhs);
			traverse_preorder(parent->rhs);
		}
	}

	void traverse_inorder(node<T> *parent){
                if(parent){
			traverse_inorder(parent->lhs);
                        cout<<parent->data<<endl;
                        traverse_inorder(parent->rhs);
                }
        }

	void find_depth_in(node<T> *parent, int & depth, const int & init_depth){
		if(parent){
			if((parent->height - init_depth) > depth)
				depth = parent->height - init_depth;
			find_depth_in(parent->lhs, depth, init_depth);
			find_depth_in(parent->rhs, depth, init_depth);
		}
	}

	int find_depth(node<T> *parent, const int & mode = 1){
		//mode 1: depth from root
		//mode 0: depth from current node
		int init_depth = (mode) ? 0 : parent->height;
		int depth = 0;
		find_depth_in(parent, depth, init_depth);
		return depth;
	}

	virtual ~binary_tree<T>(){
		cout<<"delete binary tree"<<endl;
		delete root; 
	}
};

template<typename T>
class AVL : public binary_tree<T> {
public:
	AVL(){};
	AVL(node<T> * new_root):binary_tree<T>(new_root){};
	AVL(node<T> new_root):binary_tree<T>(new_root){};

	int balance_factor(node<T> * parent){
		return (this->find_depth(parent->lhs, 0) - this->find_depth(parent->rhs, 0));
	}
	
	bool is_balanced(node<T> * parent){
		int factor = balance_factor(parent);
		return (factor <= 1 && factor >= -1);
	}

	void rebalance(node<T> * parent){
		if(parent)
			if(!is_balanced(parent)){
				if(balance_factor(parent) < -1){
//					node<T> * tmp_father = parent->father;
					parent->father->rhs = parent->lhs;
					parent->lhs->father = parent->father;
//					parent->father = parent->father->father;
					parent->lhs = parent->father;
					parent->father = parent->father->father;
					parent->lhs->father = parent;
				}
				else{
					parent->father->lhs = parent->rhs;
					parent->rhs->father = parent->father;
					parent->rhs = parent->father;
					parent->father = parent->father->father;
					parent->rhs->father = parent;
				}
			}
	}

	virtual bool insert(const T &value){
//		cout<<"AVL insert"<<endl;
		node<T> *_hot = new node<T>();
                node<T> *returned_node = this->search_tree(value, this->root, _hot);
                if(returned_node)
                        return false;
                else{
                        returned_node = new node<T>();
                        returned_node->data = value;
                        returned_node->height = _hot->height + 1;
			returned_node->father = _hot;
                        if((_hot->data) < value){
                                _hot->rhs = returned_node;
                        }
                        else
                                _hot->lhs = returned_node;

                        this->update_tree_height(returned_node->height);
                        this->count++;

			rebalance(_hot);

                 	return true;       
                }
	}

	virtual ~AVL<T>(){
		cout<<"delete AVL tree"<<endl;
//		delete[] this->root;
	}
};

int main(){
	FileIO * file = new FileIO("tube.txt");

	vector<Station *> station_list = file->read_file_to_station_list();
	vector<Station *> sorted_list = file->read_file_to_station_list();
	std::sort(sorted_list.begin(), sorted_list.end(), sort_by_name);
//	print_all(sorted_list, station_list);

//	search_by_keyword(sorted_list, station_list);
//	mode_selection(sorted_list, station_list);
	//test section

	node<int> *_node = new node<int>();
//	cout<<sorted_list[0]->get_station_index()<<endl;
	_node->data = sorted_list[0]->get_station_index();
	AVL<int> *tree = new AVL<int>(_node); //new binary_tree<int>(_node);

	for(vector<Station *>::iterator it = sorted_list.begin() + 1;it != sorted_list.end();++it){
		bool b_return = tree->insert((*it)->get_station_index());
//		cout<<(*it)->get_station_index()<<"  "<<b_return<<endl;
	}

//	tree->traverse_inorder(tree->root);
	cout<<"Tree height is "<<tree->tree_height<<endl;
	node<int> *returned_node = tree->search(0);
	cout<<returned_node->data<<" "<<returned_node->height<<endl;
	node<int> *rhs = tree->root;
//	cout<<rhs->data<<" "<<rhs->height<<endl;
	rhs = rhs->rhs;
	node<int> min, max;
//	cout<<"d 1"<<endl;
	tree->find_min_from(rhs, min);
//	cout<<"d 2"<<endl;
	tree->find_max_from((tree->root)->lhs, max);
	cout<<"min in right branch is "<<min.data<<" "<<min.height<<endl;
	cout<<"max in left branch is "<<max.data<<" "<<max.height<<endl;

	cout<<"depth is "<<tree->find_depth(tree->root)<<endl;
	cout<<"left branch depth is "<<tree->find_depth((tree->root)->lhs)<<endl;
	cout<<"right branch depth is "<<tree->find_depth((tree->root)->rhs)<<endl;
	cout<<"balance factor is "<<tree->balance_factor(tree->root)<<endl;
	cout<<"tree is balanced? "<<tree->is_balanced(tree->root)<<endl;

	cout<<"tree root "<<(tree->root)->data<<endl;
//	delete[] tree->root;
	delete tree;
	return 0;
}
