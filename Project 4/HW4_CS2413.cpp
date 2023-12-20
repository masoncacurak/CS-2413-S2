// ==================================================================
// HW6: Implement Recursive Functions of Binary Search and Merge Sort 
// ==================================================================

// In this assignment, we will implement a recursive function for binary search 
// based on array, and another recursive function for merge sort based on singly linked list. 

// The Node class (used to construct list) has been defined to you. Do not modify it. 

// In the main function, write a while loop to take inputs and use them to construct a linked list. 
// Then, input this list (its head pointer) into the merge sort function.
 
#include <iostream>
using namespace std;

// ! Do Not Modify
class Node {

public:
	void Set_SID(int x);
	int Get_SID();
	void Set_Pnext(Node *p);
	Node * Get_Pnext();
	Node();

private:
	int SID;
	Node* p_next;
};

void Node::Set_SID(int x) {
	SID = x;
}

int Node::Get_SID() {
	return SID;
}

void Node::Set_Pnext(Node* p) {
	p_next = p;
}

Node* Node::Get_Pnext() {
	return p_next;
}

Node::Node() {
	SID = -1;
	p_next = NULL;
}

// TODO: Task 1 ~ Complete the following recursive binary search function 

// BSearch function takes the list as input, outputs index of the search key & returns -1 if the key isn't in list. 
// At the end of all recursive calls, function should return the index of a matching key in the input array. 
// In every recursion, print out the number that is being compared with the search key. 
int BSearch(int key, int arr[], int left, int right) {
    if (left <= right) {
        int middle = left + (right - left) / 2;

        // Prints num being compared with key
        cout << arr[middle];

        if (arr[middle] == key) {
            return middle;
        }

        if (arr[middle] > key) {
            // Search in the left half
            return BSearch(key, arr, left, middle - 1);
        }

        // Search in the right half
        return BSearch(key, arr, middle + 1, right);
    }
    return -1;
}

// TODO: Task 2 ~ Complete the following recursive merge sort function.

// Merge function takes sorted sublists left and right as inputs and combines them into a single list
Node* Merge(Node* left, Node* right) {
    Node* result = NULL;

    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

	// Comparing values of nodes left and right to merge them
    if (left->Get_SID() <= right->Get_SID()) {
        result = left;
        result->Set_Pnext(Merge(left->Get_Pnext(), right));
    } else {
        result = right;
        result->Set_Pnext(Merge(left, right->Get_Pnext()));
    }

    return result;
}

// Takes the unsorted linked list as input and recursively divides into smaller sublists by finding middle point
Node* MSort(Node* head) {
    if (head == NULL || head->Get_Pnext() == NULL) {
        return head;
    }

	// Splitting list into halves
    Node* middle = head;
    Node* ptr = head->Get_Pnext();

    while (ptr != NULL) {
        ptr = ptr->Get_Pnext();

        if (ptr != NULL) {
            middle = middle->Get_Pnext();
            ptr = ptr->Get_Pnext();
        }
    }

    Node* left = head;
    Node* right = middle->Get_Pnext();
    middle->Set_Pnext(NULL);

	// Recursively sorting both halves
    left = MSort(left);
    right = MSort(right);

    return Merge(left, right);
}

int main() {
	// This array holds the list for binary search. 
	int L1[11];

	// This is the head pointer which holds the list for merge sort. 
	Node* L2 = NULL;

	int mode, temp, key; 

	cin >> mode >> key;

	// The first loop takes input for binary search. For simplicity, we assume there are 
	// always 11 input integers that are unique and sorted in ascending order. 
	for (int i = 0; i < 11; i++) {
		cin >> L1[i];
	}

	// TODO: Task 3 ~ The second loop takes input for merge sort. 
	// The head pointer "L2" has been declared above for you. Use it to store head of the constructed list. 
	Node* tail = NULL;
	while (cin >> temp) {
    	Node* newNode = new Node();
    	newNode->Set_SID(temp);
    	newNode->Set_Pnext(NULL);

    	// If list is empty, set new node as head
    	if (L2 == NULL) {
        	L2 = newNode;
        	tail = newNode;
    	} else {
        	// Else, add new node to end of list
        	tail->Set_Pnext(newNode);
        	tail = newNode;
    	}
	}

	// Mode 0: Test BSearch()
	int r = sizeof(L1) / sizeof(L1[0]);
	if (mode == 0) {
		
		// TODO: Task 4: Apply binary search
		cout << BSearch(key, L1, 0, r - 1);
	}

	// Mode 1: Test MSort()
	else if (mode == 1) {
		
		// TODO: Task 5: Apply merge sort.	
		L2 = MSort(L2);
		Node* temp = L2;
		while (temp != NULL) {
			cout << temp->Get_SID();
			temp = temp->Get_Pnext();
		}
	}

	return 0;
}

