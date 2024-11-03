#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    // Time complexity - logN
    // Space complexity - logN as space complexity is dependent on max depth of recursion
    string decimalToBinary(int decimal)
    {
        if (decimal == 0)
            return "";

        return decimalToBinary(decimal / 2) + to_string(decimal % 2);
    }
};

int main()
{
    Solution s;
    cout << s.decimalToBinary(10) << endl;

    return 0;
}