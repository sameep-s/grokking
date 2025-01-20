
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Time complexity - o(N)
    // Space complexity - o(N)
    int maxProfit2(vector<int> prices)
    {
        int buy = prices[0];
        int profit = 0;
        for (int price : prices)
        {
            if (price < buy)
                buy = price;
            else if (profit < price - buy)
                profit = price - buy;
        }

        return profit;
    }

    int maxProfit(vector<int> prices)
    {

        if (prices.size() == 0)
            return 0;

        return maxProfitHelper(prices, prices[0], 0);
    }

    int maxProfitHelper(vector<int> prices, int buy, int profit)
    {
        // Base case
        if (prices.size() == 0)
            return profit;

        vector<int> sliced(prices.begin() + 1, prices.end());
        // Recursive case
        if (prices[0] < buy)
            buy = prices[0];

        else if (prices[0] - buy > profit)
            profit = prices[0] - buy;

        return maxProfitHelper(sliced, buy, profit);
    }
};

int main()
{
    Solution sol;

    int profit = sol.maxProfit2({7, 2, 1, 5, 3, 6, 4});

    printf("profit %d\n", profit);

    return 0;
}
