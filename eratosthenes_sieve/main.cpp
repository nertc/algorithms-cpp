#include <unordered_map>

class eratosthenes_sieve
{
private:
    unsigned long long _limit = 0;
    const unsigned long long MIN_PRIME = 2;
    std::unordered_map<long long, long long> _firstDivisorOf;

    void calculate()
    {
        for (unsigned long long number = MIN_PRIME; number <= _limit; ++number)
        {
            if (!isPrime(number))
                continue;
            _firstDivisorOf[number] = number;

            for (unsigned long long multiple = number * number; multiple <= _limit; multiple += number)
            {
                if (!_firstDivisorOf[multiple])
                    _firstDivisorOf[multiple] = number;
            }
        }
    }

public:
    eratosthenes_sieve(unsigned long long limit)
    {
        _limit = limit;

        calculate();
    }

    long long getFirstDivisor(unsigned long long target)
    {
        if (target < MIN_PRIME)
            return target;
        return _firstDivisorOf[target];
    }

    bool isPrime(unsigned long long target)
    {
        if (target < MIN_PRIME)
            return false;
        return !_firstDivisorOf[target] || target == getFirstDivisor(target);
    }
};