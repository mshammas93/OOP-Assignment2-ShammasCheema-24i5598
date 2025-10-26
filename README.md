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
