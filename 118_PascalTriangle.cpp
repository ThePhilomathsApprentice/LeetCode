#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <stdexcept>

template <typename S>
std::ostream &operator<<(std::ostream &os,
                         const std::vector<S> &vector)
{
    // Printing all the elements
    // using <<
    for (auto element : vector)
    {
        os << element << " ";
    }
    return os;
}

/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Constraints:
1 <= numRows <= 30

Result:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 6.9 MB, less than 14.81% of C++ online submissions for Pascal's Triangle.

*/
class Solution
{
private:
    std::map<int, double> factorialMap;

    double fact(int f)
    {
        double factorial = 1;
        if (f <= 1)
        {
            return (factorial);
        }
        else
        {
            try
            {
                factorial = factorialMap.at(f);
            }
            catch (const std::out_of_range &oor)
            {
                for (int i = 1; i <= f; i++)
                {

                    factorial *= i;
                }

                factorialMap.insert(std::pair<int, double>(f, factorial));
            }

            return (factorial);
        }

        return (factorial);
    }

    double nCk(int n, int k)
    {

        double result = ((fact(n) / fact(n - k)) / (fact(k))); // static_cast<int>

        return result;
    }

    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> pascalIntRow;

        for (int i = 0; i <= rowIndex; i++)
        {
            pascalIntRow.push_back(round(nCk(rowIndex, i)));
        }

        return pascalIntRow;
    }

public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> pascalTriangle;

        for (int i = 0; i < numRows; i++)
        {
            pascalTriangle.push_back(getRow(i));
        }

        return pascalTriangle;
    }
};

int main()
{

    Solution S1;
    std::vector<std::vector<int>> pascalTriangle = S1.generate(5);
    for (auto elm : pascalTriangle)
    {
        std::cout << elm << std::endl;
    }
    return 0;
}
