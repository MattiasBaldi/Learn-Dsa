// ================================================
// Topic: Bit Manipulation
// Language: C
// Exercises: 14 (Beginner: 5 | Intermediate: 5 | Advanced: 4)
// ================================================
// Bit manipulation involves performing operations on individual bits
// of binary numbers. Key operators: & (AND), | (OR), ^ (XOR), ~ (NOT),
// << (left shift), >> (right shift). Useful for optimization, flags,
// and low-level operations.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================
// Exercise 1: Check if a Bit is Set (Beginner)
// ============================================
// Problem: Check if the i-th bit (0-indexed from right) of n is set to 1.
// Example: n=5 (binary: 101), i=0 -> true; i=1 -> false; i=2 -> true
// Hint: Use (n & (1 << i)) to isolate the i-th bit

int is_bit_set(int n, int i) {
    // TODO: implement
    return (n & (1 << i)) != 0; 
}

// ============================================
// Exercise 2: Set the i-th Bit (Beginner)
// ============================================
// Problem: Set the i-th bit (0-indexed from right) of n to 1 and return result.
// Example: n=5 (binary: 101), i=1 -> 7 (binary: 111)
// Hint: Use (n | (1 << i)) to set the bit

int set_bit(int n, int i) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 3: Clear the i-th Bit (Beginner)
// ============================================
// Problem: Clear the i-th bit (0-indexed from right) of n to 0 and return result.
// Example: n=5 (binary: 101), i=2 -> 1 (binary: 001)
// Hint: Use (n & ~(1 << i)) to clear the bit

int clear_bit(int n, int i) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 4: Count Set Bits (Beginner)
// ============================================
// Problem: Count the number of 1s in the binary representation of n.
// Example: n=5 (binary: 101) -> 2; n=7 (binary: 111) -> 3
// Hint: Use Brian Kernighan's trick: n & (n-1) clears rightmost 1

int count_set_bits(int n) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 5: Check if Power of Two (Beginner)
// ============================================
// Problem: Return 1 if n is a power of 2, else 0.
// Example: n=8 (binary: 1000) -> 1; n=6 -> 0; n=0 -> 0
// Hint: A power of 2 has only one bit set. (n & (n-1)) == 0

int is_power_of_two(int n) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 6: Toggle the i-th Bit (Intermediate)
// ============================================
// Problem: Toggle (flip) the i-th bit of n and return result.
// Example: n=5 (binary: 101), i=1 -> 7 (binary: 111); i=0 -> 4 (binary: 100)
// Hint: Use XOR: (n ^ (1 << i))

int toggle_bit(int n, int i) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 7: Isolate Rightmost Set Bit (Intermediate)
// ============================================
// Problem: Extract only the rightmost set bit of n.
// Example: n=12 (binary: 1100) -> 4 (binary: 0100)
// Hint: Use (n & (-n)) or (n & ~(n-1))

int isolate_rightmost_bit(int n) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 8: Clear Rightmost Set Bit (Intermediate)
// ============================================
// Problem: Clear the rightmost set bit of n and return result.
// Example: n=12 (binary: 1100) -> 8 (binary: 1000)
// Hint: Use (n & (n-1))

int clear_rightmost_bit(int n) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 9: Hamming Distance (Intermediate)
// ============================================
// Problem: Count the number of bit positions where x and y differ.
// Example: x=1 (binary: 001), y=4 (binary: 100) -> 2
// Hint: XOR x and y, then count set bits

int hamming_distance(int x, int y) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 10: Get Bit at Position (Intermediate)
// ============================================
// Problem: Get the bit value (0 or 1) at position i in n.
// Example: n=5 (binary: 101), i=1 -> 0; i=0 -> 1
// Hint: Shift right by i positions then check LSB

int get_bit_at(int n, int i) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 11: Find Position of MSB (Advanced)
// ============================================
// Problem: Find the position (0-indexed from right) of the most significant bit.
// Example: n=12 (binary: 1100) -> 3; n=8 -> 3; n=1 -> 0
// Hint: Repeatedly right shift until n becomes 0

int find_msb_position(int n) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 12: Swap Even/Odd Bits (Advanced)
// ============================================
// Problem: Swap all even-indexed bits with odd-indexed bits in n.
// Example: n=5 (binary: 0101) -> 10 (binary: 1010)
// Hint: Mask even bits, mask odd bits, shift, and combine

int swap_even_odd_bits(int n) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 13: Rotate Right (Advanced)
// ============================================
// Problem: Rotate bits of n to the right by d positions.
// Example: n=5 (binary: 101), d=1 -> 6 (binary: 110 after 32-bit rotation)
// Hint: Use right shift and left shift combined

unsigned int rotate_right(unsigned int n, int d) {
    // TODO: implement
    return 0;
}

// ============================================
// Exercise 14: Find Single Number (Advanced)
// ============================================
// Problem: Given an array where every element appears twice except one,
// find the single element using XOR (no extra space).
// Example: arr = [4, 2, 4, 3, 2] -> 3
// Hint: XOR has property: a ^ a = 0, a ^ 0 = a

int find_single_number(int arr[], int n) {
    // TODO: implement
    return 0;
}

// ================================================
// TEST CASES
// ================================================

