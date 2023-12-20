// ==============================================================
// HW7: Implement Hash Table with the Separate Chaining Technique 
// ==============================================================

// In this assignment, we will implement a hash table which uses separate chaining 
// to deal with collisions. The chains should be implemented using singly linked list. 
// Your task is to develop a HashTable class based on the following template. 

// TODO: You should complete six member functions. 

#include <iostream>
using namespace std;

// ! Do not modify Node class... Just use it to construct lists. 
class Node {
private:
	int key;
	Node* p_next;
	// There could be other satellite data here... we omit them for simplicity
public:
	void Set_key(int x);
	int Get_key();
	void Set_p(Node* p);
	Node* Get_p();
	Node();
};

Node::Node() {
	key = -1;
	p_next = NULL;
}
void Node::Set_key(int x) {
	key = x;
}
int Node::Get_key() {
	return key;
}
void Node::Set_p(Node* p) {
	p_next = p;
}
Node* Node::Get_p() {
	return p_next;
}

// Implement a hash table whose elements are pointers. Each pointer points to a linked 
// list that holds the (collided) students.

// The HashTable class is structured as follows. Do not modify the structure. 
// Your task is to complete the member functions. 

class HashTable {
private:

	// Size of the hash table. 
	int size;
	
	// Hash function "h"... takes "key" as input and returns a hash code h(key) = key % divisor.
	int hash(int key) {
		return key % size;
	}

	// This is a pointer to the hash table. Note it is a pointer of pointer. 
	Node** table;

	
public:

	// Function creates a hash table (through dynamic memory allocation) and initializes all cells to NULL.

	// It should create a table of the smallest necessary size N, which 
	// depends on the input divisor (of the modulo hash function).

	// This function should also update the private variable "size" to N. 
	void CreateTable(int divisor) {
		size = divisor;
    	table = new Node*[size];
    	for (int i = 0; i < size; ++i) {
        	table[i] = NULL;
    	}
	}

	// This function searchs for a student whose SID = key. If a student is found, 
	// return address of the student node. Otherwise, return NULL.
	Node* Search(int key) {
		int index = hash(key);
    	Node* temp = table[index];
    	while (temp != NULL) {
        	if (temp->Get_key() == key) {
            	return temp;
        	}
        	temp = temp->Get_p();
    	}
    	return NULL;
	}

	// This function adds a student (address stored at "temp") to the hash table. 
	void Add(Node* temp) {
		int index = hash(temp->Get_key());
    	temp->Set_p(table[index]);
    	table[index] = temp;
	}


	// This function removes a student whose SID = key from the table. If the student 
	// is not in the table, it does nothing. 
	void Remove(int key) {
		int index = hash(key);
    	Node* current = table[index];
    	Node* previous = NULL;

    	while (current != NULL && current->Get_key() != key) {
        	previous = current;
        	current = current->Get_p();
    	}

    	if (current == NULL) {
        	return;
    	}

    	if (previous == NULL) {
        	// Student is first node in list
        	table[index] = current->Get_p();
    	} else {
        	// Student is middle or end of list
        	previous->Set_p(current->Get_p());
    	}
    	delete current;
	}

	// This function returns the table size. Specifically, it returns value of the 
	// private variable "size". 
	int Get_Size() {
		return size;
	}

	// ! Do not modify
	// This is the constructor. 
	HashTable();

	// ! Do not modify
	// This is the print function. It is given to you and used to examine the correctness
	// your created/updated hash table.  
	void PrintTable();
};

// This is the constructor. It is defined for you. 
HashTable::HashTable() {
	table = NULL;
	size = 0;
}

// ! Do not modify print function
// This function will screen the table line by line, and print all SIDS in the linked list from head to tail. 
// This function is used to test if your constructed/updated table is correct
void HashTable::PrintTable() {
	Node* temp = NULL;
	for (int i = 0; i < size; i++) {
		temp = table[i];
		while (temp != NULL) {
			cout << temp->Get_key() << '\n';
			temp = temp->Get_p();
		}
	}
}

int main()
{
	int mode, temp;

	// This key is used as a search key to test the search and remove functions. 
	int key;

	// Divisor is used by the hash function and CreateTable() function to automatically determine the table size. 
	int divisor; 

	Node* Student;

	HashTable x;

	cin >> mode >> key >> divisor;

	x.CreateTable(divisor);

	while (cin >> temp) {

		Student = new Node;

		Student->Set_key(temp);

		x.Add(Student);
	}

	// Mode 0: Test if your table size is correct 
	if (mode == 0) {
		cout << x.Get_Size();
	}
	// Mode 1: Test the "Add" function 
	else if (mode == 1) {
		x.PrintTable();
	}
	// Mode 2: Test the "Search" function 
	else if (mode == 2) {
		Student = x.Search(key);
		if (Student == NULL) {
			cout << -1;
		}
		else {
			cout << Student->Get_key();
		}
	}
	// Mode 3: Test the "Remove" function 
	else if (mode == 3) {
		x.Remove(key);
		x.PrintTable();
	}

	return 0;
}