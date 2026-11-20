#include <iostream>
#include <string>
using namespace std;

class PriorityQueue
{
    struct Patient
    {
        string name;
        int priority;
    };

    Patient p[100];
    int count;

public:

    PriorityQueue()
    {
        count = 0;
    }

    // Insert patient
    void enqueue()
    {
        if(count == 100)
        {
            cout << "Queue is Full!\n";
            return;
        }

        cout << "Enter patient name: ";
        cin >> p[count].name;

        cout << "Enter priority (1-High, 2-Medium, 3-Low): ";
        cin >> p[count].priority;

        if(p[count].priority < 1 || p[count].priority > 3)
        {
            cout << "Invalid priority!\n";
            return;
        }

        count++;

        cout << "Patient added successfully!\n";
    }

    // Delete highest priority patient
    void dequeue()
    {
        if(count == 0)
        {
            cout << "Queue is Empty!\n";
            return;
        }

        int pos = 0;

        for(int i = 1; i < count; i++)
        {
            if(p[i].priority < p[pos].priority)
                pos = i;
        }

        cout << "Treating patient: " << p[pos].name << endl;

        for(int i = pos; i < count - 1; i++)
        {
            p[i] = p[i + 1];
        }

        count--;
    }

    // Display patients
    void display()
    {
        if(count == 0)
        {
            cout << "No patients in queue!\n";
            return;
        }

        cout << "\n--- Patient Queue ---\n";

        for(int i = 0; i < count; i++)
        {
            cout << "Name: " << p[i].name
                 << " | Priority: " << p[i].priority << endl;
        }
    }

    // View highest priority patient
    void peek()
    {
        if(count == 0)
        {
            cout << "Queue is Empty!\n";
            return;
        }

        int pos = 0;

        for(int i = 1; i < count; i++)
        {
            if(p[i].priority < p[pos].priority)
                pos = i;
        }

        cout << "Next patient: " << p[pos].name << endl;
        cout << "Priority: " << p[pos].priority << endl;
    }
};

int main()
{
    PriorityQueue q;
    int choice;

    do
    {
        cout << "\n===== Hospital Appointment System =====";
        cout << "\n1. Add Patient";
        cout << "\n2. Treat Patient";
        cout << "\n3. Display Patients";
        cout << "\n4. Next Patient";
        cout << "\n5. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                q.enqueue();
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 4:
                q.peek();
                break;

            case 5:
                cout << "Thank you!";
                break;

            default:
                cout << "Invalid choice!";
        }

    } while(choice != 5);

    return 0;
}
