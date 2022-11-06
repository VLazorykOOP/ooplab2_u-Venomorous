#include <iostream>

int main()
{
    int a, b, c, d;
    int res;

    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    std::cout << "Enter d: ";
    std::cin >> d;

    res = ((b << 5) + b) + ((((d << 4) - d) + ((a << 4) - (a << 2))) >> 9) - ((c << 6) + c) + ((d << 4) - (d << 1)); // 33*b+((d*15+12*a)/512)-65*c+d*14

    std::cout << "Result: " << res << std::endl;

    return 0;
}