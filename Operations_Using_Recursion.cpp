#include <iostream>
using namespace std;

// Function to calculate the sum of first n natural numbers using recursion
int sum(int n) {
  if (n == 0) return 0;
  else return sum(n - 1) + n;
}

// Function to calculate factorial of a number using recursion
int fact(int n) {
  if (n == 0) return 1;
  else return fact(n - 1) * n;
}

// Simple recursive power function: n^pow
int power(int n, int pow) {
  if (pow == 0) return 1;
  else return power(n, pow - 1) * n;
}

// Optimized recursive power function using exponentiation by squaring
int power2(int n, int pow) {
  if (pow == 0) return 1;
  if (pow % 2 == 0) {
    int half = power2(n, pow / 2);
    return half * half;
  } else {
    int half = power2(n, (pow - 1) / 2);
    return n * half * half;
  }
}

// Recursive function to approximate exponential e^x using Taylor Series
double expo(int pow, int prec) {
  static double s; // static variable to store the ongoing sum
  if (prec == 0) return s;
  else {
    s = 1 + pow * s / prec;
    return expo(pow, prec - 1);
  }
}

int Fib[10]; // Global array for memoization of Fibonacci values

// Fibonacci function with memoization for efficient calculation
int fibonacci(int n) {
  if (n <= 1) {
    Fib[n] = n;
    return n;
  } else {
    if (Fib[n - 2] == -1) {
      Fib[n - 2] = fibonacci(n - 2);
    }
    if (Fib[n - 1] == -1) {
      Fib[n - 1] = fibonacci(n - 1);
    }
    Fib[n] = Fib[n - 2] + Fib[n - 1];
    return Fib[n];
  }
}

// Recursive function to calculate nCr (combinations)
int nCr(int n, int r) {
  if (n == 0 || n == r) return 1;
  else return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// Recursive function to solve Tower of Hanoi problem
void Tow_of_Hanoi(int disk, int t1, int t2, int t3) {
  if (disk > 0) {
    Tow_of_Hanoi(disk - 1, t1, t3, t2);
    cout << "Moving disk from Tower " << t1 << " To Tower " << t3 << endl;
    Tow_of_Hanoi(disk - 1, t2, t3, t1);
  }
}

// Main function for testing
int main() {
  
  // Uncomment any of the lines below to test each function
  
   cout << "Sum of N natural numbers is " << sum(5) << endl;
   cout << "Factorial of the number is " << fact(5) << endl;
   cout << "Power of the number is " << power2(2, 6) << endl;
   cout << "Power of the exponential is " << expo(0, 10) << endl;
   cout << "Combinations " << nCr(5, 2) << endl;
   Tow_of_Hanoi(3, 1, 2, 3);

  // Initialize Fibonacci array with -1
  for (int i = 0; i < 10; i++) {
    Fib[i] = -1;
  }
  
  cout << "Fibonacci " << fibonacci(7) << endl;

  return 0;
}
