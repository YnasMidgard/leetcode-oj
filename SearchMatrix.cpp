/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
  1. Integers in each row are sorted from left to right.
  2. The first integer of each row is greater than the last integer of the previous row.
*/

#include <vector>

class Solution
{
    public:
        bool searchMatrix (std::vector<std::vector<int> > &matrix, int target)
        {
            if ( matrix.size() == 1 )
            {
                return ifTarget ( matrix.front(), target );
            }
            else
            {
                for (int n = 0; n < matrix.size(); n++)
                {
                    if ( matrix[n].front() > target )
                    {
                        if (n == 0)
                           return false;
                        else
                            return ifTarget ( matrix[n-1], target );
                    }
                }
                return ifTarget ( matrix.back(), target );
            }
        }

        bool ifTarget (std::vector<int> &myVec, int target)
        {
            for (int k = 0; k < myVec.size(); k++)
            {
                if ( myVec.at(k) == target )
                    return true;
            }
            return false;
        }
};
