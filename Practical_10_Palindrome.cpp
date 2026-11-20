#include <iostream>
#include <string>
using namespace std;

class Deque
{
    char arr[100];
    int front, rear;

public:

    Deque()
    {
        front = -1;
        rear = -1;
    }

    // Insert character at rear
    void insertRear(char ch)
    {
        if(rear == 99)
        {
            cout << "Deque is full";
            return;
        }

        if(front == -1)
            front = 0;

        rear++;
        arr[rear] = ch;
    }

    // Delete character from front
    char deleteFront()
    {
        char ch = arr[front];

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }

        return ch;
    }

    // Delete character from rear
    char deleteRear()
    {
        char ch = arr[rear];

        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear--;
        }

        return ch;
    }

    // Check palindrome
    bool isPalindrome()
    {
        while(front < rear)
        {
            char first = deleteFront();
            char last = deleteRear();

            if(first != last)
                return false;
        }

        return true;
    }
};

int main()
{
    Deque d;
    string str;

    cout << "Enter a string: ";
    cin >> str;

    for(int i = 0; i < str.length(); i++)
    {
        d.insertRear(str[i]);
    }

    if(d.isPalindrome())
        cout << "String is Palindrome";
    else
        cout << "String is Not Palindrome";

    return 0;
}
