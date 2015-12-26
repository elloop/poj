#ifdef _MSC_VER
#pragma once
#else
_Pragma("once")
#endif

#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <iterator>
#include <functional>
#include <numeric>
#include <algorithm>

class Range {
  std::pair<int, int> range_;
public:
  Range(std::pair<int, int> range) : range_(range) {}
  std::pair<int, int> range() { return range_; }
};

class Repeat {
  std::pair<int, int> repeat_;
public:
  Repeat(std::pair<int, int> repeat) : repeat_(repeat) {}
  std::pair<int, int> repeat() { return repeat_; }
};

template <typename Container>
inline void insertElements(Container& con, int first, int last) {
  for ( int i = first; i <= last; ++i ) {
    con.insert(con.end(), i);
  }
}

template <typename Con>
inline void insertRange(Con& con, Range range) {
  for ( int i = range.range().first; i < range.range().second; i++ ) {
    con.insert(con.end(), i);
  }
}

template <typename Con>
inline void insertRepeat(Con& con, Repeat repeat) {
  auto count = repeat.repeat().first;
  while ( count-- ) {
    con.insert(con.end(), repeat.repeat().second);
  }
}

template <typename ForwardIter, typename T>
ForwardIter find_before(ForwardIter beg, ForwardIter end, const T &val)
{
    auto posBefore = beg;
    while (beg != end)
    {
        if (*beg == val) 
        {
            return posBefore;
        }
        posBefore = beg;
        ++beg;
    }
    return end;
}

template <typename ForwardIter, typename Pred>
ForwardIter find_before_if(ForwardIter beg, ForwardIter end, Pred op)
{
    auto posBefore = beg;
    ++beg;
    while (beg != end)
    {
        if (op(*beg))
        {
            return posBefore;
        }
        posBefore = beg;
        ++beg;
    }
    return end;
}