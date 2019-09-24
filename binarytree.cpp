// Code to Traverse a Binary Search tree in an inordered method and Deleting a Node 100 from the tree

#include <iostream>
#include <stdio.h>

using namespace std;

struct node
{

  // Creating a Node Structure with a Left Child Pointer, Right Child Pointer and Integer Data

  int data;
  node *left;
  node *right;
};

class tree
{
  // Creating the functions and pointers to be utilized
public:
  node *root; // Declaring the root pointer of the Binary Search tree
  tree()
  {
    // Constructor to declare Rooter as Null
    root = NULL;
  }

  // Function to enter the Other Elements other than the root

  node *createNode(node *temp, int val)
  {

    // Creating a new node with the entered value

    node *nd = new node;
    nd->data = val;
    nd->left = NULL;
    nd->right = NULL;

    /* Comparing the entered value with current Node's Value

    
    If || Value < Current-Node's Value || -> Enter the element to the left

    Else || Value > Current-Node's Value || -> Enter the element to the right
    
    
    */

    if (val < temp->data)
    {
      if (temp->left == NULL)
      {
        // If the Pointer is Empty or there is no other element present, Insert the element

        temp->left = nd;
      }
      else
      {
        // Else Go down the tree

        createNode(temp->left, val);
      }
    }
    else
    {

      if (temp->right == NULL)
      {
        // If the Pointer is Empty or there is no other element present, Insert the element

        temp->right = nd;
      }
      else
      {
        // Else Go down the tree

        createNode(temp->right, val);
      }
    }
    return (nd);
  }
  // Function to insert the root Element, with only the entered value. By default, First element is the root

  node *createNode(int value)
  {
    node *nde = new node;
    nde->data = value;
    nde->left = NULL;
    nde->right = NULL;
    if (root == NULL)
    {
      root = nde;
      root->left = NULL;
      root->right = NULL;
    }
    return (root);
  }

  // Function to Delete an entered node

  node *deleteNode(node *r, int vlu)
  {
    // Locating the entered value

    if (vlu > r->data)
    {
      r = r->right;
      deleteNode(r, vlu);
    }
    else if (vlu < r->data)
    {
      r = r->left;
      deleteNode(r, vlu);
    }

    // Else presents the case that the value has been Located

    else
    {
      // Case 1: When the Node to be deleted is a leaf node

      if (r->left == NULL && r->right == NULL)
      {
        node *te = new node;
        r = Predec(r->left);
        r = te;
        std::cout << te << endl;
      }

      // Case 2: When the node to be deleted does not have a left child

      else if (r->left == NULL)
      {
        node *tmp = new node;
        tmp = r->right;
        r = tmp;
      }

      // Case 3: When the node to be deleted does not have a right child

      else if (r->right == NULL)
      {
        node *tmpr = new node;
        tmpr = r->left;
        r = tmpr;
      }

      // Case 4: When the node to be deleted has both a left and right child, or the node is the root

      else
      {

        // Call the Function Predec to Find the Predecessor of the node to be deleted

        node *tmp1 = Predec(r->left);
        r->data = tmp1->right->data;         // Set the Node's Value to the predecessor
        tmp1->right = ((tmp1->right)->left); // Delete the predecessor
      }
    }
    return (r);
  }

  // Function to find the Predecessor of a given Node

  node *Predec(node *b)
  {
    if (b == NULL)
    {
      // If the node is a leaf node, it's predecessor is Null

      return (NULL);
    }
    while (((b->right)->right) != NULL)
    {
      // Reach the Parent of the Node, which is the rightmost of the node to be deleted
      b = b->right;
    }
    // Return the parent of the Predecessor
    return (b);
  }

  // Displaying the nodes of the binary search tree using an Inorder Traversal

  void disp(node *leaf)
  {

    if (leaf == NULL)
    {
      return;
    }
    else
    {

      disp(leaf->left); // Visit the Left Child First

      std::cout << leaf->data << '\t'; // Visit the Node
      std::cout << "| ";
      disp(leaf->right); // Then Visit the Right Child
    }
  }
};

int main()
{
  // Creating an object of the Class Tree
  tree tt;
  // Creating the pointer to the root
  node *rooter = new node;
  // Creating the Root

  rooter = tt.createNode(100);

  // Creating the all other Nodes
  tt.createNode(rooter, 50);
  tt.createNode(rooter, 200);
  tt.createNode(rooter, 150);
  tt.createNode(rooter, 300);
  tt.createNode(rooter, 25);
  tt.createNode(rooter, 75);
  tt.createNode(rooter, 12);
  tt.createNode(rooter, 37);
  tt.createNode(rooter, 125);
  tt.createNode(rooter, 175);
  tt.createNode(rooter, 250);
  tt.createNode(rooter, 320);
  tt.createNode(rooter, 67);
  tt.createNode(rooter, 87);
  tt.createNode(rooter, 94);
  tt.createNode(rooter, 89);
  tt.createNode(rooter, 92);
  tt.createNode(rooter, 88);
  std::cout << endl;
  std::cout << "The Original Binary Search Tree Doing an Inorder Traversal" << endl;
  std::cout << endl;
  tt.disp(rooter);
  std::cout << endl;
  std::cout << endl;
  std::cout << "The Binary Search Tree after deleting 100 is" << endl;
  std::cout << endl;
  tt.deleteNode(rooter, 100); // Deleting the Value 100 from the Binary Tree
  tt.disp(rooter);
  std::cout << endl;
  std::cout << endl;
  std::cout << "The End" << endl;
}
