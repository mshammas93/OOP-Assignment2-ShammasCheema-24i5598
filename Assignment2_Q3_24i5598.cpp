#include <iostream>
#include <string>
using namespace std;

class Node 
{
public:
    int BookID;
    string Title;
    string Author;
    Node* prev;
    Node* next;

    Node(int id, string title, string author)
    {
        BookID = id;
        Title = title;
        Author = author;
        prev = nullptr;
        next = nullptr;
    }
};

class Library 
{
private:
    Node* head;
    Node* tail;

public:
    Library()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addToBeginning(int id, string title, string author)
    {
        Node* newNode = new Node(id, title, author);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void addToEnd(int id, string title, string author)
    {
        Node* newNode = new Node(id, title, author);
        if (tail == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void addAtPosition(int id, string title, string author, int position)
    {
        if (position <= 1)
        {
            addToBeginning(id, title, author);
            return;
        }

        Node* current = head;
        int currentPos = 1;

        while (current != nullptr && currentPos < position - 1)
        {
            current = current->next;
            currentPos++;
        }

        if (current == nullptr)
        {
            addToEnd(id, title, author);
            return;
        }

        Node* newNode = new Node(id, title, author);
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    bool deleteBook(int id)
    {
        Node* current = head;
        while (current != nullptr)
        {
            if (current->BookID == id)
            {
                if (current->prev != nullptr)
                {
                    current->prev->next = current->next;
                }
                else
                {
                    head = current->next;
                }
                if (current->next != nullptr)
                {
                    current->next->prev = current->prev;
                }
                else
                {
                    tail = current->prev;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void displayForward()
    {
        Node* current = head;
        cout << "Books (Forward):" << endl;
        while (current != nullptr)
        {
            cout << "ID: " << current->BookID 
                 << ", Title: " << current->Title 
                 << ", Author: " << current->Author << endl;
            current = current->next;
        }
    }

    void displayBackward()
    {
        Node* current = tail;
        cout << "Books (Backward):" << endl;
        while (current != nullptr)
        {
            cout << "ID: " << current->BookID 
                 << ", Title: " << current->Title 
                 << ", Author: " << current->Author << endl;
            current = current->prev;
        }
    }
};

int main()
{
    Library library;

    library.addToBeginning(1, "The Hobbit", "Tolkien");
    library.addToEnd(2, "1984", "Orwell");
    library.addAtPosition(3, "Pride and Prejudice", "Austen", 2);

    cout << "Initial Library State:" << endl;
    library.displayForward();
    cout << endl;
    library.displayBackward();

    cout << endl;
    cout << "Deleting book with ID 2..." << endl;
    if (library.deleteBook(2))
    {
        cout << "Book deleted successfully!" << endl;
    }
    else
    {
        cout << "Book not found!" << endl;
    }

    cout << endl;
    cout << "Updated Library State:" << endl;
    library.displayForward();

    return 0;
}