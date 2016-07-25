/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

*/

//Boyer–Moore majority vote algorithm
//https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
//if no element appears more than n/2, the element it returns may not be the one that apears most times
// say [1,1,3,3,3,9,1,9,9,3]

class Solution1 {
public:
    int majorityElement(vector<int> &num) {
        int majorityIndex = 0;
        for (int count = 1, i = 1; i < num.size(); i++) {
            num[majorityIndex] == num[i] ? count++ : count--;
            if (count == 0) {
                majorityIndex = i;
                count = 1;
            }
        }
        return num[majorityIndex];
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int major, counts = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (!counts) {
                major = nums[i];
                counts = 1;
            }
            else counts += (nums[i] == major) ? 1 : -1;
        }
        return major;
    }
};

/////////////////////////////////////////////////////////////////

//hashtable 
// if no major element found, it returns one appears most

class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts; 
        int n = nums.size();
        for (int i = 0; i < n; i++)
            if (++counts[nums[i]] > n / 2)
                return nums[i];
        int val;
        int maxct = 0;
        for(int i = 0; i < n ; ++i){
            if(counts[nums[i]] > maxct){
                maxct = counts[nums[i]];
                val = nums[i];
            }
        }
        return val;
    }
};
