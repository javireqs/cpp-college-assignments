// Array-based List Class for Playlists
// Max Luttrell CS 110C
//
// Javier Hernandez Requena
// Sept. 6, 2022
// Playlist Template Functions
//


#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;


template<class ItemType>
class List
{
private:
    static const int CHUNK_SIZE=2;
    ItemType *list;
    int numItems;
    int maxItems;
public:
    // default constructor and destructor
    List() { numItems = 0; maxItems = CHUNK_SIZE;
        list = new ItemType[CHUNK_SIZE]; }
    virtual ~List() { delete [] list; }
    
    // list member functions
    bool isEmpty()  const { return numItems==0; }
    int getLength() const { return numItems; }
    bool insert(int pos, const ItemType& item);
    bool remove(int pos);
    
    // clear the list
    // clear can simply set numItems to zero.  The array list may still contain
    // items already inserted into the list, but since numItems is zero, there
    // isn't any way to get at them using getEntry() or setEntry()
    void clear() { numItems = 0; }
    
    // return entry at postion pos
    // throw invalid_argument if pos<1 or pos>getLength()
    ItemType getEntry(int pos) const;
    
    // set entry at postion pos to item
    // throw invalid_argument if pos<1 or pos>getLength()
    void setEntry(int pos, const ItemType& item);
};

template<class ItemType>
bool List<ItemType>::insert(int pos, const ItemType& item)
{
    bool canAdd = (numItems < maxItems);
    if (!canAdd)  
    {
        ItemType* oldArray = list;
        list = new ItemType[2 * maxItems];
        for(int i=0; i<maxItems; i++)
            list[i] = oldArray[i];
        delete [] oldArray;
        maxItems = 2 * maxItems;
    }
    
    list[numItems] = item;
    numItems++;
    return true;
}

template<class ItemType>
ItemType List<ItemType>::getEntry(int pos) const
{
    if(pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: getEntry() using invalid position");
    }
    return list[pos-1];
}

// implementations for setEntry() and remove() functions
template<class ItemType>
void List<ItemType>::setEntry(int pos, const ItemType& item)
{
    if(pos<1 || pos>getLength()) {
        throw invalid_argument("ERROR: setEntry() using invalid position");
    }
    ItemType oldItem = list[pos];
    list[pos-1] = item;
}

template<class ItemType>
bool List<ItemType>::remove(int pos)
{
    bool canSub;

    canSub = ((pos > 0) && (pos <= numItems + 1));
    if (canSub)
    {
        // remove entry by shifting all entries after the one
        // at position toward the beginning of the array
        // (no shift if position == numItems)
        for(int i = pos; i < numItems; i++)
            list[i] = list[i+1];

        // now decrease number of items
        numItems--;
    }
    // return boolean
    return canSub;
}


// Utility functions to input a track number with some input checking
// to make sure it's a number
int getTrack()
{
    bool inputCheck;
    int trackNumber;
    
    do
    {
        inputCheck = true;
        cout << "Please enter the track number you'd like to view: ";
        if (!(cin >> trackNumber))
        {
            cout << "Please enter numbers only.\n";
            cin.clear();
            cin.ignore(10000,'\n');
            inputCheck = false;
        }
    } while (!inputCheck);
    return trackNumber;
}


int main()
{
    List<string> songs;
    char goAgain = 'y';
    int trackNumber, pos;
    string trackName, newSong;
    char exit = 'n';
    char choice;
    
    // Insert some songs into our list
    songs.insert(1, "One More Saturday Night");
    songs.insert(1, "Friday I'm in Love");
    songs.insert(3, "Sunday Morning Coming Down");
    songs.insert(1, "California Love");
    
    do
    {
        cout << "Welcome! There are " << songs.getLength() << " tracks.\n";
        
        cout << "Would you like to see the tracks? (y/n) ";
        cin >> choice;
        while (choice!='n')
        {
            trackNumber = getTrack();
            try
            {
                trackName = songs.getEntry(trackNumber);
            }
            catch (invalid_argument arg)
            {
                cout << arg.what() << endl;
                trackName = "No Track";
            }
            cout << "Your track name is: " << trackName << endl;

            cout << "Go again? (y/n) ";
            cin >> choice;
        }
        choice = 'y';

        cout << "Would you like to replace the tracks? (y/n) ";
        cin >> choice;
        while (choice!='n')
        {
            cout << "Let's replace a song with one of your own."
                << endl << "Enter your song's name (Type '*' and hit Enter to end song name): ";
            getline(cin, newSong, '*');
            cout << "Enter the position to replace: ";
            cin >> pos;
            try
            {
                songs.setEntry(pos, newSong);
                cout << "The song in position " << pos << " has been replaced by: " << songs.getEntry(pos);
            }
            catch(invalid_argument e)
            {
                cerr << e.what() << '\n';
            }

            cout << "Go again? (y/n) ";
            cin >> choice;
        }
        choice = 'y';
        
        cout << "Would you like to insert tracks? (y/n) ";
        cin >> choice;
        while (choice!='n')
        {
            cout << "Let's insert a song into our playlist!\n";
            cout << "Enter a song name to insert into the playlist (Type '*' and hit Enter to end song name): ";
            getline(cin, newSong, '*');
            pos = songs.getLength()-1;
            bool inserted = songs.insert(pos, newSong);
            if (inserted)
            {
                cout << "Song was successfully inserted!" << endl;
            }

            cout << "Go again? (y/n) ";
            cin >> choice;
        }
        choice = 'y';

        cout << "Would you like to exit playlist? (y/n) ";
        cin >> exit;
    } while (exit!='y');
    
    
    cout << "Rock on!\n";
    return 0;
}