int main() {
    int passed = 0, total = 0;

    // Test Exercise 1: is_bit_set
    printf("\n--- Exercise 1: is_bit_set ---\n");
    total++;
    if (is_bit_set(5, 0) == 1 && is_bit_set(5, 1) == 0 && is_bit_set(5, 2) == 1) {
        printf("PASS: is_bit_set(5, [0,1,2]) = [1,0,1]\n");
        passed++;
    } else {
        printf("FAIL: is_bit_set\n");
    }

    // Test Exercise 2: set_bit
    printf("\n--- Exercise 2: set_bit ---\n");
    total++;
    if (set_bit(5, 1) == 7 && set_bit(0, 0) == 1) {
        printf("PASS: set_bit(5, 1) = 7, set_bit(0, 0) = 1\n");
        passed++;
    } else {
        printf("FAIL: set_bit\n");
    }

    // Test Exercise 3: clear_bit
    printf("\n--- Exercise 3: clear_bit ---\n");
    total++;
    if (clear_bit(5, 2) == 1 && clear_bit(7, 0) == 6) {
        printf("PASS: clear_bit(5, 2) = 1, clear_bit(7, 0) = 6\n");
        passed++;
    } else {
        printf("FAIL: clear_bit\n");
    }

    // Test Exercise 4: count_set_bits
    printf("\n--- Exercise 4: count_set_bits ---\n");
    total++;
    if (count_set_bits(5) == 2 && count_set_bits(7) == 3) {
        printf("PASS: count_set_bits(5) = 2, count_set_bits(7) = 3\n");
        passed++;
    } else {
        printf("FAIL: count_set_bits\n");
    }

    // Test Exercise 5: is_power_of_two
    printf("\n--- Exercise 5: is_power_of_two ---\n");
    total++;
    if (is_power_of_two(8) == 1 && is_power_of_two(6) == 0 && is_power_of_two(0) == 0) {
        printf("PASS: is_power_of_two(8) = 1, is_power_of_two(6) = 0\n");
        passed++;
    } else {
        printf("FAIL: is_power_of_two\n");
    }

    // Test Exercise 6: toggle_bit
    printf("\n--- Exercise 6: toggle_bit ---\n");
    total++;
    if (toggle_bit(5, 1) == 7 && toggle_bit(5, 0) == 4) {
        printf("PASS: toggle_bit(5, 1) = 7, toggle_bit(5, 0) = 4\n");
        passed++;
    } else {
        printf("FAIL: toggle_bit\n");
    }

    // Test Exercise 7: isolate_rightmost_bit
    printf("\n--- Exercise 7: isolate_rightmost_bit ---\n");
    total++;
    if (isolate_rightmost_bit(12) == 4 && isolate_rightmost_bit(8) == 8) {
        printf("PASS: isolate_rightmost_bit(12) = 4, isolate_rightmost_bit(8) = 8\n");
        passed++;
    } else {
        printf("FAIL: isolate_rightmost_bit\n");
    }

    // Test Exercise 8: clear_rightmost_bit
    printf("\n--- Exercise 8: clear_rightmost_bit ---\n");
    total++;
    if (clear_rightmost_bit(12) == 8 && clear_rightmost_bit(7) == 6) {
        printf("PASS: clear_rightmost_bit(12) = 8, clear_rightmost_bit(7) = 6\n");
        passed++;
    } else {
        printf("FAIL: clear_rightmost_bit\n");
    }

    // Test Exercise 9: hamming_distance
    printf("\n--- Exercise 9: hamming_distance ---\n");
    total++;
    if (hamming_distance(1, 4) == 2 && hamming_distance(3, 1) == 1) {
        printf("PASS: hamming_distance(1, 4) = 2, hamming_distance(3, 1) = 1\n");
        passed++;
    } else {
        printf("FAIL: hamming_distance\n");
    }

    // Test Exercise 10: get_bit_at
    printf("\n--- Exercise 10: get_bit_at ---\n");
    total++;
    if (get_bit_at(5, 0) == 1 && get_bit_at(5, 1) == 0 && get_bit_at(5, 2) == 1) {
        printf("PASS: get_bit_at(5, [0,1,2]) = [1,0,1]\n");
        passed++;
    } else {
        printf("FAIL: get_bit_at\n");
    }

    // Test Exercise 11: find_msb_position
    printf("\n--- Exercise 11: find_msb_position ---\n");
    total++;
    if (find_msb_position(12) == 3 && find_msb_position(1) == 0 && find_msb_position(8) == 3) {
        printf("PASS: find_msb_position(12) = 3, find_msb_position(1) = 0\n");
        passed++;
    } else {
        printf("FAIL: find_msb_position\n");
    }

    // Test Exercise 13: rotate_right
    printf("\n--- Exercise 13: rotate_right ---\n");
    total++;
    unsigned int expected = ((unsigned int)5 >> 1) | ((unsigned int)5 << 31);
    if (rotate_right(5, 1) == expected) {
        printf("PASS: rotate_right(5, 1) works correctly\n");
        passed++;
    } else {
        printf("FAIL: rotate_right\n");
    }

    // Test Exercise 14: find_single_number
    printf("\n--- Exercise 14: find_single_number ---\n");
    total++;
    int arr[] = {4, 2, 4, 3, 2};
    if (find_single_number(arr, 5) == 3) {
        printf("PASS: find_single_number([4, 2, 4, 3, 2]) = 3\n");
        passed++;
    } else {
        printf("FAIL: find_single_number\n");
    }

    printf("\n================================================\n");
    printf("Results: %d/%d tests passed\n", passed, total);
    printf("================================================\n");

    return 0;
}
