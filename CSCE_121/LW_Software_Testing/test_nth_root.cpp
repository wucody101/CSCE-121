#include <iostream>
#include <cmath>
#include "./nth_root.h"

int main() {
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        nth_root(2, 1);
        
        try{
            nth_root(0,1);
            throw std::domain_error("A");
        }
        catch (...) {
        }

        try{
            nth_root(2,-1);
            throw std::domain_error("B");
        }
        catch (...) {
        }

        try{
            nth_root(-1,0);
            throw std::domain_error("C");
        }
        catch (...) {
        }

        try{
            nth_root(1,2);
            throw std::domain_error("D");
        }
        catch (...) {
        }

        try{
            nth_root(-1,2);
            throw std::domain_error("E");
        }
        catch (...) {
        }

        try{
            nth_root(-1,2);
            throw std::domain_error("F");
        }
        catch (...) {
        }

        try{
            nth_root(-6,1);
            throw std::domain_error("G");
        }
        catch (...) {
        }

        try{
            nth_root(-3,1);
            throw std::domain_error("H");
        }
        catch (...) {
        }

        try{
            nth_root(6,1);
            throw std::domain_error("I");
        }
        catch (...) {
        }

        try{
            nth_root(2,1);
            throw std::domain_error("J");
        }
        catch (...) {
        }

        try{
            nth_root(2,0);
            throw std::domain_error("K");
        }
        catch (...) {
        }

        try{
            nth_root(2,1);
            throw std::domain_error("L");
        }
        catch (...) {
        }

        try{
            nth_root(3,-2);
            throw std::domain_error("M");
        }
        catch (...) {
        }

        try{
            nth_root(2,3);
            throw std::domain_error("N");
        }
        catch (...) {
        }

        try{
            nth_root(2,1.5);
            throw std::domain_error("O");
        }
        catch (...) {
        }
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
