#include "List.h"
#include "Tree.h"


template <typename T>
void printArray(T* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
	Tree<int> tree;
 	int sizeSortAsc = 0;
	int sizeSortDesc = 0;
	int n = 10;
	int* arrOrigin = new int[n] {1, 7, 45, 2, 7, 8, 9, 2, 1,10 };
	int* arrSortedAsc = new int[n];
	int* arrSortedDesc = new int[n];
	cout << "Origin Array:" << endl;
	printArray(arrOrigin, n);

	tree.addArray(arrOrigin, n);
	tree.sortAscending(arrSortedAsc, sizeSortAsc);
	tree.sortDescending(arrSortedDesc, sizeSortDesc);

	cout << "\nSorted Array:" << endl;
	printArray(arrSortedAsc, sizeSortAsc);
	printArray(arrSortedDesc, sizeSortDesc);
	cout << "\nDone" << endl;


	Tree<int> treeList;
	list<int> listOrigin;
	list<int> listSorted;
	for (int i = 0; i < n; i++)
		listOrigin.push_back(arrOrigin[i]);

	cout <<  "\nOrigin List:" << endl;
	listOrigin.printAll();

	treeList.addList(listOrigin, n);
	treeList.sortAscendingList(listSorted);

	cout << "\nSorted List:" << endl;
	listSorted.printAll();
	cout << "\nDone" << endl;




	delete[] arrOrigin;
	delete[] arrSortedAsc;
	delete[] arrSortedDesc;
	return 0;
   
    



   
   
}