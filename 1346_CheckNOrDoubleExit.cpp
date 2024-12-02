#include <vector>
#include <algorithm>
#include <iostream>

void printVector(std::vector<int> numVec);

/*
Given an array arr of integers, check if there exist two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]


Example 1:
Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]

Example 2:
Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.
*/

class Solution
{
public:
    bool checkIfExist(std::vector<int> &arr)
    {
        std::unordered_map<int, int> seen;

        for (int i = 0; i < arr.size(); i++)
        {
            if ((arr[i] % 2) == 0)
            {
                // EVEN
                // std::cout << "EVEN.\n";
                // std::cout << (arr[i]>>1) << "\n";
                // std::cout << (arr[i]<<1) << "\n";
                if (seen.contains(arr[i] >> 1) ||
                    seen.contains(arr[i] << 1))
                {
                    return true;
                }
            }
            else
            {
                // ODD
                //  std::cout << "ODD.\n";
                //  std::cout << (arr[i]<<1) << "\n";
                if (seen.contains(arr[i] << 1))
                {
                    return true;
                }
            }
            seen[arr[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution S1;
    std::vector<int> vec1 = {10, 2, 5, 3};
    std::vector<int> vec2 = {3, 1, 7, 11};
    std::vector<int> vec3 = {3, 1, 7, 11, 22};

    std::cout
        << "vec1: ";
    printVector(vec1);

    std::cout
        << "vec2: ";
    printVector(vec2);

    std::cout
        << "vec3: ";
    printVector(vec3);

    std::cout
        << "Exists in vec1?: " << (S1.checkIfExist(vec1) ? "true" : "false") << "\n"
        << "Exists in vec2?: " << (S1.checkIfExist(vec2) ? "true" : "false") << "\n"
        << "Exists in vec3?: " << (S1.checkIfExist(vec3) ? "true" : "false") << "\n"
        << "\n";
}