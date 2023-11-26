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
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Constraints:
0 <= rowIndex <= 33

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

        double result = ((fact(n) / fact(n - k)) / (fact(k)));

        return result;
    }

public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> pascalIntRow;

        if (rowIndex > 31)
        {
            std::cout << "WARNING: Please keep numbers <=31.\n";
        }

        for (int i = 0; i <= rowIndex; i++)
        {
            pascalIntRow.push_back(round(nCk(rowIndex, i)));
        }

        return pascalIntRow;
    }
};

int main()
{
    Solution S1;
    std::vector<int> pascalTriangle2 = S1.getRow(5);
    std::cout << pascalTriangle2 << std::endl;

    pascalTriangle2 = S1.getRow(32);
    std::cout << pascalTriangle2 << std::endl;

    return 0;
}
