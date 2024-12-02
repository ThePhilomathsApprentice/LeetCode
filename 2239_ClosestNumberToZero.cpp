#include <vector>
#include <iostream>
#include <cmath>

void printVector(std::vector<int> numVec);

/*
Given an integer array nums of size n,
return the number with the value closest to 0 in nums.

If there are multiple answers, return the number with the largest value.


Example 1:

Input: nums = [-4,-2,1,4,8]
Output: 1
Explanation:
The distance from -4 to 0 is |-4| = 4.
The distance from -2 to 0 is |-2| = 2.
The distance from 1 to 0 is |1| = 1.
The distance from 4 to 0 is |4| = 4.
The distance from 8 to 0 is |8| = 8.
Thus, the closest number to 0 in the array is 1.
Example 2:

Input: nums = [2,-1,1]
Output: 1
Explanation: 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.

*/

class Solution
{
public:
    int findClosestNumber(std::vector<int> &nums)
    {
        int closest = nums[0];
        // iterate over nums
        //   get mod of number.
        //   check diffrence with zero
        //   is it smaller than closest?
        //     -y : update closest
        //     -n : go to next number.
        for (int i = 0; i < nums.size(); i++)
        {
            if ((std::abs(nums[i]) == std::abs(closest)) &&
                (nums[i] > closest))
            {
                closest = nums[i];
            }
            closest = (std::abs(nums[i]) < std::abs(closest)) ? nums[i] : closest;
        }
        return closest;
    }
};

int main()
{
    Solution S1;
    std::vector<int> number = {-1, 1, 2, 15};

    std::cout
        << "Number Vector: ";
    printVector(number);

    int closestNumber = S1.findClosestNumber(number);

    std::cout
        << "ClosestNumber: " << closestNumber
        << "\n";
}