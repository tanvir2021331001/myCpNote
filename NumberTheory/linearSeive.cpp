vector<int> linearSieve(int n)
{
  vector<int> primes;
  vector<int> lp(n + 1, 0); //---lowest prime factor lp

  for (int i = 2; i <= n; i++)
  {
    if (lp[i] == 0) 
    { 
      lp[i] = i;
      primes.push_back(i);
    }

    for (int p : primes)
    {
      if (p > lp[i] || i * p > n)
        break;
      lp[i * p] = p;
    }
  }

  return primes;
}
