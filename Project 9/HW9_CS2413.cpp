// ========================================
// HW15: Implement Min Heap
// ========================================

// In this assignment, we will implement a Min Heap. You can choose to implement it based on linked-list or array. 
// The provided template assumes array-based implementation, but feel free to modify it as needed.
// Just make sure to keep the in/output (format) of all functions that are tested in the main function. 

// Your major task is to implement the heap class. In addition, in the main function, test mode 3, 
// you need to implement an application of your heap to sort an array of nodes based on their keys. 

#include <iostream>
#include <queue>
using namespace std;

// The node class has been defined for you. 
class Node {

private:
	int key;
	// satellite data 

public:
	void Set_key(int x);
	int Get_key();
	Node();
};

void Node::Set_key(int x) {
	key = x;
}

int Node::Get_key() {
	return key;
}

Node::Node() {
	key = -1;
}

// The MinHeap class has been structured for you. Please complete the functions and feel free 
// to add variables or functions to facilitate your own designs and implementations. 

// However, Add, Remove and Root functions must be implemented based 
// on the given definitions (because we test them in the main function)

class MinHeap {

private:
	Node* root;
	int ArraySize;
	int HeapSize;

public:

	// This function prints keys in the heap based on breadth-first traverse 
	// (do not add space between keys; do not change line at any time).
	// You may use a modified version of the BS traverse function in HW10. 
	void BSTraverse() {
		for (int i = 0; i < HeapSize; i++) {
			cout << root[i].Get_key();
		}
	}

	// This function adds a node at address p to the heap. 
	void Add(Node* p) {
		root[HeapSize] = *p;
		int index = HeapSize;
		HeapSize++;

		while (index > 0) {
			int pIndex = (index - 1) / 2;

			if (root[pIndex].Get_key() > root[index].Get_key()) {
				Node temp = root[index];
        		root[index] = root[pIndex];
        		root[pIndex] = temp;
				index = pIndex;
			} else {
				break;
			}
		}
	}

	// This function removes root. 
	void Remove() {
		if (HeapSize == 0) {
			// Nothing to remove
        	return; 
    	}

    	// Replace root node with last node in the heap
    	root[0] = root[HeapSize - 1];
    	HeapSize--;

    	// Perform heapify-down to maintain the min-heap property
    	int currentIndex = 0;
    	while (true) {
        	int leftChild = 2 * currentIndex + 1;
        	int rightChild = 2 * currentIndex + 2;
        	int smallest = currentIndex;

        	// Find smallest value among current node, left child, and right child
        	if (leftChild < HeapSize && root[leftChild].Get_key() < root[smallest].Get_key()) {
            	smallest = leftChild;
        	}

        	if (rightChild < HeapSize && root[rightChild].Get_key() < root[smallest].Get_key()) {
            	smallest = rightChild;
        	}

        	if (smallest == currentIndex) {
            	break;
        	}

        	// Swap current node with smallest child
        	Node temp = root[currentIndex];
        	root[currentIndex] = root[smallest];
        	root[smallest] = temp;

        	currentIndex = smallest;
    	}
	}

	// This function returns root. 
	Node* Root() {
		if (HeapSize > 0) {
        	return &root[0];
    	}

		// Return nullptr if heap is empty
    	return nullptr; 
	}

	void Resize(int n) {
		// Resize array to accommodate n elements
    	Node* newRoot = new Node[n];
    	for (int i = 0; i < HeapSize; ++i) {
        	newRoot[i] = root[i];
    	}

    	delete[] root;
    	root = newRoot;
    	ArraySize = n;
	}

	// You can design the constructor in any way you like e.g., you 
	// may initialize heap size to zero or to some large enough 
	// In the latter case, you should properly mark unused array cells. 
	MinHeap() {
    	ArraySize = 10;
    	HeapSize = 0;
    	root = new Node[ArraySize];
	}

	
};

int main() {

	// mode: Test mode 
	// key: Keys of nodes to be added to heap 
	int mode, key;
	cin >> mode; 

	// Adding nodes to heap. 
	MinHeap heap;
	Node* temp;
	while (cin >> key) {
		temp = new Node;
		temp->Set_key(key);	
		heap.Add(temp);
	}

	// Mode 0: Test Add()
	if (mode == 0) {
		heap.BSTraverse();
	}

	// Mode 1: Test Root()
	else if (mode == 1) {
		temp = heap.Root();
		cout << temp->Get_key();
	}

	// Mode 2: Test Remove()
	else if (mode == 2) {
		heap.Remove();
		heap.BSTraverse();
	}

	// Mode 3: Implement heap sort.
	else if (mode == 3) {

    	// First construct an array of nodes.
    	// The keys are 5, 4, 3, 2, 1 in "arr".
    	// Do not modify this part.
    	Node arr[5];
		for (int i = 0; i < 5; i++) { 
        	arr[i].Set_key(5 - i);
    	}

    	// Adds nodes from arr to the MinHeap
    	for (int i = 0; i < 5; i++) {
        	heap.Add(&arr[i]);
    	}

    	// Removes nodes from MinHeap and places them back in arr
    	for (int i = 0; i < 5; i++) {
        	Node* sortedNode = heap.Root();

        	if (sortedNode) {
            	arr[i] = *sortedNode;
            	// Remove node after placing it in array
            	heap.Remove();
        	}
    	}

    	// At last, we print keys in arr.
    	// They should be 1, 2, 3, 4, 5.
    	// Do not modify this part.
    	for (int i = 0; i < 5; i++) {
        	cout << arr[i].Get_key();
    	}
	}

	return 0;
}

