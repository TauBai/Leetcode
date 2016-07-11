/*
 * full details https://en.wikipedia.org/wiki/Two%27s_complement
 * https://discuss.leetcode.com/topic/49771/java-simple-easy-understand-solution-with-explanation
 *
 first to find a carry , then to find a different bit and assign it to a, 
 then to shift the carry one position left and assign it to b. 
 iterate till there b == 0
 
 * by zhaolz 
 */

class Solution {
public:
    int getSum(int a, int b) {
        return (b == 0) ? a : getSum(a ^ b, (a & b) << 1);
    }
};
