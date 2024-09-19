

bool isPalindrome(string str) //function to check palindrome
{
    ArrayQueue(); //object of myQueue class
    ArrayStack(); //object of myStack class
    int length=str.length(); //variable to store the length of string
    for(int i=0;i<length;i++)
    {
        aQueue.enqueue(str[i]); //enqueue data into queue
        aStack.push(str[i]);    //push data into stack
    }

    bool charactersAreEqual=true; //flag variable to check for palindrome
    while(!aQueue.isEmpty() && charactersAreEqual)
    {
        char queueFront=aQueue.peekFront(); //front of queue
        char stackTop=aStack.peek();        //top of queue

        if(queueFront==stackTop) //if queueFront and stackTop are equal
        {
            aQueue.dequeue();
            aStack.pop();
        }
        else //if queueFront and stackTop are not equal
        {
            charactersAreEqual=false;
        }
    }
    return charactersAreEqual; //return the flag
}

int main()
{
    cout<<"Enter the string: \n";
    string str; //string for storing the input string by user
    cin>>str; //take input the string

    if(isPalindrome(str)) //check for palindrome
        cout<<"Given string is Palindrome.";

    else //if not palindrome
        cout<<"Given String is not Palindrome.";

    return 0;
}