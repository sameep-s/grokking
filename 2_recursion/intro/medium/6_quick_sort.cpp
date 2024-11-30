#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sort(vector<int> &nums)
    {
        quickSort(nums);

        return nums;
    }

    // Time complexity - O(N*logN)
    // Space complexity - O(N*logN)
    void quickSort(vector<int> &nums)
    {
        if (nums.size() > 1)
        {

            // Step1 : Create a pivot element
            int pivot = nums[nums.size() / 2];

            // Step2 : every element less than pivot goes to left arr,every element less than pivot goes to right arr
            vector<int> left, right, mid;

            for (int x : nums)
            {
                if (x > pivot)
                    right.push_back(x);
                else if (x < pivot)
                    left.push_back(x);
                else
                    mid.push_back(x);
            }

            // Step 3: recursive call to quicksort and make sure that the size of nums is greater than 1
            quickSort(left);
            quickSort(right);

            // Step 4: Merge all arrays left, middle, end
            left.insert(left.end(), mid.begin(), mid.end());
            left.insert(left.end(), right.begin(), right.end());

            // Add those values in nums
            nums.clear();
            nums.insert(nums.begin(), left.begin(), left.end());
        }
    }
};

// This is main function
int main()
{
    Solution sol;
    vector<vector<int>> examples = {
        {4, 2, 6, 8, 3},
        {10, 5, 3, 7, 2, 8, 6},
        {1, 2, 3, 4, 5}};

    for (int i = 0; i < examples.size(); i++)
    {
        vector<int> nums = examples[i];
        sol.sort(nums);

        printf("Sorted Array #%d :", i + 1);

        for (int num : nums)
            printf("%d ", num);

        printf("\n");
    }

    return 0;
}
