
/*********************************************************************
 * CaesarEncode implements the Caesar cipher encoding scheme.        *
 *                                                                   * 
 * Receive: ch, a character.                                         *
 *          key, the amount by which to rotate ch.                   *
 * Return:  The character that is key positions after ch,            *
 *          with "wrap-around" to the beginning of the sequence.     *
 *********************************************************************/
#include <cstdlib>     // exit()
#include <cctype>      // isupper(), islower()
#include <iostream>
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


