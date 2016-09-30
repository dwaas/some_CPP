#include <algorithm>            //std::minmax_element()
#include <numeric>              //std::accumulate()
#include <vector>               //std::vector

int sum(std::vector<int> numbers)
{
//if vector has only two elements, they will be both deleted
  if(numbers.size() <= 2) {return 0;}

  //accumulate and subtract min and max positions.
  auto minmax = std::minmax_element(numbers.begin(), numbers.end());

  return std::accumulate(numbers.begin(), numbers.end(), 0) -
    (*minmax.first + *minmax.second);
}
kku
