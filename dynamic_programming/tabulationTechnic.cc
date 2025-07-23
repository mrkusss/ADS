#include <iostream>
#include <vector>

std::vector<int> Fibonacci(int i) 
{
    std::vector<int> fibo;
    int fib1 = 0,fib2 = 1;

    for (int x = 0; x<i; ++x) {
        int next = fib1+fib2;
        fib1 = fib2;
        fibo.push_back(fib1);
        fib2 = next;
    }

    return fibo; 
}

void print(const std::vector<int>& v) 
{
    for (int i = 0; i<v.size(); ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

int main() 
{
    for (int i = 0; i < 5; ++i) {
        std::cout << i << " -> ";
        print(Fibonacci(i));
    }

}