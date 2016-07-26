/*

Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

Subscribe to see which companies asked this question


*/





//////// runtime error

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> solution;
        
        for(auto i =nums.begin() ; i != nums.end() -1; ++i){
            for(auto j = i+1; j != nums.end(); ++j){
                if( *i + *j == target){
                    solution.push_back(i-nums.begin());
                    solution.push_back(j-nums.begin());
                }
            
            }
        }
        if(solution.empty())
            cout << "No pairs found"<< endl;
        return solution;
    }
};



///////////////////////////////////////////////////////////////////////////////////
////////////         Hash table                 ///////////////////////////////////////


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int,int> hash;
        for (int i = 0; i < nums.size(); i++){
            int pairToFind = target - nums[i];
            if(hash.find(pairToFind) != hash.end()){
                result.push_back(hash[pairToFind] );
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
	    }
	
        return result;
    }
};

