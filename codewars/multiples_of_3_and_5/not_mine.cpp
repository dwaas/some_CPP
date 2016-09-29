//this was posted by vsouzas; I admit that my solution is overly complex 
//compared to the following one. 

int solution(int number) 
{
  int sum = 0;
  for (int n = 3; n < number; n++) {
    if ((n%3 == 0) || (n%5 == 0))
      sum += n;
  }
  return sum;
}
