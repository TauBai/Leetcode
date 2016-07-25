class Solution {
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
