//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include "BinaryNodeTree.h"  // ADT binary tree operations
#include <iostream>
#include <string>

using namespace std;

void display(string& anItem)
{
   cout << "Displaying item - " << anItem << endl;
}  // end display

void check(bool success)
{
   if (success)
      cout << "Done." << endl;
   else
      cout << " Entry not in tree." << endl;
}  // end check

int main()
{
   BinaryTreeInterface<string>* tree1 = new BinaryNodeTree<string>();   
   tree1->add("10");
   tree1->add("20");
   tree1->add("30");
   tree1->add("40");

   BinaryTreeInterface<string>* tree2 = new BinaryNodeTree<string>();   
   tree2->add("10");
   tree2->add("20");
   tree2->add("30");
   tree2->add("40");

   cout << "Tree 1 Preorder:\n";
   tree1->preorderTraverse(display);

   cout << "Tree 2 Preorder:\n";
   tree2->preorderTraverse(display);

   cout << "Tree 1 Inorder:\n";
   tree1->inorderTraverse(display);

   cout << "Tree 2 Inorder:\n";
   tree2->inorderTraverse(display);
   
   return 0;
}  // end main

/* NEW SAMPLE OUTPUT:

Tree 1 Preorder:
Displaying item - 10
Displaying item - 40
Displaying item - 20
Displaying item - 30
Tree 2 Preorder:
Displaying item - 10
Displaying item - 20
Displaying item - 30
Displaying item - 40
Tree 1 Inorder:
Displaying item - 40
Displaying item - 10
Displaying item - 20
Displaying item - 30
Tree 2 Inorder:
Displaying item - 30
Displaying item - 20
Displaying item - 40
Displaying item - 10

*/

