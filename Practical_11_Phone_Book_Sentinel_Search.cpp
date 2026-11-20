#include <iostream>
#include <cstring>
using namespace std;

class PhoneBook
{
    struct Friend
    {
        char name[30];
        char mobile[15];
    };

    Friend f[101];
    int n;

public:

    PhoneBook()
    {
        n = 0;
    }

    // Insert friend in sorted order
    void insert(char name[], char mobile[])
    {
        int i = n - 1;

        while(i >= 0 && strcmp(f[i].name, name) > 0)
        {
            f[i + 1] = f[i];
            i--;
        }

        strcpy(f[i + 1].name, name);
        strcpy(f[i + 1].mobile, mobile);

        n++;

        cout << "Friend inserted successfully!\n";
    }

    // Sentinel Search
    int search(char key[])
    {
        strcpy(f[n].name, key);

        int i = 0;

        while(strcmp(f[i].name, key) != 0)
        {
            i++;
        }

        if(i == n)
            return -1;

        return i;
    }

    // Search and insert if not present
    void searchFriend()
    {
        char name[30], mobile[15];

        cout << "Enter name to search: ";
        cin >> name;

        int pos = search(name);

        if(pos != -1)
        {
            cout << "Friend Found!\n";
            cout << "Name: " << f[pos].name << endl;
            cout << "Mobile: " << f[pos].mobile << endl;
        }
        else
        {
            cout << "Friend not found!\n";

            cout << "Enter mobile number: ";
            cin >> mobile;

            insert(name, mobile);
        }
    }

    // Display phone book
    void display()
    {
        cout << "\n--- Phone Book ---\n";

        if(n == 0)
        {
            cout << "Phone Book is Empty\n";
            return;
        }

        for(int i = 0; i < n; i++)
        {
            cout << f[i].name << " : "
                 << f[i].mobile << endl;
        }
    }
};

int main()
{
    PhoneBook p;
    int choice;
    char name[30], mobile[15];

    do
    {
        cout << "\n1. Add Friend";
        cout << "\n2. Search Friend";
        cout << "\n3. Display Phone Book";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter name: ";
                cin >> name;

                cout << "Enter mobile number: ";
                cin >> mobile;

                p.insert(name, mobile);
                break;

            case 2:
                p.searchFriend();
                break;

            case 3:
                p.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid Choice!";
        }

    } while(choice != 4);

    return 0;
}
