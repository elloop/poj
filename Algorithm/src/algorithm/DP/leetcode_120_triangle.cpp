#include "inc.h"
#include <vector>
using namespace std;

NS_BEGIN(elloop);


class Solution
{
public:
    // transfer equation:
    // 
    int minimumTotal(vector<vector<int>>& triangle)
    {
        return 0;
    }
};


BEGIN_TEST(LeetCodeDP, Triangle, @);

vector<vector<int>> mat =
{
    { 2 },
    { 3, 4 },
    { 6, 5, 7 },
    { 4, 1, 8, 3 }
};

for ( const auto & ary : mat )
{
    for ( auto const & elem : ary )
    {
        p(elem); p(" ");
    }
    cr;
}

Solution s;
psln(s.minimumTotal(mat));

END_TEST;



NS_END(elloop);