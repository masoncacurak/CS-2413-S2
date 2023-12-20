**Data Structures S2:**
----------------
**Project 1:** Takes the student ID and GPA of five students as input and outputs the min, max, and mean GPA and stores the student IDs and corresponding GPAs in an array of object and outputs them.

**Project 2:** Implements basic vector functionalities such as obtaining the size, checking for emptiness, accessing elements by index, resizing, adding elements to the end, removing elements from the end, inserting elements at a specified index, and erasing elements from a specified index. The class employs dynamic memory allocation and pointer manipulation to manage its array of integer elements. The main function tests the various vector operations based on user-input modes and additional values, printing the size and elements of the vector after each operation. 

**Project 3:** Implements a singly linked list class and a node class. The list class includes functions for creating a linked list based on input SID and GPA pairs, determining the list size, finding a node with a specific SID, inserting and removing nodes at specified indices, reversing the list, and clearing the entire list. The main function reads input values to determine the testing mode and evaluates the corresponding list operations, such as creating, sizing, finding, inserting, removing, reversing, or clearing the list. The program operates with a user-defined linked list and allows testing various functionalities based on the specified mode, providing insights into the implementation and functionality of the linked list class.

**Project 4:** Implements recursive binary search and merge sort functions. The binary search function takes an array of unique and sorted integers, and a search key, recursively printing the numbers being compared and returning the index of the key if found. The merge sort function operates on a singly linked list, recursively splitting it until single-node sublists are obtained, and then merging them in a sorted manner. The main function reads user inputs to perform either binary search or merge sort based on the specified mode. For binary search, it searches for a key in a pre-defined array, while for merge sort, it constructs and sorts a linked list, printing the results. The program demonstrates the recursive nature of these algorithms and their application to both arrays and linked lists.

**Project 5:** Implements a hash table with separate chaining to handle collisions, utilizing singly linked lists for chains. The program defines a Node class for constructing linked list nodes. The HashTable class includes member functions for creating a hash table, searching for a student by Student ID (SID), adding a student to the table, removing a student by SID, and retrieving the table size. The CreateTable function dynamically allocates memory for the hash table based on a given divisor. The Add function adds a student to the table using separate chaining. The Search function looks for a student by SID and returns the node if found. The Remove function deletes a student from the table based on SID. The program reads user inputs to determine the mode of operation, including testing the table size, adding students, searching for a student, and removing a student, and prints the results accordingly. The provided PrintTable function aids in examining the correctness of the hash table.

**Project 6:** Implements a hash table using coalesced chaining to handle collisions. In this approach, instead of using a pointer "p_next" to hold the address of the next node, an integer "idx_next" is used to hold the position of the next node in the table. The program defines a Node class for constructing objects representing students with key values (Student IDs) and index values for chaining. The HashTable class includes member functions for creating a hash table, searching for a student by SID, adding a student, removing a student, and retrieving the table size. The CreateTable function dynamically allocates memory for the hash table based on a given divisor. The Search function looks for a student by SID and returns the index if found. The Add function adds a student to the hash table using linear probing for collision resolution. The table is resized and rehashed if it becomes full. The Remove function deletes a student from the table based on SID. The program reads user inputs to determine the mode of operation, including testing the "Add" function and resizing, checking the correctness of chains, testing the "Search" function, and testing the "Remove" function, and prints the results accordingly. The provided PrintTable and PrintChain functions aid in examining the correctness of the hash table and chains.

**Project 7:** Implements operations on a binary tree, defining a Node class for tree nodes. The Traverse function performs pre-order, post-order, in-order, or breadth-first traversal based on the input string. The Height function calculates the height of the list-based binary tree recursively. The Convert2Array function transforms the list-based tree into an array-based tree using breadth-first traversal and returns the resulting array. The main function reads a mode and executes corresponding test cases: traversing the tree in different orders, calculating the tree's height, and converting the tree to an array. The binary tree used for testing has specific key values assigned to nodes. Test cases demonstrate the functionality of the implemented tree operations.

**Project 8:** Implements an AVL tree, a self-balancing binary search tree. The code defines two classes: Node for the tree nodes and AVL for the AVL tree operations. The Node class contains methods for setting and getting key values, left and right child nodes, parent node, and height. The AVL class includes functions for pre-order traversal, getting the root node, adding a node to the AVL tree, removing a node from the AVL tree, calculating the height of a subtree, and performing AVL rotations. The main function reads user input to determine the test mode and AVL property, then performs various AVL tree operations based on the input mode, such as adding nodes, searching, removing, and checking the height. The tree maintains its AVL property by performing necessary rotations during add and remove operations.

**Project 9:** Implements a Min Heap using an array-based structure, with the MinHeap class containing functions for adding a node, removing the root node, retrieving the root node, resizing the heap, and performing breadth-first traversal. The main function allows testing various modes, including adding nodes to the heap, retrieving the root, removing the root, and implementing heap sort on an array of nodes. The Min Heap maintains the min-heap property, where each node's value is less than or equal to its children's values. The code demonstrates these functionalities and tests them under different scenarios, providing a foundation for heap operations and a heap-sort application on an array of nodes. The Node class, representing elements with integer keys, accompanies the MinHeap class.

**Project 10:** Implements an undirected graph and provides functions to perform various operations such as checking if there is an edge between two nodes, determining if there is a path from one node to another, calculating the degree of a node, and traversing the graph using both depth-first search and breadth-first search algorithms. The graph is represented as an adjacency matrix. The main function takes input parameters to determine the mode of testing (e.g., checking for edges, paths, or degrees) and executes the corresponding operations on the graph. 
