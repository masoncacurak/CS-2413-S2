// =======================================================================
// HW13: Implement a Binary Search Tree which can be converted to AVL Tree 
// =======================================================================

// In this assignment, we will implement an AVL tree which can also do 
// standard Binary Search Tree adding and removal.  

// You can add new variables and functions in both classes. However, you should 
// implement the following given functions because they will be called in the main 
// function to test part of your implementation. (Check "main" function for more details.)
// 1. PreTraverse()
// 2. GetRoot()
// 3. Add()
// 4. Remove()
// 5. Add_AVL()
// 6. Remove_AVL()
// 7. Height()

#include <iostream>
using namespace std;

class Node {
    private:
	int key;
    int height;
	Node* p_left; 
	Node* p_right;
	Node* p_parent;

public:
	void Set_key(int x) {
        key = x;
    }

	int Get_key() {
        return key;
    }

	void Set_left(Node *p) {
        p_left = p;
    }

	void Set_right(Node* p) {
        p_right = p;
    }

	void Set_parent(Node* p) {
        p_parent = p;
    }

    void Set_height(int h) {
        height = h;
    }

	Node* Get_left() {
        return p_left;
    }

	Node* Get_right() {
        return p_right;
    }

	Node* Get_parent() {
        return p_parent;
    }

    int Get_height() {
        return height;
    }

	Node() {
        key = 0;
	    p_left = NULL;
	    p_right = NULL;
	    p_parent = NULL;
    }
};

class AVL {

private:
	
	// This is root of the AVL
	Node* root;

    Node* RemoveAVLRecursive(Node* p, int key) {
		if (p == nullptr) {
			return p;
		}

		if (key < p -> Get_key()) {
		    p -> Set_left(RemoveAVLRecursive(p -> Get_left(), key));
		}
		    
        else if (key > p -> Get_key()) {
		    p -> Set_right(RemoveAVLRecursive(p -> Get_right(), key));

		} else {
			if (p -> Get_left() == nullptr || p -> Get_right() == nullptr) {
				Node* tNode = p -> Get_left() ? p -> Get_left() : p -> Get_right();

				if (tNode == nullptr) {
					tNode = p;
					p = nullptr; 

				} else {
				    *p = *tNode;  
				}
				delete tNode; 

			} else {
				Node* tNode = MinValueNode(p -> Get_right()); 
			    p -> Set_key(tNode -> Get_key());
				p -> Set_right(RemoveAVLRecursive(p -> Get_right(), tNode -> Get_key()));
			}
		}

		if (p == nullptr) {
            return p;
        }

		p = BalanceNode(p);
	    return p; 
    }

    // Gets the balances of node p
    int GetBalance(Node* p) {
		if (p == nullptr) {
			return 0;
		}
		return Depth(p -> Get_left()) - Depth(p -> Get_right());
	}

    // checks to see what rotations need to happen
	Node* BalanceNode(Node* p) {
		int balance = GetBalance(p);
	    if (balance > 1 && GetBalance(p -> Get_left()) >= 0) {
			return Rotate_cw(p);
		}
		
		if (balance > 1 && GetBalance(p -> Get_left()) < 0) {
			p -> Set_left(Rotate_cc(p -> Get_left()));
		    return Rotate_cw(p);
	    }

		if (balance < -1 && GetBalance(p -> Get_right()) <= 0) {
		    return Rotate_cc(p);
	    }
	
		if (balance < -1 && GetBalance(p -> Get_right()) > 0) {
			p -> Set_right(Rotate_cw(p -> Get_right()));
		    return Rotate_cc(p);
	    }

	    return p;
    }

	// gets the depth of the nodes
	int Depth(Node* p) {
		if (p == nullptr) {
			return 0;
		}
	    return max(Depth(p -> Get_left()), Depth(p -> Get_right())) + 1;
    }
        
    // gets the min value for a node
    Node* MinValueNode(Node* node) {
		Node* current = node;
		while (current && current -> Get_left() != nullptr) {
			current = current -> Get_left();
		}      
		return current;
	}
	
    // recursively searches for a node based on a key
    Node* SearchRecursive(Node* node, int key) {
		if (node == nullptr || node -> Get_key() == key) {
			return node;
		}

		if (key > node -> Get_key()) {
			return SearchRecursive(node -> Get_right(), key);
		} else { 
		    return SearchRecursive(node -> Get_left(), key);
		}
	}

public:

