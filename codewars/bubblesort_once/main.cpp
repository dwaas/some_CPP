#include <algorithm>            //std::swap
#include <vector>               //std::vector

std::vector<int> bubbleSortOnce(std::vector<int> input)
{
    for (auto it=input.begin(); it < (input.end()-1); ++it)
    {
        if ( *it > *(it+1) ) { std::swap(*it,*(it+1) ); }
    }

    return input;
}
