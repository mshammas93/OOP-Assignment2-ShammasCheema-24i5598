#include <iostream>
#include <string>

using namespace std;

class Feature 
{
public:
    string Name;
    Feature(const string& name)
    {
        Name = name;
    }
    virtual ~Feature()
    {
        
    }
    virtual void analyze() const = 0;
};

class LandFeature : public Feature 
{
public:
    LandFeature(const string& name) : Feature(name)
    {
        
    }
    void analyze() const override
    {
        cout << "LandFeature \"" << Name << "\": land area detected." << endl;
    }
};

class WaterFeature : public Feature 
{
public:
    WaterFeature(const string& name) : Feature(name)
    {
        
    }
    void analyze() const override
    {
        cout << "WaterFeature \"" << Name << "\": water body detected." << endl;
    }
};

class SinglyLinkedList 
{
    struct Node 
    {
        int FeatureID;
        Feature* feature;
        Node* next;
        Node(int id, Feature* f)
        {
            FeatureID = id;
            feature = f;
            next = nullptr;
        }
    };

    Node* head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    ~SinglyLinkedList()
    {
        Node* cur = head;
        while (cur != nullptr)
        {
            Node* tmp = cur->next;
            if (cur->feature != nullptr)
            {
                delete cur->feature;
                cur->feature = nullptr;
            }
            delete cur;
            cur = tmp;
        }
        head = nullptr;
    }

    void insertAtEnd(int featureID, Feature* f)
    {
        if (f == nullptr)
        {
            return;
        }
        Node* node = new Node(featureID, f);
        if (head == nullptr)
        {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = node;
    }

    bool deleteByID(int featureID)
    {
        Node* cur = head;
        Node* prev = nullptr;
        while (cur != nullptr && cur->FeatureID != featureID)
        {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr)
        {
            return false;
        }
        if (prev == nullptr)
        {
            head = cur->next;
        }
        else
        {
            prev->next = cur->next;
        }
        if (cur->feature != nullptr)
        {
            delete cur->feature;
            cur->feature = nullptr;
        }
        delete cur;
        return true;
    }

    void displayAll() const
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        Node* cur = head;
        while (cur != nullptr)
        {
            cout << "FeatureID " << cur->FeatureID << " -> ";
            if (cur->feature != nullptr)
            {
                cur->feature->analyze();
            }
            else
            {
                cout << "(no feature)" << endl;
            }
            cur = cur->next;
        }
    }

    void reverseList()
    {
        Node* prev = nullptr;
        Node* cur = head;
        while (cur != nullptr)
        {
            Node* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head = prev;
    }
};

int main()
{
    SinglyLinkedList list;

    list.insertAtEnd(101, new LandFeature(string("Forest")));
    list.insertAtEnd(102, new WaterFeature(string("River")));
    list.insertAtEnd(103, new LandFeature(string("Mountain")));
    list.insertAtEnd(104, new WaterFeature(string("Lake")));

    cout << "Initial list:" << endl;
    list.displayAll();

    cout << endl;
    cout << "Deleting FeatureID 102..." << endl;
    bool deleted = list.deleteByID(102);
    if (deleted == true)
    {
        cout << "Deleted 102" << endl;
    }
    else
    {
        cout << "102 not found" << endl;
    }

    cout << "After deletion:" << endl;
    list.displayAll();

    cout << endl;
    cout << "Reversing list..." << endl;
    list.reverseList();
    cout << "After reversing:" << endl;
    list.displayAll();

    return 0;
}
