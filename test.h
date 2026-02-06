#include <iostream>
#ifndef TEST_H
#define TEST_H
#define RED_ON "\033[1;31m"
#define GREEN_ON "\033[1;32m"
#define COLOR_OFF "\033[1;0m"

void testPass(const std::string& msg)
{
    std::cout << GREEN_ON << "PASS: " << msg;
    std::cout << COLOR_OFF;
}
void testFail(const std::string& msg)
{
    std::cout << RED_ON << "FAIL: " << msg;
    std::cout << COLOR_OFF;
}
void testTrue(bool p, const std::string& msg)
{
    if(p) testPass(msg);
    else testFail(msg);
    std::cout << COLOR_OFF << std::endl;
}
void testFalse(bool p, const std::string& msg) {testTrue(!p, msg);}

#endif



