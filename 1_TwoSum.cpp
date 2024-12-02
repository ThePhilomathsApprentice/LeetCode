#include <iostream>
#include <vector>
#include <unordered_map>

/*
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.



Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
*/

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++)
        {
            if (seen.contains(target - nums[i]))
            {
                // Found both numbers.
                return {seen[(target - nums[i])], i};
            }
            // Add that in the seen, if not already present.
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution S1;
    std::vector<int> number = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> tooSum = S1.twoSum(number, target);

    std::cout
        << "The vector in question: "
        << "[";
    for (int i = 0; i < number.size(); i++)
    {
        std::cout
            << number[i]
            << " ";
    }
    std::cout
        << "]\n";

    std::cout
        << "Target: " << target
        << "\n";

    std::cout
        << "Indexes that hit the target:\n";
    for (int i = 0; i < tooSum.size(); i++)
    {
        std::cout
            << "tooSum[i]: " << tooSum[i]
            << "\n";
    }
}