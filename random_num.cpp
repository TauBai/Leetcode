//  generate random number,  this is for houghellipse

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
std::vector<size_t> trashnum_box;
int main()
{
    size_t k = 3;
    
    bool compare_trashnum(size_t t);
    size_t t1 , t2 , t3;                  //随机生成三个点
    srand((unsigned) time(NULL));
        do {
            
            t1 = rand() % k;
        }
        while(compare_trashnum(t1));
        trashnum_box.push_back(t1);
    srand((unsigned) time(NULL));
        do {
            t2 = rand() % k;
        }
        while(compare_trashnum(t2));
        trashnum_box.push_back(t2);
    srand((unsigned) time(NULL));
        do {
            t3 = rand() % k;
        }
        while(compare_trashnum(t3));
        trashnum_box.push_back(t3);

        std::cout << "t1 = " << t1 << std::endl
                  << "t2 = " << t2 << std::endl
                  << "t3 = " << t3 << std::endl;
}

bool compare_trashnum(size_t t)
{
    for (size_t i = 0 ; i < trashnum_box.size(); ++i)
    {
        if ( t == trashnum_box[i])
            return true;

    }
    return false;
}
