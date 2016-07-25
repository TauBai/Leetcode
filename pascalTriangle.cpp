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
