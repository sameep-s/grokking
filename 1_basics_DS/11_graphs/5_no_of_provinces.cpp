#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int i)
    {
        for (int j = 0; j < isConnected.size(); j++)
            if (isConnected[i][j] == 1 && !visited[j])
            {
                visited[j] = true;
                dfs(isConnected, visited, j);
            }
    }

    int findProvinces(vector<vector<int>> &isConnected)
    {
        int size = isConnected.size();
        int provinces = 0;
        vector<bool> visited(size, false);

        for (int i = 0; i < size; i++)
            if (!visited[i])
            {
                dfs(isConnected, visited, i);
                provinces++;
            }

        return provinces;
    }
};

int main()
{
    Solution solution;

    std::vector<std::vector<int>> test1 = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    std::vector<std::vector<int>> test2 = {{1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 0}, {1, 0, 0, 1}};
    std::vector<std::vector<int>> test3 = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    std::cout << solution.findProvinces(test1) << std::endl; // Expected output: 2
    std::cout << solution.findProvinces(test2) << std::endl; // Expected output: 2
    std::cout << solution.findProvinces(test3) << std::endl; // Expected output: 3
}