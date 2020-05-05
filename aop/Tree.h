#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Tree {
private:
	template <typename T>
	struct node {
		T d;
		node* l;
		node* r;
	};

	node<T>* tree;
public:
	~Tree() { deleteTree(tree); }


	void addElement(T elem) {
		node<T>* temp = new node<T>();
		temp->d = elem;
		temp->l = NULL;
		temp->r = NULL;


		if (tree == NULL) { tree = temp; }
		else {
			node<T>* i = tree;
			while ((elem < i->d) && (i->l != NULL) || (i->d < elem) && (i->r != NULL)) {
				if ((elem < i->d) && (i->l != NULL)) { i = i->l; }
				else { i = i->r; }
			}
			if (elem <= i->d) { i->l = temp; }
			else { i->r = temp; }
		}
	}
	 
	void treeLeftUp(node<T>* tree, T* arrSorted, int& k) {
		if (tree != NULL){

			treeLeftUp(tree->l, arrSorted, k);
			arrSorted[k] = tree->d;
			k++;
			treeLeftUp(tree->r, arrSorted, k);

		}
		
	}

	void treeRightUp(node<T>* tree, T* arrSorted, int& k) {
		if (tree != NULL){

			treeRightUp(tree->r, arrSorted, k);
			arrSorted[k] = tree->d;
			k++;
			treeRightUp(tree->l, arrSorted, k);

		}
	}


	void treeLeftUpList(node<T>* tree, list<T>& list) {
		if (tree != NULL) {

			treeLeftUpList(tree->l,list);
			list.push_back(tree->d);
			treeLeftUpList(tree->r,list);

		}
	}
	void sortAscendingList(list<T>& list) {
		node<T>* temp = tree;
		treeLeftUpList(tree,list);
	}



	void sortAscending(T* arrSorted, int& k) { 
		node<T>* temp = tree;
		treeLeftUp(tree, arrSorted, k); 
	}
	void sortDescending(T* arrSorted, int& k) { 
		node<T>* temp = tree;
		treeRightUp(temp, arrSorted, k);
	}


	void addArray(T* arr, int n) {
		for (int i = 0; i < n; i++) {
			addElement(arr[i]);
		}
	}

	void addList(list<T> list, int n) {
		for (int i = 0; i < n; i++) {
			addElement(list.value());
			list.pop();
		}
	}




	void deleteTree(node<T>* tree) {
		if (tree == NULL) return;

		deleteTree(tree->l);
		deleteTree(tree->r);

		delete tree;
	}

};