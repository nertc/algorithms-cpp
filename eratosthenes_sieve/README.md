# Eratosthenes Sieve

__Eratosthenes algorithm to find prime numbers;__  
As by the definiton prime number is ["a positive integer that is not divisible without remainder by any integer except itself and 1, with 1 often excluded"](https://www.dictionary.com/browse/prime-number#:~:text=noun%20Mathematics.,and%207%20are%20prime%20numbers.) algorithm works only in range `0 - 18,446,744,073,709,551,615 (2^64)` (uses unsigned long long);  
  
Time Complexity: `~O(n*log(log(n)))`;

## Usage

### Creation
```cpp
// eratosthenes_sieve sieve_name(highest_number_to_check)
eratosthenes_sieve sieve(50);
```

### Find out if number is prime
*If `number_to_check` exceeds `highest_number_to_check`, this function produces error;*  
```cpp
// sieve_name.isPrime(number_to_check)
sieve.isPrime(7); // true
```

### Find out number's lowest prime divisor
*If `number_to_check` exceeds `highest_number_to_check`, this function produces error;*  
*If `number_to_check` is less, function returns `number_to_check`*  
```cpp
// sieve_name.getFirstDivisor(number_to_check)
sieve.getFirstDivisor(21); // 3
```

### Example
```cpp
#include "eratosthenes_sieve/main.cpp"
#include <iostream>

int main() {
    eratosthenes_sieve sieve(50);
    std::cout << std::boolalpha;
    std::cout << sieve.isPrime(0) << std::endl;             // false
    std::cout << sieve.getFirstDivisor(1) << std::endl;     // 1
    std::cout << sieve.getFirstDivisor(5) << std::endl;     // 5
    std::cout << sieve.getFirstDivisor(6) << std::endl;     // 2
    std::cout << sieve.isPrime(2) << std::endl;             // true
    std::cout << sieve.getFirstDivisor(21) << std::endl;    // 3
}
```