#include <iostream>

using namespace std;

//create a structure of a binary tree node
    struct node {
        int data = 0 ;
        node * left = NULL ;
        node * right = NULL ;

    };
//create a new node of binary search tree using the structure
    node * createNewNode (int value){
        node * newNode = new node ();
        newNode -> data = value ;
        newNode -> left = NULL ;
        newNode -> right = NULL ;
        return newNode ;
    }

//recursive function to insert elements into binary search tree
     node * Insert(node *root, int value)
    {
        // check If the tree is empty
        if (root == NULL) {
            //return a new Node  if root is null
            return createNewNode(value);
        }

       //check if the data of the root is less than the value to be inserted
        if (root-> data < value ) {
            // Traverse to the right place and insert the node
            root-> right = Insert(root->right, value);
        }
        // if the data of the root is greater than the value to be inserted
        else {
            //Traverse to the right place and insert the node
            root-> left = Insert(root->left, value);
        }
         // Return 'root' node  after insertion.
            return root;
    }

// function return sum of all elements which is
//less or equal to the kth smallest element in the binary search tree
int kth_smallest_elements_sum(node *root, int k, int &Count)
{
	// base case , check if the root is equal to null (reached the leaves)
	if (root == NULL)
		return 0;
    // base case , check if the count is greater than k (the sum of the smallest kth elements is calculated)
	if (Count > k)
		return 0;
    //recursion
	// calculating the sum of elements in left subtree
	int result = kth_smallest_elements_sum(root->left, k, Count);
	//check if the count is greater than or equal k
	if (Count >= k)
		return result;

	// Adding the data of the root
	result = result + root-> data;

	// adding the current node
	Count++;
	//check if the count is equal to k
	if (Count == k)
	return result;

	// check if count is less than k
	if (Count < k){
    //return right subtree nodes
	return result + kth_smallest_elements_sum(root-> right, k, Count);
	}
}

// Wrapper over kth_smallest_elements_sum()
    int kthSmallestElementSum(struct node *root, int k)
    {
    int Count = 0;
    kth_smallest_elements_sum(root, k, Count);
    }


int main()
{

    cout << " - test case 1 - " << endl ;
	node *root1 = NULL;
	root1 = Insert(root1, 54);
	root1 = Insert(root1, 51);
	root1 = Insert(root1, 49);
	root1 = Insert(root1, 52);
	root1 = Insert(root1, 75);
	root1 = Insert(root1, 74);
	root1 = Insert(root1, 85);

	int k = 3;
    cout <<"Sum of kth smallest elements is " << kthSmallestElementSum(root1, k) <<endl;
    cout << "---------------------------------------------------------------" << endl ;


    cout << " - test case 2 - " << endl ;
	node *root2 = NULL;
	root2 = Insert(root2, 8);
	root2 = Insert(root2, 7);
	root2 = Insert(root2, 2);
	root2 = Insert(root2, 10);
	root2 = Insert(root2, 9);
	root2 = Insert(root2, 13);

	 k = 3;
    cout <<"Sum of kth smallest elements is " << kthSmallestElementSum(root2, k) <<endl;
    cout << "---------------------------------------------------------------" << endl ;



    cout << " - test case 3 - " << endl ;
	node *root3 = NULL;
	root3 = Insert(root3, 8);
	root3 = Insert(root3, 5);
	root3 = Insert(root3, 2);
	root3 = Insert(root3, 3);
	root3 = Insert(root3, 7);
	root3 = Insert(root3, 11);

    k = 5;
    cout <<"Sum of kth smallest elements is " << kthSmallestElementSum(root3, k) <<endl;
    cout << "---------------------------------------------------------------" << endl ;


    cout << " - test case 4 - " << endl ;
	node *root4 = NULL;
	root4 = Insert(root4, 20);
	root4 = Insert(root4, 8);
	root4 = Insert(root4, 4);
	root4 = Insert(root4, 12);
	root4 = Insert(root4, 10);
	root4 = Insert(root4, 14);
	root4 = Insert(root4, 22);

	k = 3;
    cout <<"Sum of kth smallest elements is " << kthSmallestElementSum(root4, k) <<endl;
    cout << "---------------------------------------------------------------" << endl ;


    cout << " - test case 5 - " << endl ;
	node *root5 = NULL;
	root5 = Insert(root5, 8);
	root5 = Insert(root5, 3);
	root5 = Insert(root5, 1);
	root5 = Insert(root5, 6);
	root5 = Insert(root5, 4);
	root5 = Insert(root5, 7);
	root5 = Insert(root5, 10);
	root5 = Insert(root5, 14);
	root5 = Insert(root5, 13);

    k = 4;
    cout <<"Sum of kth smallest elements is " << kthSmallestElementSum(root5, k) <<endl;
    cout << "---------------------------------------------------------------" << endl ;



    cout << " - test case 6 - " << endl ;
	node *root6 = NULL;
	root6 = Insert(root6, 40);
	root6 = Insert(root6, 30);
	root6 = Insert(root6, 25);
	root6 = Insert(root6, 35);
	root6 = Insert(root6, 50);
	root6 = Insert(root6, 45);
	root6 = Insert(root6, 60);

	k = 5;
    cout <<"Sum of kth smallest elements is " << kthSmallestElementSum(root6, k) <<endl;
    cout << "---------------------------------------------------------------" << endl ;



	return 0;
}
