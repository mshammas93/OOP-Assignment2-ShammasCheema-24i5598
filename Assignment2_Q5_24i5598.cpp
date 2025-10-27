#include <iostream>
using namespace std;

class Node 
{
public:
    char data;
    Node* next;
    Node(char c) 
    { 
        data = c; 
        next = nullptr; 
    }
};

// Linked List based Stack
class NodeStack 
{
private:
    Node* top;

public:
    NodeStack() 
    { 
        top = nullptr; 
    }
    
    void push(char c) 
    {
        Node* node = new Node(c);
        node->next = top;
        top = node;
    }

    char pop() 
    {
        if (top == nullptr) 
            return '\0';
        char c = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return c;
    }
};

// Array based Stack
class ArrayStack 
{
private:
    char* arr;
    int size;
    int top;

public:
    ArrayStack() 
    { 
        size = 10;
        arr = new char[size];
        top = -1;
    }

    void push(char c) 
    {
        if (top == size - 1) 
        {
            char* temp = new char[size * 2];
            for (int i = 0; i < size; i++) 
                temp[i] = arr[i];
            delete[] arr;
            arr = temp;
            size *= 2;
        }
        arr[++top] = c;
    }

    char pop() 
    {
        if (top < 0) 
            return '\0';
        return arr[top--];
    }
};

// Q1a using bith tyes of stcaks
void ChangeLocationArray(char* Array, int b1, int b2) 
{
    ArrayStack stack;
    for (int i = b1 - 1; i < b2; i++) 
        stack.push(Array[i]);
    for (int i = b1 - 1; i < b2; i++) 
        Array[i] = stack.pop();
}

void ChangeLocationList(char* Array, int b1, int b2) 
{
    NodeStack stack;
    for (int i = b1 - 1; i < b2; i++) 
        stack.push(Array[i]);
    for (int i = b1 - 1; i < b2; i++) 
        Array[i] = stack.pop();
}

// Q1b using both types of tacks
void PrintPatternArray(int n) 
{
    ArrayStack stack;
    for (int i = n; i > 0; i--) 
    {
        int rem = i;
        while (rem > 0) 
        {
            if (rem >= 2) 
            { 
                stack.push('2'); 
                rem -= 2; 
            }
            else 
            { 
                stack.push('1'); 
                rem--; 
            }
        }
        
        char c;
        while ((c = stack.pop()) != '\0') 
            cout << c << " ";
        cout << endl;
    }
}

void PrintPatternList(int n) 
{
    NodeStack stack;
    for (int i = n; i > 0; i--) 
    {
        int rem = i;
        while (rem > 0) 
        {
            if (rem >= 2) 
            { 
                stack.push('2'); 
                rem -= 2; 
            }
            else 
            { 
                stack.push('1'); 
                rem--; 
            }
        }
        
        char c;
        while ((c = stack.pop()) != '\0') 
            cout << c << " ";
        cout << endl;
    }
}

int main() 
{
    // part a test 
    char arr1[] = "COMPUTER";
    char arr2[] = "COMPUTER";
    
    cout << "Original: " << arr1 << endl;
    
    cout << "Array-based implementation:" << endl;
    ChangeLocationArray(arr1, 3, 7);
    cout << "Changed: " << arr1 << endl;
    
    cout << "List-based implementation:" << endl;
    ChangeLocationList(arr2, 3, 7);
    cout << "Changed: " << arr2 << endl;
    
    // part b test 
    cout << "Pattern for n=4 (Array-based):" << endl;
    PrintPatternArray(4);
    
    cout << "Pattern for n=4 (List-based):" << endl;
    PrintPatternList(4);
    
    return 0;
}