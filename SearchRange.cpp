/*
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm's runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
*/

#include <vector>

class Solution
{
    public:
        std::vector<int> searchRange (int Array[], int ArraySize, int Target)
        {
            std::vector<int> solutionVec;

            for (int n = 0; n < ArraySize; n++)
            {
                if ( Array[n] == Target )	// first hit
                {
                    solutionVec.push_back(n);
                    for (; n < ArraySize; n++)	// if there's more in the array
                    {
                        if (Array[n] > Target)
                        {
                            solutionVec.push_back (n-1);
                            return solutionVec;
                        }
                    }
                    solutionVec.push_back ( ArraySize-1 );
                    return solutionVec;
                }
            }
            solutionVec.push_back (-1);
            solutionVec.push_back (-1);
            return solutionVec;
        }
};
