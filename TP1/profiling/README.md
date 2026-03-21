# Time Profiling - Instrucciones

Este apartado describe cómo ejecutar el profiling del programa utilizando `gprof` y `perf`.

## Estructura

- `src/` → código fuente
- `bin/` → ejecutables
- `results/` → resultados de profiling

---

## Compilación con profiling (gprof)

Desde la carpeta profiling:

```bash
cd src
gcc -Wall -pg test_gprof.c test_gprof_new.c -o ../bin/test_gprof