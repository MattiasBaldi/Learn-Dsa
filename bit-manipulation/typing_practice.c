// ================================================
// BIT MANIPULATION - TYPING PRACTICE
// Copy the code below line by line to learn patterns
// ================================================

#include <stdio.h>

// ============================================
// EXAMPLE 1: Check if number is odd
// ============================================
// SOLUTION (study this):
int is_odd(int n) {
    return n & 1;
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int is_odd_practice(int n) {
    return n & 1; 
}

// 1011
// odd-even-odd-odd

// ============================================
// EXAMPLE 2: Multiply by 2 using bit shift
// ============================================
// SOLUTION (study this):
int multiply_by_two(int n) {
    return n << 1;
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int multiply_by_two_practice(int n) {

    // Type here:
    return n << 1; 
}

// ============================================
// EXAMPLE 3: Divide by 4 using bit shift
// ============================================
// SOLUTION (study this):
int divide_by_four(int n) {
    return n >> 2;
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int divide_by_four_practice(int n) {
    // Type here:
    return n >> 2; 
}

// ============================================
// EXAMPLE 4: Check if has bit at position
// ============================================
// SOLUTION (study this):
int has_bit_at_position(int n, int pos) {
    return (n & (1 << pos)) != 0;
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int has_bit_at_position_practice(int n, int pos) {
    // Type here:
    return (n & (1 << pos)) != 0; 
}

// ============================================
// EXAMPLE 5: Set bit at position
// ============================================
// SOLUTION (study this):
int set_bit_at_position(int n, int pos) {
    return n | (1 << pos);
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int set_bit_at_position_practice(int n, int pos) {
    // Type here:
    return n | (1 << pos);
}

// ============================================
// EXAMPLE 6: Remove bit at position
// ============================================
// SOLUTION (study this):
int remove_bit_at_position(int n, int pos) {
    return n & ~(1 << pos);
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int remove_bit_at_position_practice(int n, int pos) {
    // Type here:
    return n & ~(1 << pos); 
}

// ============================================
// EXAMPLE 7: Flip bit at position
// ============================================
// SOLUTION (study this):
int flip_bit_at_position(int n, int pos) {
    return n ^ (1 << pos);
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int flip_bit_at_position_practice(int n, int pos) {

    // Type here:
    return n ^(1 << pos); 
}

// ============================================
// EXAMPLE 8: Get rightmost set bit
// ============================================
// SOLUTION (study this):
int get_rightmost_set_bit(int n) {
    return n & (-n);
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int get_rightmost_set_bit_practice(int n) {
    // Type here:
    return n & (-n); 
}

// ============================================
// EXAMPLE 9: Remove rightmost set bit
// ============================================
// SOLUTION (study this):
int remove_rightmost_set_bit(int n) {
    return n & (n - 1);
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int remove_rightmost_set_bit_practice(int n) {
    // Type here:
    return n & (n - 1); 
}

// ============================================
// EXAMPLE 10: Count total set bits
// ============================================
// SOLUTION (study this):
int count_all_set_bits(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int count_all_set_bits_practice(int n) {
    // Type here:
    int count = 0; 
    while (n) {
        n &= (n-1); 
        count++; 
    }
    return count; 
}

// ============================================
// EXAMPLE 11: XOR two numbers
// ============================================
// SOLUTION (study this):
int xor_numbers(int a, int b) {
    return a ^ b;
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int xor_numbers_practice(int a, int b) {
    // Type here:

}

// ============================================
// EXAMPLE 12: Check if power of 2
// ============================================
// SOLUTION (study this):
int is_power_of_2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

// NOW TYPE THE EXACT SAME CODE BELOW:
int is_power_of_2_practice(int n) {
    // Type here:
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    printf("Typing practice complete! Now test your implementations.\n");
    return 0;
}
