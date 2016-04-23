/*
 Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

 */


class Solution {
public:
    string reverseVowels(string s) {
        string::iterator iter = s.begin();
        string::iterator iterend = s.end();
        vector<string::iterator> iteratorbox;
        for(;iter != iterend ; ++iter){
            if((*iter) == 'a' ||
               (*iter) == 'e' ||
               (*iter) == 'i' ||
               (*iter) == 'o' ||
               (*iter) == 'u' ||
               (*iter) == 'A' ||
               (*iter) == 'E' ||
               (*iter) == 'I' ||
               (*iter) == 'O' ||
               (*iter) == 'U'){
                   iteratorbox.push_back(iter);
               }
            
        }
        if(!iteratorbox.empty())
        {
            auto itbegin = iteratorbox.begin();
            auto itend =   iteratorbox.end() ;
            --itend;
            for(;itbegin < itend ; ++itbegin, --itend)
            {            
                char temp = **itbegin;
              *(*itbegin) = *(*itend); 
              *(*itend) = temp;
            }
        }
        return s;
}
};
