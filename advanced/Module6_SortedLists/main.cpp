//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

#include <iostream>
#include <string>
#include "SortedListHasA.h" // ADT sorted list operations

using namespace std;

void displayList(SortedListInterface<int>* listPtr)
{
	cout << "\nHigh Scores Hall of Fame: " << endl;
   for (int pos = listPtr->getLength(); pos > 0; pos--)
   {
      if (listPtr->getEntry(pos) >= 0)
         cout << listPtr->getEntry(pos) << " ";
      else
         break;
   } // end for
	cout << endl << endl;
}  // end displayList

/*
void copyConstructorTester()
{
	SortedListHasA<string> list;
   string items[] = {"zero", "one", "two", "three", "four", "five"};
	for (int i = 0; i < 6; i++)
   {
		cout << "Adding " << items[i] << endl;
      list.insertSorted(items[i]);
	}
   displayList(&list);
   
   SortedListHasA<string> copyOfList(list);
   cout << "Copy of list: ";
   displayList(&copyOfList);
   
   cout << "The copied list: ";
   displayList(&list);
}  // end copyConstructorTester

void sortedListTester(SortedListInterface<string>* listPtr)
{
   string luke = "Luke";
   string brent = "Brent";
   string donna = "Donna";
   string tom = "Tom";
   string sue = "Sue";
   string jerry = "Jerry";
   
   cout << "\nTest isEmpty with an empty list:" << endl;
   if (listPtr->isEmpty())
      cout << "OK" << endl;
   else
      cout << "isEmpty() error" << endl;
	
   listPtr->insertSorted(luke);
   listPtr->insertSorted(brent);
   listPtr->insertSorted(donna);
   listPtr->insertSorted(tom);
   listPtr->insertSorted(sue);
   listPtr->insertSorted(jerry);
   
   // display the list
   cout << "List should contain\nBrent, Donna, " <<
   "Jerry, Luke, Sue, Tom" << endl;
   cout << "\nList actually contains:" << endl;
   displayList(listPtr);
   cout << endl;
   
   // test getPosition
   cout << "\nTest getPosition:\n" << endl;
   
   // These names are in the list
   cout << "Brent is at position " << listPtr->getPosition(brent) << endl;
   cout << "Donna is at position " << listPtr->getPosition(donna) << endl;
   cout << "Jerry is at position " << listPtr->getPosition(jerry) << endl;
   cout << "Luke is at position "  << listPtr->getPosition(luke) << endl;
   cout << "Sue is at position "   << listPtr->getPosition(sue) << endl;
   cout << "Tom is at position "   << listPtr->getPosition(tom) << endl;
   
   // These names are not in the list
   string missy = "Missy";
   cout << "Missy belongs at position " << listPtr->getPosition(missy) << endl;
   string zeke = "Zeke";
   cout << "Zeke belongs at position " << listPtr->getPosition(zeke) << endl;
   string aaron = "Aaron";
   cout << "Aaron belongs at position " << listPtr->getPosition(aaron) << endl;
   
   // test getLength and getEntry
   cout << "\nTest getLength and getEntry:\n" << endl;
   
   cout << "\nList has " << listPtr->getLength() << " entries, as follows:\n" << endl;
   for (int i = 1; i <= listPtr->getLength(); i++)
      cout << i << ": " << listPtr->getEntry(i) << endl;
   
   
   // test remove
   cout << "\nTest remove:\n" << endl;
   
   // remove first entry
   cout << "\nRemoving first item (Brent): " << listPtr->removeSorted(brent) << "; should be 1 (true)" << endl;
   cout << "\nAfter removing Brent, list contains " << listPtr->getLength()
   << " items, as follows:" << endl;
   displayList(listPtr);
   
   // remove interior
   cout << "\nRemoving interior item (Luke): " << listPtr->removeSorted(luke) << "; should be 1 (true)" << endl;
   cout << "\nAfter removing Luke, list contains " << listPtr->getLength()
   << " items, as follows:" << endl;
   displayList(listPtr);
   
   // remove last
   cout << "\nRemoving last item (Tom): " << listPtr->removeSorted(tom) << "; should be 1 (true)" << endl;
   cout << "\nAfter removing last item, list contains " << listPtr->getLength()
   << " items, as follows:" << endl;
   displayList(listPtr);
   
   cout << "\nRemoving a missing item (Brent): " << listPtr->removeSorted(brent) << "; should be 0 (false)" << endl;
   cout << "\nRemoving a missing item (Luke): " << listPtr->removeSorted(luke) << "; should be 0 (false)" << endl;
   cout << "\nRemoving a missing item (Tom): " << listPtr->removeSorted(tom) << "; should be 0 (false)" << endl;
   
   cout << "\nThe list contains " << listPtr->getLength()
   << " items, as follows:" << endl;
   displayList(listPtr);
   
   // test clear()
   cout << "\nTest clear():\n" << endl;
   listPtr->clear();
   
   if (listPtr->isEmpty())
      cout << "\nThe list is empty after invoking clear()." << endl;
   else
      cout << "\nclear() error" << endl;
} // end sortedListTester

void listOpsTester(SortedListInterface<string>* listPtr)
{
   string luke = "Luke";
   string brent = "Brent";
   string donna = "Donna";
   string tom = "Tom";
   string sue = "Sue";
   string jerry = "Jerry";
   
   listPtr->insertSorted(luke);
   listPtr->insertSorted(brent);
   listPtr->insertSorted(donna);
   listPtr->insertSorted(tom);
   listPtr->insertSorted(sue);
   listPtr->insertSorted(jerry);
   
   displayList(listPtr);
   
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 0 (false)" << endl;
   cout << "getLength returns : " << listPtr->getLength() << "; should be 6" << endl;
   
   cout << "remove(2): returns " << listPtr->remove(2) << "; should be 1 (true)" << endl;
   cout << "remove(1): returns " << listPtr->remove(1) << "; should be 1 (true)" << endl;
   cout << "remove(6): returns " << listPtr->remove(6) << "; should be 0 (false)" << endl;
   displayList(listPtr);
   cout << "getLength returns : " << listPtr->getLength() << "; should be 4" << endl;
   cout << "clear: " << endl;
   listPtr->clear();
   cout << "isEmpty: returns " << listPtr->isEmpty() << "; should be 1 (true)" << endl;
   
   try
   {
      cout << "Attempt an illegal retrieval from position 6: " << endl;
      listPtr->getEntry(6);
   }
   catch(PrecondViolatedExcep e)
   {
      cout << e.what() << endl;
   }  // end try/catch
} // end listOpsTester
*/


int main()
{
   /*
   copyConstructorTester();

   SortedListInterface<int>* intList = new SortedListHasA<int>();

	SortedListInterface<string>* listPtr = new SortedListHasA<string>();
	cout << "Testing the Link-Based Sorted List:" << endl;
	sortedListTester(listPtr);
   cout << "======================================" << endl;
   
	cout << "\nTesting the List Operations:" << endl;
	listOpsTester(listPtr);
   */  

   int score = 1;
   const int MAX = 1000;
   
   
   SortedListHasA<int> highScores;
   SortedListInterface<int>* scorePtr = new SortedListHasA<int>();
   int scores[MAX] = {100, 56, 57, 94, 23};
   for (int i = 0; i < 6; i++)
   {
      highScores.insertSorted(scores[i]);
   }

   cout << "Hello, welcome to our Hall of Fame!" << endl << endl;
   
   while (score >= 0)
   {
      cout << "Enter high score (negative number to quit): " << endl;
      cin >> score;
      highScores.insertSorted(score);
      displayList(&highScores);
   }
   

   return 0;
}  // end main

