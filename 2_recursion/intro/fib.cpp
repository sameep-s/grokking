#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Map is used as cache Dynamic Programming
unordered_map<int, int> cache;

// Memoization -> Top-Bottom
int fib(int n)
{

    if (cache.find(n) != cache.end())
        return cache[n];

    // Base case
    if (n == 0 || n == 1)
        return n;

    // Recursive case
    cache[n] = fib(n - 1) + fib(n - 2);

    return cache[n];
}

// Tabulation -> Bottom-Up
int fib_tab(int n)
{
    vector<int> table(n + 1);

    //  Base case
    table[0] = 0;
    table[1] = 1;

    // Recursive case
    for (int i = 2; i <= n; i++)
        table[i] = table[i - 1] + table[i - 2];

    return table[n];
}

int main()
{
    cout << fib(10) << endl;     // Memoization
    cout << fib_tab(10) << endl; // Tabulation
}