#include <iostream>
#include <string>
using namespace std;

class Customer 
{
public:
    int ID;
    string Name;
    int TicketCount;
    Customer* next;

    Customer(int id, string name, int tickets)
    {
        ID = id;
        Name = name;
        TicketCount = tickets;
        next = nullptr;
    }
};

class PriorityTicketQueue 
{
private:
    Customer* front;
    int size;

public:
    PriorityTicketQueue()
    {
        front = nullptr;
        size = 0;
    }

    void enqueue(int id, string name, int tickets)
    {
        Customer* newCustomer = new Customer(id, name, tickets);
        
        if (front == nullptr || tickets > front->TicketCount)
        {
            newCustomer->next = front;
            front = newCustomer;
        }
        else
        {
            Customer* current = front;
            while (current->next != nullptr && 
                   current->next->TicketCount >= tickets)
            {
                current = current->next;
            }
            newCustomer->next = current->next;
            current->next = newCustomer;
        }
        size++;
        cout << "Customer " << name << " added to priority queue" << endl;
    }

    void dequeue()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Customer* temp = front;
        cout << "Issuing " << temp->TicketCount << " tickets to " << temp->Name << endl;
        
        front = front->next;
        delete temp;
        size--;
    }

    void display()
    {
        if (front == nullptr)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Current Priority Queue Status:" << endl;
        Customer* temp = front;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->ID 
                 << ", Name: " << temp->Name 
                 << ", Tickets: " << temp->TicketCount << endl;
            temp = temp->next;
        }
        cout << "Total customers in queue: " << size << endl;
    }
};


int main()
{
    PriorityTicketQueue movieQueue;

    movieQueue.enqueue(1, "Shammas", 2);
    movieQueue.enqueue(2, "Omer", 3);    
    movieQueue.enqueue(3, "Abbasi", 1);  
    
    cout << endl;
    movieQueue.display();
    
    cout << endl;
    movieQueue.dequeue();  
    
    cout << endl;
    movieQueue.display();
    
    cout << endl;
    movieQueue.enqueue(4, "Ahmed", 4);   
    
    cout << endl;
    movieQueue.display();

    return 0;
}