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

class Solution2
{
public:
    vector<int> sort(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);

        return nums;
    }

    int partition(vector<int> &nums, int low, int high)
    {
        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++)
            if (nums[j] < pivot)
                swap(nums[i++], nums[j]);

        swap(nums[i], nums[high]);

        return i;
    }

    void quickSort(vector<int> &nums, int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(nums, low, high);

            quickSort(nums, low, pivotIndex - 1);
            quickSort(nums, pivotIndex + 1, high);
        }
    }
};

class Solution3
{
public:
    vector<int> quickSort(vector<int> arr)
    {
        if (arr.size() > 1)
        {
            // Step 1 : calculate mid
            int pivot = arr[arr.size() / 2];

            vector<int> left, right, mid;

            for (int x : arr)
            {
                if (x < pivot)
                    left.push_back(x);
                else if (x > pivot)
                    right.push_back(x);
                else
                    mid.push_back(x);
            }

            left = quickSort(left);
            right = quickSort(right);

            left.insert(left.end(), mid.begin(), mid.end());
            left.insert(left.end(), right.begin(), right.end());

            return left;
        }
        return arr;
    }
};

// This is main function
int main()
{
    Solution3 sol;
    vector<vector<int>> examples = {

        {4, 2, 6, 8, 3},
        {22, 44, 23, 3, 4, 3, 2, 3, 5, 3, 5, 3, 598, 99, 100},
        {10, 5, 3, 7, 2, 8, 6},
        {1, 2, 12, 34, 3, 4, 5}

    };

    for (int i = 0; i < examples.size(); i++)
    {
        vector<int> nums = examples[i];
        vector<int> sortedNums = sol.quickSort(nums);

        printf("Sorted Array #%d :", i + 1);

        for (int num : sortedNums)
            printf("%d ", num);

        printf("\n");
    }

    return 0;
}
