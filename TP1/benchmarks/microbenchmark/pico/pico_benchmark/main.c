#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include <stdio.h>

#include "benchmark.h"

int main() {
    stdio_init_all();

    sleep_ms(5000);
    set_sys_clock_khz(250000, true); // 250 MHz
    printf("Freq: %lu MHz\n", clock_get_hz(clk_sys) / 1000000);

    absolute_time_t start, end;

    start = get_absolute_time();
    test_integers();
    end = get_absolute_time();
    printf("Int time: %lld us\n", absolute_time_diff_us(start, end));

    start = get_absolute_time();
    test_floats();
    end = get_absolute_time();
    printf("Float time: %lld us\n", absolute_time_diff_us(start, end));

    while (1);
}