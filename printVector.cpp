#include <vector>
#include <iostream>

void printVector(std::vector<int> numVec)
{
    std::cout
        << "[";
    for (int i = 0; i < numVec.size(); i++)
    {
        std::cout
            << numVec[i]
            << " ";
    }
    std::cout
        << "]\n";
}