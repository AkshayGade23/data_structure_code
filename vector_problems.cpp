#include <iostream>
using namespace std;
#include <vector>

bool canJump(vector<int> &nums)
{
    if (nums[0] == nums.size() - 1 || nums.size()==1)
        return true;

    for (int i = nums[0]; i > 0; i--)
    {
        if (i >= nums.size() )
            continue;

        vector<int> subvector(nums.begin() + i, nums.end());
        if (canJump(subvector))
            return true;
    }
    return false;
}

int main()
{
    vector<int> v{2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    cout << canJump(v);
    return 0;
}
