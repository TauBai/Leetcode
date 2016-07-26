/*

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.reserve(numRows);
        if(numRows == 0) return result;
        if(numRows == 1) return {{1}};
        vector<int> firstRow{1};
        result.push_back(firstRow);

        for(int i = 1;numRows > 1; --numRows, ++i){
            vector<int> newVec(i+1);
            vector<int> prevVec = *result.rbegin();
            adjacent_difference(prevVec.begin(),prevVec.end(),newVec.begin(),plus<int>());
            newVec[i] = 1;
            result.push_back(newVec);
        }
        return result;
    }
};

/*

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?

Subscribe to see which companies asked this question

Show Tags
Show Similar Problems


*/
// O(k) space
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex+1);
        for(int i= 0; i <= rowIndex; ++i){
            result[i] = 1;
            for(int t = i-1; t > 0;--t){
                result[t] = result[t] +result[t-1];
            }
            
        }
        return result;
    }
};
