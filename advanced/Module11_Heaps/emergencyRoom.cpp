#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    int priority;
    string name;
    Patient(int _priority, string _name)
    {
        priority = _priority;
        name = _name;
    }
};

class PatientQueue
{
    public:
        int size();
        bool isEmpty();
        void enqueue(int priority, string name);
        Patient* dequeue(); // returns pointer to patient record and removes from array
        void printList(); // print the array
        PatientQueue(); // constructor
        ~PatientQueue(); // destructor
        Patient* peekTop(); // returns patient to be served (patient with highest priority),
                            // does not remove patient
    
    private:
        void swap(int index1, int index2); // swap the contents in the array
        Patient* waitlist[100];
        int lastIndex;
};

// constructor
PatientQueue::PatientQueue()
{
    lastIndex = 0; //initiallizes lastIndex to 0;

    for (int i = 0; i < 100; i++)
    {
    waitlist[i] = NULL;
    }
}

// destructor
PatientQueue::~PatientQueue()
{
    cout << "===\nWe're CLOSING! Deleting patient queue!" << endl;
    for (int i = 1; i < lastIndex; i++)
    {
        cout << "Removing " << waitlist[i]->name << " from queue." << endl;
        waitlist[i] = NULL;
        delete waitlist[i];
    }
}

/** 
 * Function name: size
 * Purpose: Returns value of lastIndex
 * @return - int value of lastIndex
*/
int PatientQueue::size()
{
    return lastIndex;
}

/**
 * Function name: swap
 * Purpose: swap the values in the array to prioritize with smallest value
 * @return - none
*/
void PatientQueue::swap(int index1, int index2)
{
    int priority = waitlist[index1]->priority;
    string name = waitlist[index1]->name;
    Patient* tmp = new Patient(priority, name);

    for(; index1 * 2 <= lastIndex; index1 = index2)
    {
        index2 = index1 * 2;
        if (index2 != lastIndex && waitlist[index2 + 1]->priority < waitlist [index2]->priority)
        {
            index2++;
        }
        if (waitlist[index2]->priority < tmp->priority)
        {
            waitlist[index1] = waitlist[index2];
        }
        else
        {
            break;
        }

        waitlist[index2] = tmp;
    }

}

/**
* Function name: isEmpty
* Purpose: checks to see if the array has any values added to it
* @return - true if array is empty
*/
bool PatientQueue::isEmpty()
{
    if (lastIndex == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
* Function name: enqueue
* Purpose: adds new value to array and prioritizes it by priority number
* @return - none
*/
void PatientQueue::enqueue(int priority, string name)
{
    Patient* tmp = new Patient(priority, name);

    if (lastIndex == 99)
    {
        throw string("Heap Storage is full!");
    }
    else
    {
        int hole = ++lastIndex;
        for (; hole > 1 && priority < waitlist[hole/2]->priority; hole /=2)
        {
            waitlist[hole] = waitlist[hole/2];
        }

        waitlist[hole] = tmp;
        cout << "===\nAdding " << waitlist[hole]->priority <<" " << waitlist[hole]->name << endl;
        printList();
    }
}

/**
* Function name: dequeue
* Purpose: removes minimum priority value from queue
* @return - pointer to the value being removed
*/
Patient* PatientQueue:: dequeue()
{
    int priority = waitlist[1]->priority;
    string name = waitlist[1]->name;
    Patient* tmp = new Patient(priority, name);

    if (isEmpty())
    {
        throw string("Queue is empty!");
    }
    else
    {
        cout << "===\nProcessing " << waitlist[1]->priority <<" " << waitlist[1]->name << endl;
        waitlist[1] = waitlist[lastIndex--];
        swap(1, lastIndex);
    }

    return tmp;
}

/**
 * Function name: printList
 * Purpose: to print the priority list in array order
 * @return - none
*/
void PatientQueue::printList()
{
    cout << "===\nPatients Waiting" << endl;
    if (isEmpty())
    {
        cout << "No one is waiting!" <<endl;
    }
    else
    {
        for (int i = 1; i<=lastIndex; i++)
        {
            cout << "[" << waitlist[i]->priority << "] " << waitlist[i]->name << endl;
        }
    }
}

/** 
 * Function Name: peekTop()
 * Purpose: returns next patient to be served (patient with highest priority)
 * @return  patient with highest priority
*/
Patient* PatientQueue::peekTop()
{
    return waitlist[0];
}


void processNextPatient(PatientQueue* queue)
{
    if (queue==NULL)
    {
        cout << "No one waiting!" << endl;
    }
    else if (!queue->isEmpty())
    {
        Patient *next = queue->dequeue();
        cout << "===\nNEXT! - " << next->name << endl;
        delete next;
    }
}

int main()
{
    PatientQueue *queue = new PatientQueue();

    queue->enqueue(22, "Mary");
    processNextPatient(queue);
    queue->printList();

    processNextPatient(queue);

    queue->enqueue(3, "John");
    queue->enqueue(19, "Jim");
    queue->enqueue(20, "Joe");
    queue->enqueue(15, "Jack");
    queue->enqueue(7, "Jill");
    queue->enqueue(6, "Jerry");
    queue->enqueue(2, "Jessica");
    queue->enqueue(1, "Josephine");
    queue->enqueue(5, "Juan");
    queue->enqueue(4, "Hector");

    processNextPatient(queue);
    processNextPatient(queue);

    cout << queue->size() << " patient" << (queue->size()==1?"":"s") << " currently waiting." << endl;

    queue->enqueue(1, "Tim");
    queue->enqueue(8, "Fred");
    queue->dequeue();

    delete queue;

    return 0;
}