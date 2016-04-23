#include <iostream>
#include <vector>
using namespace std;
string reverseVowels(string s);

int main()
{
    string s ="helll";
    cout << reverseVowels(s);
}
string reverseVowels(string s) {
        string::iterator iter = s.begin();
        string::iterator iterend = s.end();
        vector<string::iterator> iteratorbox;
        for(;iter != iterend ; ++iter){
            if((*iter) == 'a' ||
               (*iter) == 'e' ||
               (*iter) == 'i' ||
               (*iter) == 'o' ||
               (*iter) == 'u'){
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
