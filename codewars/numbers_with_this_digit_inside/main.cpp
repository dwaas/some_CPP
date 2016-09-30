#include <string>	                // std::to_string()
#include <numeric>			// std::accumulate
#include <functional>		        // std::multiplies
#include <vector>                       //std::vector

#include <boost/range/irange.hpp>       //boost::irange()

std::vector<long> numbersWithDigitInside(long x, long d)
{
    using namespace std;
//degenerate case - a priori defined cases
    vector<long> result(3, 0);
    const bool invalid_input = (x <= 0 || d < 0 || d > 9 || d > x);
    if (invalid_input) {return result;}

//general case
    vector<long> valid_numbers;
    valid_numbers.reserve(x); // roughest estimate

    //x+1 because we include the number x itself
    for(unsigned n : boost::irange <long> (1,(x+1) ) )
    {
      bool digit_in_n = to_string(n).find(to_string(d)) != string::npos;
      if(digit_in_n ){valid_numbers.push_back(n);}
    }

    result[0] = valid_numbers.size();
    result[1] = accumulate(valid_numbers.begin(), valid_numbers.end(), 0L);
    result[2] = valid_numbers.empty()?
                  0 :
                  (accumulate(valid_numbers.begin(), valid_numbers.end(), 1L, multiplies<long>()));

    return result;
}
