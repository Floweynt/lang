#include <iostream>

extern "C" auto put_int(int str) -> int
{
    std::cout << str;
    return 0;
}

extern "C" auto put_newline() -> int 
{
    std::cout << '\n';
    return 0;
}

extern "C" auto put_prompt() -> int 
{
    std::cout << "enter a number to compute the factorial for: ";
    return 0;
}

extern "C" auto read_int() -> int
{
    int val = -1;
    std::cin >> val;
    return val;
}
