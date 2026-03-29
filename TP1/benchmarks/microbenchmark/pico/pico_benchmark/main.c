#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"
#include <stdio.h>

int main() {
    stdio_init_all();
    sleep_ms(2000);

    set_sys_clock_khz(80000, true);

    printf("Prueba de tiempo\n");
    printf("----------------\n");

    absolute_time_t inicio, fin;

    // ===== PRUEBA CON ENTEROS =====
    volatile int sumaEntera = 0;

    inicio = get_absolute_time();

    for (long i = 0; i < 100000000; i++) {
        sumaEntera = sumaEntera + 1;
    }

    fin = get_absolute_time();

    int64_t tiempo_int_us = absolute_time_diff_us(inicio, fin);

    printf("Tiempo con enteros: %.3f s\n", tiempo_int_us / 1e6);

    // ===== PRUEBA CON FLOATS =====
    volatile float sumaFloat = 0;

    inicio = get_absolute_time();

    for (long i = 0; i < 100000000; i++) {
        sumaFloat = sumaFloat + 1.0f;
    }

    fin = get_absolute_time();

    int64_t tiempo_float_us = absolute_time_diff_us(inicio, fin);

    printf("Tiempo con floats: %.3f s\n", tiempo_float_us / 1e6);

    while (1);
}
