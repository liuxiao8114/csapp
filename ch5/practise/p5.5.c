/*
A. For degree n, how many additions and how many multiplications does this
code perform?

B. On our reference machine, with arithmetic operations having the latencies
shown in Figure 5.12, we measure the CPE for this function to be 5.00. Explain
how this CPE arises based on the data dependencies formed between
iterations due to the operations implementing lines 7–8 of the function.

*/
double poly(double a[], double x, long degree)
{
  long i;
  double result = a[0];
  double xpwr = x; /* Equals x^i at start of loop */
  
  for (i = 1; i <= degree; i++) {
    result += a[i] * xpwr;
    xpwr = x * xpwr;
  }
  return result;
}