/*

SAMPLE OUTPUT:

Welcome! There are 4 tracks.
Would you like to see the tracks? (y/n) y
Please enter the track number you'd like to view: 1
Your track name is: One More Saturday Night
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is: Friday I'm in Love
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is: Sunday Morning Coming Down
Go again? (y/n) y
Please enter the track number you'd like to view: 4
Your track name is: California Love
Go again? (y/n) y
Please enter the track number you'd like to view: 5
ERROR: getEntry() using invalid position
Your track name is: No Track
Go again? (y/n) n
Would you like to replace the tracks? (y/n) y
Let's replace a song with one of your own.
Enter your song's name (Type '*' and hit Enter to end song name): Check Yo Self *
Enter the position to replace: 1
The song in position 1 has been replaced by: 
Check Yo Self 
Go again? (y/n) y
Let's replace a song with one of your own.
Enter your song's name (Type '*' and hit Enter to end song name): Smoke & Mirrors *
Enter the position to replace: 2
The song in position 2 has been replaced by: 
Smoke & Mirrors 
Go again? (y/n) y
Let's replace a song with one of your own.
Enter your song's name (Type '*' and hit Enter to end song name): Stanley *
Enter the position to replace: 3
The song in position 3 has been replaced by: 
Stanley 
Go again? (y/n) y
Let's replace a song with one of your own.
Enter your song's name (Type '*' and hit Enter to end song name): Notorious
*
Enter the position to replace: 5
ERROR: setEntry() using invalid position
Go again? (y/n) n
Would you like to insert tracks? (y/n) y
Let's insert a song into our playlist!
Enter a song name to insert into the playlist (Type '*' and hit Enter to end song name): Picture Me Rollin' *
Song was successfully inserted!
Go again? (y/n) y
Let's insert a song into our playlist!
Enter a song name to insert into the playlist (Type '*' and hit Enter to end song name): Str8 Ballin' *
Song was successfully inserted!
Go again? (y/n) n
Would you like to exit playlist? (y/n) n
Welcome! There are 6 tracks.
Would you like to see the tracks? (y/n) y
Please enter the track number you'd like to view: 1
Your track name is: 
Check Yo Self 
Go again? (y/n) y
Please enter the track number you'd like to view: 2
Your track name is: 
Smoke & Mirrors 
Go again? (y/n) y
Please enter the track number you'd like to view: 3
Your track name is: 
Stanley 
Go again? (y/n) y
Please enter the track number you'd like to view: 4
Your track name is: California Love
Go again? (y/n) y
Please enter the track number you'd like to view: 5
Your track name is: 
Picture Me Rollin' 
Go again? (y/n) y
Please enter the track number you'd like to view: 6
Your track name is: 
Str8 Ballin' 
Go again? (y/n) y
Please enter the track number you'd like to view: 7
ERROR: getEntry() using invalid position
Your track name is: No Track
Go again? (y/n) n
Would you like to replace the tracks? (y/n) y
Let's replace a song with one of your own.
Enter your song's name (Type '*' and hit Enter to end song name): Old School *
Enter the position to replace: 465
ERROR: setEntry() using invalid position
Go again? (y/n) n
Would you like to insert tracks? (y/n) n
Would you like to exit playlist? (y/n) y
Rock on!

*/
