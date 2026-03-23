#include <stdint.h>

#define ITERATIONS 200000000

volatile uint32_t int_result = 0;
volatile float float_result = 0.0f;

void test_integers() {
    uint32_t acc = 0;
    for (uint32_t i = 0; i < ITERATIONS; i++) {
        acc += i;
        acc ^= (acc << 1);
    }
    int_result = acc;
}

void test_floats() {
    float acc = 0.0f;
    for (uint32_t i = 0; i < ITERATIONS; i++) {
        acc += (float)i * 0.000001f;
        acc *= 1.000001f;
    }
    float_result = acc;
}