![Isologotipo FCEFyN y UNC](./assets/2_1_Isologotipo%20FCEFyN%20y%20UNC-%20blanco_Sin%20fondo-Con%20bajada.png "UNC y FCEFyN")

# TRABAJO PRÁCTICO N° 2  
## Stackframe - Calculadora de Índice GINI

**Integrantes:**
- García, Lautaro Misael
- Gomez, Dolores
- Renaudo Gaggioli, Valentino

**Abril 2026**


---

# 1. Introducción

El objetivo de este trabajo práctico es implementar un sistema que integre distintos niveles de software, utilizando C y ensamblador, con el fin de comprender el funcionamiento del stack y las convenciones de llamada entre funciones.

Se plantea la resolución en dos etapas:
- Implementación completa en C
- Migración de la lógica a ensamblador

---

# 2. Objetivos

## Objetivo general

Comprender el uso del stackframe y la interacción entre lenguajes de alto y bajo nivel.

## Objetivos específicos

- Implementar procesamiento de datos en C
- Utilizar convenciones de llamada
- Implementar funciones en assembler
- Analizar el stack mediante GDB

---

# 3. Arquitectura del sistema

El sistema se compone de las siguientes capas:

- Python (opcional): obtención de datos desde API
- C: control del flujo del programa
- Assembler: procesamiento de datos

Flujo general:

```text
Python → C → ASM → Resultado
```

# 3.1 Integración Python - C - ASM

Para la integración entre lenguajes se utilizó la biblioteca `ctypes` de Python, que permite cargar librerías dinámicas (`.so`).

Se implementó un wrapper en C que actúa como intermediario entre Python y la rutina en ensamblador.

Firma de la función:

```c
int procesar_wrapper(float x);
```

Desde Python:

```python
lib.procesar_wrapper.argtypes = [ctypes.c_float]
lib.procesar_wrapper.restype = ctypes.c_int
```

---

# 4. Iteración 1 - Implementación en C

## Descripción

- Recepción de datos
- Conversión de float a entero
- Incremento del valor en 1

## Implementación

Se implementó la función:

```c
int procesar(float x) {
    int valor = (int)x; // truncamiento
    return valor + 1;
}
```

Se validó mediante un programa en C que solicita datos por consola.

---

# 5. Iteración 2 - Implementación en Assembler

## Descripción

Se reimplementó la función en ensamblador respetando la convención System V AMD64 ABI.

## Código relevante

```asm
# procesar.s
cvttss2si   %xmm0, %eax
addl        $1   , %eax
ret
```

## Consideraciones

- El argumento float se recibe en el registro `xmm0`
- El valor de retorno se coloca en `eax`

---

# 6. Stackframe y convención de llamadas

# 7. Debug y análisis con GDB

# 8. Sistema de compilación

Se utilizó un Makefile para automatizar:

- compilación en C
- ensamblado
- generación de librería compartida
- ejecución con Python

Comando principal:

```bash
make run-py
```
---

# 9. Conclusión