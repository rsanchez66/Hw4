#include <iostream>

void multiply(int x, int result[], int& result_size) {
    int carry = 0;
    for (int i = 0; i < result_size; ++i) {
        int product = result[i] * x + carry;
        result[i] = product % 10;
        carry = product / 10;
    }

    while (carry) {
        result[result_size] = carry % 10;
        carry /= 10;
        ++result_size;
    }
}

void factorial(int n) {
    int* result = new int[1000]; // array to store result
    result[0] = 1;
    int result_size = 1;

    for (int x = 2; x <= n; ++x)
        multiply(x, result, result_size);

    std::cout << "Factorial of " << n << " is: ";
    for (int i = result_size - 1; i >= 0; --i)
        std::cout << result[i];
    std::cout << std::endl;

    delete[] result; // Freeing allocated memory
}

int main() {
    int num;
    std::cout << "Enter a number to calculate its factorial: ";
    std::cin >> num;
    factorial(num);
    return 0;
}