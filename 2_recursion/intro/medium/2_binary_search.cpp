#include <bits/stdc++.h>

class Solution
{
public:
    // Binary search using recursion
    // Time Complexity - O(LogN)
    // Space Complexity - O(LogN)
    bool binarySearch(const vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;

        return binarySearchHelper(nums, target, l, r);
    }

    bool binarySearchHelper(vector<int> nums, int target, int l, int r)
    {
        // Base case
        if (l > r)
            return false;

        // Find mid
        int mid = (l + r) / 2;

        // Recursive case
        if (nums[mid] > target)
            return binarySearchHelper(nums, target, l, mid - 1);
        else if (nums[mid] < target)
            return binarySearchHelper(nums, target, mid + 1, r);
        else
            return true;
    }
};

int main()
{
    Solution sol;
    // Example inputs
    vector<vector<int>> examples = {
        {1, 2, 3, 4, 5},
        {2, 4, 6, 8, 10},
        {3, 6, 9, 12, 15}};

    vector<int> keys = {4, 5, 15};

    for (int i = 0; i < examples.size(); i++)
    {
        const vector<int> &nums = examples[i];
        int target = keys[i];
        bool result = sol.binarySearch(nums, target);

        printf("Example %d -> %d found ? %s.\n", (i + 1), target, result ? "Yes" : "No");
    }

    return 0;
}
