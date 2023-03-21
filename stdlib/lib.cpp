#include <stdio.h>

extern "C" auto success(int i) -> int
{
    printf("success: %d\n", i);
    return 0;
}

extern "C" auto error(int i) -> int
{
    printf("error: %d\n", i);
    return 0;
}

extern "C" auto put_int(int str) -> int
{
    // std::cout << str;
    printf("%d", str);
    return 0;
}

extern "C" auto put_newline() -> int
{
    //    std::cout << '\n';
    printf("\n");
    return 0;
}
extern "C" auto put_prompt() -> int
{
    //    std::cout << "enter a number to compute the factorial for: ";
    printf("enter a number to compute the factorial for:");
    return 0;
}

extern "C" auto read_int() -> int
{
    //    int val = -1;
    //    std::cin >> val;
    int val = -1;
    scanf("%d", &val);
    return val;
}

extern "C" auto builtin_popcount(unsigned val) -> unsigned { return __builtin_popcount(val); }
