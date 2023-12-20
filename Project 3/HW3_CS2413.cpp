// ========================================
// HW4: Implement a Singly List Class
// ========================================
 
// In this assignment, we will implement a singly linked list class based on a node class. 

// The List class has been partly defined for you. It has one private variable "head" and several 
// public functions. The constructor and Print function have been defined for you (do not modify them), 
// and your task is to implement other functions. 

// You can add new member functions to the List class but not new member variables. In addition, you 
// cannot use any existing list-related library or function. 

#include <iostream>
using namespace std;

// ! Do not modify
class Node {

private:
	int SID;
	float GPA;
	Node* p_next;

public:
	void Set_SID(int x);
	void Set_GPA(float y);
	int Get_SID();
	float Get_GPA();
	void Set_Pnext(Node* p);
	Node* Get_Pnext();
	Node();
};

void Node::Set_SID(int x) {
	SID = x;
}

void Node::Set_GPA(float y) {
	GPA = y;
}

int Node::Get_SID() {
	return SID;
}

float Node::Get_GPA() {
	return GPA;
}

void Node::Set_Pnext(Node* p) {
	p_next = p;
}

Node* Node::Get_Pnext() {
	return p_next;
}

Node::Node() {
	SID = -1;
	GPA = -1;
	p_next = NULL;
}


// TODO: The List class has been partly defined for you. Complete its undefined member functions. 
class List {

private:
	Node* head;
public:
	// List function is defined for you.
	List();

	// Print function is defined for you.
	void PrtSID();

	// Create function creates a singly linked list based on inputs and assigns its head node's address to the "head" pointer.
	// ! The format of input should be as follows: sid_1 gpa_1 sid_2 gpa_2 sid_3 gpa_3...... 
	// Here, sid_i and gpa_i are SID and GPA of the i_th input student. A new node is always added to the head of the list. 
	// Finally, the process should terminate when an invalid input is given. 
	// There is no need to deal with the case of a valid sid followed by an invalid gpa. 
	
	void Create() {
		int sid;
		int gpa;
    	Node* newNode = nullptr;
    
    	while (cin >> sid >> gpa) {
        	if (sid < 0 || gpa < 0) {
            	break;
        	}

        	newNode = new Node();
        	newNode->Set_SID(sid);
        	newNode->Set_GPA(gpa);

        	newNode->Set_Pnext(head);
        	head = newNode;
    	}
	}

	// Lsize function returns the number of nodes in the list. (Return 0 if the list is empty)
	int Lsize() {
		int count = 0;
    	Node* current = head;

    	while (current != nullptr) {
        	count++;
        	current = current->Get_Pnext();
    	}
    	return count;
	}

	// Find function returns address of the node in the list whose SID = key. (Return NULL if no match is found)
	Node* Find(int key) {
		Node* current = head;

    	while (current != nullptr) {
        	if (current->Get_SID() == key) {
            	return current;
        	}
        	current = current->Get_Pnext();
    	}
    	return nullptr;
	}

	// Insert function inserts a new node (whose address is stored at "p") as the idx_th node in the list. 
	// Return 1 if insertion is successful and return -1 if idx is out of range. A valid range is [1, Lsize+1], 
	// where "1" means adding to head and "Lsize+1" means adding to tail. 
	int Insert(Node* p, int idx) {
    	if (idx < 1 || idx > Lsize() + 1) {
        	return -1;
    	}

    	if (idx == 1) {
     		p->Set_Pnext(head);
        	head = p;
        	return 1;
    	}

    	Node* current = head;
    	int count = 1;
    	while (count < idx - 1) {
        	current = current->Get_Pnext();
        	count++;
    	}

    	p->Set_Pnext(current->Get_Pnext());
    	current->Set_Pnext(p);

    	return 1;
	}

	// Remove function removes the idx_th node from the list. Return 1 if removal is successful and -1 if 
	// idx is out of range. A valid range is [1, Lsize], where "1" means removing head and "Lsize" means removing tail. 
	int Remove(int idx) {
    	if (idx < 1 || idx > Lsize()) {
        	return -1;
    	}

    	if (idx == 1) {
        	Node* temp = head;
        	head = head->Get_Pnext();
        	delete temp;
        	return 1;
    	}

    	Node* current = head;
    	int count = 1;

    	while (count < idx - 1) {
        	current = current->Get_Pnext();
        	count++;
    	}

    	Node* temp = current->Get_Pnext();
    	current->Set_Pnext(temp->Get_Pnext());
    	delete temp;

    	return 1;
	}

	// Reverse function reserves the list. For example, if the current list has three nodes A->B->C, after 
	// running Reverse the order should be C->B->A. 
	void Reverse() {
		Node* prev = nullptr;
    	Node* current = head;
    	Node* next = nullptr;

    	while (current != nullptr) {
        	next = current->Get_Pnext();
        	current->Set_Pnext(prev);

        	prev = current;
        	current = next;
    	}

    	head = prev;
	}

	// Clear function removes all nodes from the list (so it becomes an empty list). 
	void Clear() {
		while (head != nullptr) {
        	Node* temp = head;
        	head = head->Get_Pnext();
        	delete temp;
    	}
	}
};

// The constructor has been defined for you.
List::List() {
	head = NULL;
}

// The print function has been defined for you.
void List::PrtSID() {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->Get_SID();
		temp = temp->Get_Pnext();
	}
}

int main() {

	int mode, key, sid, idx;
	float gpa;

	// The first five inputs are for testing. 
	// * "mode" determines which function to test. 
	// * "key" is used to evaluate Find().
	// * "sid" and "gpa" are used to evaluate Insert().
	// * "idx" is used to evaluate Insert() and Remove().
	
	// After these inputs, the rest inputs are used to create the initial singly linked list. 
	cin >> mode >> key >> sid >> gpa >> idx; 

	// Declare a singly linked list named "x"
	List x; 

	// Input data to x. After this, a list should be created and stored at address "head".
	x.Create();

	// Mode 0: test Create()
	if (mode == 0) {
		x.PrtSID();
	}
	// Mode 1: test Lsize()
	else if (mode == 1) {
		cout << x.Lsize();
	}
	// Mode 2: test Find()
	else if (mode == 2) {
		Node* temp = x.Find(key);
		if (temp == NULL) {
			cout << -1;
		}
		else {
			cout << temp->Get_GPA();
		}
	}
	// Mode 3: test Insert()
	else if (mode == 3) {
		Node* temp = new Node; 
		temp->Set_SID(key);
		temp->Set_GPA(3.5);
		x.Insert(temp, idx);
		x.PrtSID();
	}
	// Mode 4: test Remove()
	else if (mode == 4) {
		x.Remove(idx);
		x.PrtSID();
	}
	// Mode 5: test Reverse()
	else if (mode == 5) {
		x.Reverse();
		x.PrtSID();
	}
	// Mode 6: test Clear()
	else if (mode == 6) {
		x.Clear();
		cout << x.Lsize();
	}

	return 0;
}


