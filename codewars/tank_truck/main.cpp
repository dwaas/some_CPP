#include <cmath> //std::floor

class VolTank
{
public:
    static int tankVol(int h, int d, int vt);
};

typedef long double ld;

int
VolTank::tankVol(int h, int d, int vt)
{
  const ld r = d / 2.0;
  const ld area_circle = M_PI * std::pow (r, 2);

//circular sector (as a function of theta)
  //pi and two get elided
  const ld area_sec = std::pow(r, 2) * std::acos( (r -h) / r);

//isosceles triangle within the sector

  //base and height refer to half of the isosceles tr (right triangle)
  //pitagora's
  const ld tr_base = std::sqrt(2 * r * h - std::pow(h, 2) );

  const ld tr_height = (r - h);

  //* 2.0 and / 2.0 cancel out
  const ld area_tr = tr_height * tr_base;

  const ld fluid_area = area_sec - area_tr;
  const ld ratio = fluid_area / area_circle;

  return std::floor(ratio * vt);
}
