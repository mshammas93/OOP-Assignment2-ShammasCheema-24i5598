# OOP-Assignment2-ShammasCheema-24i5598
Assignment 2 for OOP class 

Question1a: 
Purpose: reverse (swap inward) the characters between two inclusive 1-based indices b1 and b2 in a null-terminated char array.
Preconditions: Array must be non-null and null-terminated; b1 and b2 are 1-based positions (1..length).
Steps inside ChangeLocation:
Return immediately if Array is null or if b1 >= b2 (base case).
Compute the string length to validate bounds.
If b1 < 1 or b2 > length, return (invalid bounds).
Swap Array[b1-1] and Array[b2-1].
Recurse with ChangeLocation(Array, b1+1, b2-1) to continue swapping the next inner pair.
Complexity: each recursion does a length scan O(L) plus a constant swap; overall worst-case O(k * L) where k ≈ (b2-b1)/2. Passing length or using pointer arithmetic would reduce to O(L).
Example: "COMPUTER", b1=3, b2=7
Swap positions 3 and 7: C O E P U T M R
Next recursion swaps 4 and 6: positions already correct for this example; recursion stops when b1 >= b2.
main() demonstrates by printing the array before and after calling ChangeLocation(arr, 3, 7).

Question1b:
The program takes an integer input n and prints a specific numeric pattern using recursion.
When the program starts, it asks the user to enter a number. The function PrintPattern is then called, which prints one line at a time based on the current line number. The same function calls itself repeatedly until all lines are printed.
For the first line, it simply prints the number n.
For the second line, it divides n into two equal parts and prints them side by side.
From the third line onward, it prints several 1s followed by a number that decreases as the lines progress.
The recursion continues until the line number becomes greater than n, at which point the function stops calling itself.
This approach avoids loops in the main logic and relies on recursive calls to move from one line to the next. The base case ensures the recursion ends properly.
In short, the function prints the desired pattern step by step using recursion without using arrays or additional helper functions.

Question2:
The program is designed to represent and manage different geographical features such as land and water using object-oriented programming and a singly linked list.
The base class Feature defines a general template for all types of features and includes a pure virtual function called analyze, which makes it an abstract class. Two derived classes, LandFeature and WaterFeature, inherit from Feature and each implement their own version of the analyze function. The LandFeature class prints a message indicating that land has been detected, while the WaterFeature class prints a message indicating that a water body has been detected.
The SinglyLinkedList class manages a list of these features. Each element in the list, called a node, stores a feature ID, a pointer to a Feature object, and a pointer to the next node. The class provides several functions: inserting a new feature at the end, deleting a feature using its ID, displaying all the features, and reversing the list order. The destructor ensures that all dynamically allocated memory is properly released when the program ends.
In the main function, a linked list is created and four features are added: a forest, a river, a mountain, and a lake. The list is first displayed in its original order. Then the program deletes the feature with ID 102, which is the river, and shows the updated list. Finally, the list is reversed and displayed again.
This program demonstrates key programming concepts such as abstraction, inheritance, polymorphism, and dynamic memory management, along with practical linked list operations like insertion, deletion, traversal, and reversal.

Question3:
The program manages a small library system using a doubly linked list to store book information. Each book has an ID, title, and author.
The Node class represents a single book in the list. Each node stores the book’s details and has two pointers: one pointing to the previous node and one pointing to the next node. This allows the list to be traversed both forward and backward.
The Library class manages the entire linked list. It has two pointers: head, which points to the first node, and tail, which points to the last node. The class provides several functions to handle different operations.
The addToBeginning function inserts a new book at the start of the list. If the list is empty, the new book becomes both the head and tail. Otherwise, it is linked before the current head.
The addToEnd function inserts a new book at the end of the list. If the list is empty, the new node becomes both the head and tail. Otherwise, it is linked after the current tail.
The addAtPosition function inserts a new book at a specific position. If the position is 1 or less, the book is added at the beginning. If the position is greater than the number of existing books, it is added at the end. Otherwise, the function finds the correct place and links the new node between two existing nodes.
The deleteBook function removes a book by its ID. It searches through the list, and when it finds the book, it adjusts the pointers of the surrounding nodes so that the book is removed safely. It also updates the head or tail pointers when deleting the first or last node.
The displayForward function shows all books starting from the head to the tail, while the displayBackward function shows them in reverse order, starting from the tail to the head.
In the main function, a Library object is created. Three books are added using different insertion methods: one at the beginning, one at the end, and one in the middle. The program then displays the list in both forward and backward directions. After that, the book with ID 2 is deleted, and the updated list is displayed again.
Overall, this program demonstrates how a doubly linked list can be used to efficiently manage a collection of records, allowing easy insertion, deletion, and traversal in both directions.

Question4:
This program creates a movie ticket queue where customers with more tickets get served first. Each customer has an ID, name, and ticket count, and the queue is made using a linked list.
When a customer joins, they are placed according to how many tickets they have so that those with higher numbers come first. The enqueue function adds them in order, dequeue removes the first customer, and display shows the list of all waiting customers.
In the main function, several customers are added, one is served, and the updated list is shown. This demonstrates a priority queue based on ticket quantity instead of arrival order

Question5a:
This program shows stack implementation using arrays and linked lists. Both versions include push and pop functions for adding and removing elements.
In part (a), a section of the word “COMPUTER” is reversed using both array and linked list stacks. Elements between two positions are pushed and then popped back to reverse their order.
In part (b), a numeric pattern of 1s and 2s is printed using both stack types. The stack helps reverse the order of numbers before displaying each line.
Overall, the code compares how array-based and list-based stacks work through reversing text and generating number patterns.
