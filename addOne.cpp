// addOne.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
namespace Solution
{
    vector<int> plusOne(vector<int> &A)
    {
        // reverse the vector to make it easier to work with
        reverse(A.begin(), A.end());

        // if the last number is 9, then add a 0 to the end of the vector (solves 99 to 100)
        if (A[A.size() - 1] == 9)
        {
            A.push_back(0);
        }

        // increase by 1
        bool carry = false;
        for (size_t i = 0; i < A.size(); i++)
        {
            A[i] = A[i] + 1;
            // check if the number needs to be wrapped around 10 and if one should be carried forward
            if (A[i] % 10 == 0)
            {
                A[i] = 0;
                carry = true;
            }
            // get out of the loop if there's no need to carry
            if (carry == false)
            {
                break;
            }
            carry = false;
        }

        // pop the trailing 0
        while (A[A.size() - 1] == 0)
        {
            A.pop_back();
        }

        // reverse back the vector and return the increased value
        reverse(A.begin(), A.end());
        return A;
    }
}

int main()
{
    string actual;

    // test cases

    // 123 to 124
    vector<int> data = {1, 2, 3};
    vector<int> result = Solution::plusOne(data);
    
    for (size_t i = 0; i < result.size(); i++)
    {
        actual.append(to_string(result[i]));
    }
    assert(actual == "124");
    actual.clear();

    // 009 to 10
    data = { 0, 0, 9 };
    result = Solution::plusOne(data);

    for (size_t i = 0; i < result.size(); i++)
    {
        actual.append(to_string(result[i]));
    }
    assert(actual == "10");
    actual.clear();

    // 99 to 100
    data = { 9, 9 };
    result = Solution::plusOne(data);

    for (size_t i = 0; i < result.size(); i++)
    {
        actual.append(to_string(result[i]));
    }
    assert(actual == "100");
    actual.clear();

    return 0;
}