	// This function implements pre-order traverse, starting from the root, and prints the traveres sequence
    // (with no space between nodes). You can use the function you implemented in HW10 (by slightly modifying it).
    // This function is only used to test if your updated AVL/BST is correct.
	void PreTraverse() {
	    PreOrderTraversal(root);
	}

    void PreOrderTraversal(Node* input) {
        if (input == nullptr) {
            return;
        }

        cout << input -> Get_key();
        PreOrderTraversal(input -> Get_left());
        PreOrderTraversal(input -> Get_right());
    }

    // helper method to help add to a tree that balences and rotates as needed
    Node* addAvlHelper(Node* root, Node* p) {
        if (root == NULL) {
            return p;
        }

        if (p -> Get_key() < root -> Get_key()) {
            root -> Set_left(addAvlHelper(root -> Get_left(), p));
        } 
        else if (p -> Get_key() > root -> Get_key()) {
            root -> Set_right(addAvlHelper(root -> Get_right(), p));
        } else {
            return root;
        }

        int left = Height(root -> Get_left());
        int right = Height(root -> Get_right());
        int balance = left - right;

        if (balance > 1 && p -> Get_key() < root -> Get_left() -> Get_key()) {
            return Rotate_cw(root);
        }
 
        if (balance < -1 && p -> Get_key() > root -> Get_right() -> Get_key()) {
            return Rotate_cc(root);
        }

        if (balance > 1 && p -> Get_key() > root -> Get_left() -> Get_key()) {
            root -> Set_left(Rotate_cc(root -> Get_left()));
            return Rotate_cw(root);
        }

        if (balance < -1 && p -> Get_key() < root -> Get_right() -> Get_key()) {
            root -> Set_right(Rotate_cw(root -> Get_right()));
            return Rotate_cc(root);    
        }
        return root;
    }
	    
    // This function returns the root node.  Normally we don't need it. Here we 
	// just it to evaluate your Height function. See main function test case 5 for details.
	Node* GetRoot() {
        return root;
    }

	// This function performs search  on the current AVL with "key". It returns address of a matching 
	// node, or returns NULL if no  matching node is found. 
	Node* Search(int key) {
        return SearchRecursive(root, key); 
    }

	// This function adds a new node at  "p" to AVL without considering  any violation of AVL property. 
	// (So just standard BST adding.) It can return a proper address.
	Node* Add(Node* p) {
        Node* tNode = root;
        Node* pNode = NULL;
        while (tNode != NULL) {
            pNode = tNode;

            if (p -> Get_key() < tNode -> Get_key()) {
                tNode = tNode -> Get_left();
            } else {
                tNode = tNode -> Get_right();
            }
        }
        if (pNode == NULL) {
            root = p;
        }
        else if (p -> Get_key() < pNode -> Get_key()) {
            pNode -> Set_left(p);
        } else {
            pNode -> Set_right(p);
        }
        return p;
    }

	// This function removes a node with  "key" from AVL without considering  any violation of AVL property. 
	// (So just standard BST removal.)  For simplicty, to fill holes, let  us only use the recursive algorithm 
	// that looks for the max/min node in  the left/right subtress of the hole.  It can return a proper address.
	Node* Remove(int key) {
        Node* target = root;
        Node*prev = NULL;
        while (target != NULL && target -> Get_key() != key) {
            prev = target;

            if (key < target -> Get_key()) {
                target = target -> Get_left();
            } else {
                target = target -> Get_right();
            }
        }
        
        if (target == NULL) {
            return root;
        }

        if (target -> Get_left() == NULL || target -> Get_right() == NULL) {
            Node* myNode;

            if (target -> Get_left() == NULL) {
                myNode = target -> Get_right();
            } else {
                myNode = target -> Get_left();
            }

            if (prev == NULL) {
                free(target);
                return myNode;    
            }

            if (target == prev -> Get_left()) {
                prev -> Set_left(myNode);
            } else {
                prev -> Set_right(myNode);
            }
            free(target);      
        } else {
            Node* yourNode = NULL;
            Node* tNode;
            tNode = target -> Get_right();

            while (tNode -> Get_left() != NULL) {
                yourNode = tNode;
                tNode = tNode -> Get_left();
            }

            if (yourNode != NULL) {
                yourNode -> Set_left(tNode -> Get_right());
            } else {
                target -> Set_right(tNode -> Get_right());
            }

            tNode -> Set_key(target -> Get_key());
            free(tNode);
        }
        return root;
    }

