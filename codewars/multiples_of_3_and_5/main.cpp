// intuition behind the algorithm: the first and the last multiples
// will always add to a constant. Knowing the number of (multiple) couples
// it's possible to calculate the sum of them in one go.
// NOTE: for k=1 we have gauss's summation of the first n numbers

// the pivot function is introduced because if the number of couples is odd,
// the central multiple would be left out.

int pivot(int n, int k)
{
  int multiple_couples = n / (2 * k);
  int central_couple = multiple_couples + 1;

  return k * central_couple;
}

int sum_of_couples(int n, int k)
{
  int first_multiple = k;
  int last_multiple = n / k * k;

  return (n / (2 * k) ) * (last_multiple + first_multiple);
}

int sum_of_multiples(int n, int k)
{
  if(n <= 0) {return 0;} // by definition
  else {n -= 1;}         // fixing ranges

  int sum = sum_of_couples(n,k);
  bool has_odd_multiples = (n / k) % 2;

  return sum + (has_odd_multiples * pivot(n,k) );
}

int solution(int number)
{
  //subtracting numbers counted twice
  return sum_of_multiples (number, 3) +
           sum_of_multiples (number, 5) -
           sum_of_multiples (number, 15);
}
