/*

Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.



*/



class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        int ctNegSign = 0;
        for(auto a : str){
            if (a>='0' && a<='9'){
                result *= 10;
                result += a - '0';
            }
            if(a == '-')
                ++ctNegSign;
        }
        if( ctNegSign%2)
            result = -result;
        return result;
    }
};
