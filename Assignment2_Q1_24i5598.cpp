#include <iostream>
using namespace std;

void ChangeLocation(char *Array, int b1, int b2) // Question 1 part a begins here
{
    if (Array == nullptr) return;
    if (b1 >= b2) return;

    int len = 0;
    while (Array[len] != '\0') ++len;

    if (b1 < 1 || b2 > len) return;

    char temp = Array[b1 - 1];
    Array[b1 - 1] = Array[b2 - 1];
    Array[b2 - 1] = temp;

    ChangeLocation(Array, b1 + 1, b2 - 1);
} // question 1 part a ends here

void PrintPattern(int &n, int line = 1) // question 1 part b begins here
{
    if (line > n) return; 

    if (line == 1)
        cout << n << endl;
    else if (line == 2)
        cout << n/2 << " " << n/2 << endl;
    else {
        for (int i = 1; i < line; i++)
            cout << "1 ";
        cout << n - line + 1 << endl;
    }

    PrintPattern(n, line + 1); // question 1 part b ends here
}

int main()
{
    char arr[] = "COMPUTER"; // Question 1 part a begins here
    cout << "Original: ";
    for (int i = 0; arr[i] != '\0'; ++i) cout << arr[i];
    cout << endl;

    ChangeLocation(arr, 3, 7); 

    cout << "After ChangeLocation(3,7): ";
    for (int i = 0; arr[i] != '\0'; ++i) cout << arr[i];
    cout << endl; // question 1 part a ends here

    int n; // Question 1 part b begins here
    cout << "Enter any number = ";
    cin >> n;
    PrintPattern(n); // question 1 part b ends here

    return 0;
}