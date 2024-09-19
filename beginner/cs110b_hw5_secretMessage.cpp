/* 
Javier Hernandez Requena
July 27, 2022
CS 110 B - C++ Programming Fundamentals
Assignement 5 - Secret Message
This program takes an input file, encodes it using the caesar cipher, then sends it into an output file. It also allows
a user to decode an input file into an output file.
*/


#include <iostream>
#include <string>
#include <array>
#include <string>
#include <fstream>
#include <cstdlib>     // exit()
#include <cctype>      // isupper(), islower()
using namespace std;


char CaesarEncode(char ch, int key)
{
  const int FIRST_UPPER = 65,
            FIRST_LOWER = 97,
            NUM_CHARS = 26;

  if (key <= 0 || key >= NUM_CHARS)
    {
      cout << "\n*** CaesarEncode: key must be between 1 and 25\n" << endl;
      exit(1);
    }
  
  if (isupper(ch))
    return (ch - FIRST_UPPER + key) % NUM_CHARS + FIRST_UPPER;
  else if (islower(ch))
    return (ch - FIRST_LOWER + key) % NUM_CHARS + FIRST_LOWER;
  else
    return ch;
}


char CaesarDecode(char ch, int key)
{
  const int FIRST_UPPER = 65,
            FIRST_LOWER = 97,
            NUM_CHARS = 26;
  
  if (key <= 0 || key >= 26)
  {
     cout << "\n*** CaesarDecode: key must be between 1 and 25!\n" << endl;
     exit(1);
  }

  if (isupper(ch))
    return (ch - FIRST_UPPER + NUM_CHARS - key) % NUM_CHARS + FIRST_UPPER;
  else if (islower(ch))
    return (ch - FIRST_LOWER + NUM_CHARS - key) % NUM_CHARS + FIRST_LOWER;
  else
    return ch;
}


bool processFile(string inputFileName, string outputFileName, string encodeDecode)
{
  ifstream inFile;
  ofstream outFile;
  char next_char;
  int key = 7;
  
  inFile.open(inputFileName.c_str());
  if (!inFile.is_open())
  {
    return false;
  }
  
  outFile.open(outputFileName.c_str());
  if (!inFile.is_open())
  {
    return false;
  }

  while (inFile >> noskipws >> next_char)
  {
    if (encodeDecode == "Encode" || encodeDecode == "encode")
    {
      outFile << CaesarEncode(next_char, key);
    }
    else if (encodeDecode == "Decode" || encodeDecode == "decode")
    {
      outFile << CaesarDecode(next_char, key);
    }
  }

  inFile.close();
  outFile.close();
  return true;
}


int main()
{
  string encodeDecode;
  string inputFileName;
  string outputFileName;
  bool result;

  cout << "\n\nHello, welcome to the Caesar Cipher program:\n\n";
  cout << "Do you want to Encode or Decode?\n";
  cout << "Enter 'Encode' or 'Decode':\n\n";
  getline(cin, encodeDecode);

  cout << "\nEnter an input filename:\n\n";
  getline(cin, inputFileName);

  cout << "\nEnter an output filename:\n\n";
  getline(cin, outputFileName);

  result = processFile(inputFileName, outputFileName, encodeDecode);

  if (result == true)
  {
    cout << "\nCipher Succeeded!\n\n";
  }
  else
  {
    cout << "\nFile not found!\n\n";
  } 

}