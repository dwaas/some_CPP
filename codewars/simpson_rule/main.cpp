#include <cmath>                        // std::sin, std::pow
#include <boost/range/irange.hpp>       // boost:irange
#include <boost/range/numeric.hpp>      // boost:accumulate

class SimpsonIntegration
{
public:
    static double simpson(unsigned n);
};

double
SimpsonIntegration::simpson(unsigned n)
{
    constexpr long double a = 0, b = M_PI;
    long double h_n = (b - a) / n;

    auto x = [&] (unsigned j){return a + j*h_n;};
    auto f = [](long double x){return pow(std::sin(x),3) * 3 / 2 ;};

    long double sum = boost::accumulate(
                          boost::irange<unsigned>(1, n/2 + 1), 0.0L,
                          [&](long double acc, unsigned j){
                            return acc + f(x(2*j - 2) ) +
                              4 * f(x(2*j - 1) ) +
                              f(x(2*j) );
                          });

    return h_n / 3 * sum;
}
