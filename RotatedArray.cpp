/*

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

*/
// for trivial assignment operator,  memmove() is extremely fast
class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> newnums = nums;
        k = k % nums.size();
        if(k > 0){
            copy(nums.end()-k, nums.end(),newnums.begin());
            copy(nums.begin(),nums.end()-k,newnums.begin()+k);
            nums = newnums;
        }
    }
};
// in-place solution  O(1) space and O(n) time
class Solution2 {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        for(; k >0 ; --k){
            int temp = *nums.rbegin();
            copy_backward(nums.begin(), nums.end()-1,nums.end());
            nums[0] = temp;
        }
    }
};
