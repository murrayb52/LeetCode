#include <math.h>
#include <stdio.h>

int reverse(int x){
    // calculate number of digits (d)
    int digits = 1;
    int divided = x;
    while (divided > 10) {
        digits++;
        divided /= 10;
    }

    // modulus of 10^n multiplied by 10^(d-n)
    int reversedNum = 0;
    int factor = 10;
    int multiplier = pow(10, digits);
    for (int digit = 0 ; digit <= digits; digit++ ) {
        // transform digit
        int mod = x % factor;
        reversedNum += (mod * multiplier);
        
        // move to next digit
        multiplier /= 10;
        factor *= 10;
    }

    return digits;
}

int main(void) {
    printf("Input: 123    -> %d\n", reverse(123));
    printf("Input: -123   -> %d\n", reverse(-123));
    printf("Input: 120    -> %d\n", reverse(120));
    return 0;
}