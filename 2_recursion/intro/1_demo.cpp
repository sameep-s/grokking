#include <iostream>

using namespace std;

void countDown(int n)
{

    cout << "n :" << n << endl;

    // Base case
    if (n == 1)
    {
        // Prologue operaiton
        cout << "Happy new year" << endl;
        return;
    }

    // Recursive case
    countDown(--n);
    // No operaion in epilogue
}

int main()
{
    countDown(10);

    return 0;
}