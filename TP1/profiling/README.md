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
```

Luego:
```bash
cd ../bin
./test_gprof
```

Y finalmente:
```bash
gprof test_gprof gmon.out > ../results/analysis<Apellido>.txt
```

Esto ya genera el `.txt` con los resultados y lo ubica en el fichero correspondiente

## Generación de gráfico de profiling

### Instalación de gprof2dot

En Ubuntu, no está disponible por apt. Usar:

```bash
sudo apt install pipx
pipx ensurepath
pipx install gprof2dot
```

### Instalación de graphviz

```bash
sudo apt install graphviz
```

### Generar gráfico

En `profiling/bin` : 

```bash
gprof test_gprof gmon.out | gprof2dot -o output.dot
dot -Tpng output.dot -o profile.png
```

### Resultado

- `profile.png` → gráfico final
- `output.dot` → archivo intermedio

### Interpretación del gráfico

- Cada nodo representa una función
- El tamaño indica el tiempo de ejecución
- Las flechas representan llamadas entre funciones

Las funciones más grandes son los principales cuellos de botella.

## Recomendaciones

### Organización:
- Mover imagenes a `profiling/images`
- Resultados del analisis a `profiling/results`

### Subir:
- `analysis<Apellido>.txt`

### Ignorar (`.gitignore`):

- `output.dot` 
- `gmon.out` 

### Si algo falla:

- Verificar version del compilador: `gcc --version`
- `gprof2dot: no se encontró la orden` : no se corrió `ensurepath`
- `dot: command not found` : falta graphviz
- Gráfico vacío: no se ejecutó el binario antes
- Revisar siempre que estés corriendo los comandos en el fichero correcto