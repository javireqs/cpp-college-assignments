
/********************************************************************
 * CaesarDecode implements the Caesar cipher encoding scheme.       *
 *                                                                  * 
 * Receive: ch, a character,                                        *
 *          key, an integer.                                        *
 * Return:  The character that is key positions before ch,          *
 *          with "wrap-around" to the end of the sequence.          *
 ********************************************************************/
#include <cstdlib>     // exit()
#include <cctype>      // isupper(), islower()
#include <iostream>
using namespace std;
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


