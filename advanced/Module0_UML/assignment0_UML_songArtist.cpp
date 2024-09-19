// Javier Hernandez Requena
// CS 110c - C++ Data Structures & Algorithms
// Max Lutrell
// August 18, 2022
// Program: UML_songArtist
// Desc: Implements a complete C++ program which declares UML "Song" class & implements its member functions
//       then creates runs a simple main program that creates an object of the class, asks user for name and
//       artist, then calls set & get functions to display the song name & song artist back to user.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Song
{
    private:
        // Member Variables
        string name;
        string artist;

    public:
        // Accessor Functions
        string getName() const;
        string getArtist() const;

        // Mutator Functions
        void setName(string);
        void setArtist(string);
};

// Accessor Functions (get methods)
string Song::getName() const
{
    return name;
}

string Song::getArtist() const
{
    return artist;
}

// Mutator Functions (set methods)
void Song::setName(string newName)
{
    name = newName;
}

void Song::setArtist(string newArtist)
{
    artist = newArtist;
}

int main()
{
    string name;
    string artist;

    cout << "Enter a song name: ";
    getline(cin, name);

    cout << "Enter an artist name: ";
    getline(cin, artist);

    Song Song1;

    Song1.setName(name);
    Song1.setArtist(artist);

    cout << endl << "The name of the song is: " << Song1.getName() << endl
        << "The name of the artist is: " << Song1.getArtist() << endl;

    return 0;
}

/*

SAMPLE OUTPUT:

[jhern441@hills 0]$ ./a.out
Enter a song name: Arise
Enter an artist name: Sol Rising

The name of the song is: Arise
The name of the artist is: Sol Rising
[jhern441@hills 0]$ 

*/