	// This function adds a new node  stored at "p" to AVL and performs  necessary rotations to restore 
	// the AVL property.
	void Add_AVL(Node* p) {
        root = addAvlHelper(root, p);
    }

	// This function removes a node  with "key" from AVL and performs 
	// necessary rotations to restore  the AVL property.
	void Remove_AVL(int key) {
        root = RemoveAVLRecursive(root, key);
    }

	// ! This function returns height of a subtree rooted at "p". 
	int Height(Node* p) {
    	if (p == NULL) {
        	return -1;
    	}
    	int leftHeight = Height(p->Get_left());
    	int rightHeight = Height(p->Get_right());
        return (max(leftHeight, rightHeight) + 1);
	}

    // ! This function performs clock-wise rotation at node "p". It only does
	// rotation and does not consider the type of violation scenario.
	// It can return a proper address.
	Node* Rotate_cw(Node* p) {

    	// Perform clockwise rotation at node p
    	Node* newRoot = p->Get_left();
    	p->Set_left(newRoot->Get_right());
		
    	if (newRoot->Get_right() != NULL) {
        	newRoot->Get_right()->Set_parent(p);
    	}

    	newRoot->Set_right(p);
    	p->Set_parent(newRoot);
    	return newRoot;
	}

	// ! This function performs counter clock-wise rotation at node "p". 
	// It only does rotation and does not consider the type of violation 
	// scenario. It can return a proper address.
	Node* Rotate_cc(Node* p) {

    	// Perform counter-clockwise rotation at node p
    	Node* newRoot = p->Get_right();
    	p->Set_right(newRoot->Get_left());

    	if (newRoot->Get_left() != NULL) {
        	newRoot->Get_left()->Set_parent(p);
    	}

    	newRoot->Set_left(p);
    	p->Set_parent(newRoot);
    	return newRoot;
	}

    // ! This function checks if there is a violation at a node p, and  return the violation scenario. 
	// It returns a string of 
	// - "NO" if no violation 
	// - "LL" if it is left-left violation 
	// - "RR" if it is right-right violation
	// - "LR" if it is left-right violation
	// - "RL" if it is right-left violation
    string CheckViolation(Node* p) {
    	int leftHeight = Height(p->Get_left());
    	int rightHeight = Height(p->Get_right());
    	int balance = rightHeight - leftHeight;

    	if (balance > 1) {
        	if (Height(p->Get_right()->Get_right()) >= Height(p->Get_right()->Get_left())) {
            	return "RR";
        	} else {
            	return "RL";
        	}
    	} 
        else if (balance < -1) {
        	if (Height(p->Get_left()->Get_left()) >= Height(p->Get_left()->Get_right())) {
            	return "LL";
        	} else {
            	return "LR";
        	}
    	}
    	return "NO";
	}

	// This function intiailizes root = NULL.
	AVL() {
        root = NULL;
    }
};

int main() {

    // mode_test: indicate which function to test
    // model_avl: if 1, we do adding with AVL property
    // if 0, we do adding without AVL property (so just standard bst adding)
    // key_temp: keys of nodes to add to AVL initially
    // key_search:key of node for search/remove
    int mode_test, mode_avl, key_temp, key_search;

    Node* temp;
    
    // This is our AVL tree object.
    AVL tree;

    cin >> mode_test >> mode_avl >> key_search;

    while (cin >> key_temp) {

        temp = new Node;
        temp  ->  Set_key(key_temp);

        if (mode_avl == 0) {
            tree.Add(temp);
        }
        else if (mode_avl == 1) {
            tree.Add_AVL(temp);
        }
    }

    // Mode 0: Test "Add" function.
    if (mode_test == 0) {
        tree.PreTraverse();
    }
    
    // Mode 1: Test "Add_AVL" function
    else if (mode_test == 1) {
        tree.PreTraverse();
    }

    // Mode 2: Test "Search" function
    else if (mode_test == 2) {
        temp = tree.Search(key_search);
        if (temp == NULL) {
            cout << -1;
        } else {
            cout << temp  ->  Get_key();
        }
    }

    // Mode 3: Test "Remove" function
    else if (mode_test == 3) {
        tree.Remove(key_search);
        tree.PreTraverse();
    }

    // Mode 4: Test "Remove_AVL" function
    else if (mode_test == 4) {
        tree.Remove_AVL(key_search);
        tree.PreTraverse();
    }

    // Mode 5: Test "Height" function
    else if (mode_test == 5) {
        cout << tree.Height(tree.GetRoot());
    }

    return 0;
}