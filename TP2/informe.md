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

Python → C → ASM → Resultado

---

# 4. Iteración 1 - Implementación en C
En esta primera iteración se desarrolló la lógica completa en lenguaje C con el objetivo de validar el funcionamiento del sistema antes de migrar a ensamblador.

La función principal procesar recibe un valor de tipo float, realiza un truncamiento hacia cero para convertirlo a entero y luego incrementa el resultado en una unidad.

Esta implementación permite verificar el comportamiento esperado de manera sencilla, aprovechando la abstracción del lenguaje C.


## Descripción

- Recepción de datos
- Conversión de float a entero
- Incremento del valor en 1

## Código relevante

#include "procesar.h"

int procesar(float x) {
    int valor = (int)x;  // truncamiento hacia cero
    return valor + 1;
}

#ifndef PROCESAR_H
#define PROCESAR_H

int procesar(float x);

#endif

#include <stdio.h>

int procesar(float x);

int main() {
    float valores[] = {3.7, 2.1, -1.9, 0.0};

    for (int i = 0; i < 4; i++) {
        int r = procesar(valores[i]);
        printf("x = %.2f → resultado = %d\n", valores[i], r);
    }

    return 0;
}

| Entrada | Truncamiento | Resultado |
|:-------:|:------------:|:---------:|
| 3.7     | 3            | 4         |
| 2.1     | 2            | 3         |
| -1.9    | -1           | 0         |
| 0.0     | 0            | 1         |

# 5. Iteración 2 - Implementación en Assembler

En esta iteración se reemplazó la implementación en C por una versión equivalente en ensamblador para arquitectura x86-64, manteniendo la misma interfaz de la función.

El objetivo fue comprender cómo se implementan operaciones simples a bajo nivel y cómo se respetan las convenciones de llamada del sistema.

Se utilizó la convención System V AMD64 ABI, donde:

El argumento float se recibe en el registro %xmm0
El valor de retorno (int) se devuelve en %eax

## Código relevante
.section .text
.globl procesar
.type procesar, @function

procesar:
    cvttss2si %xmm0, %eax   # float → int (truncamiento)
    addl $1, %eax           # suma 1
    ret

.size procesar, .-procesar

cvttss2si: convierte un float a entero truncando hacia cero
addl: suma un valor inmediato al registro
ret: retorna al programa llamador


# 6. Stackframe y convención de llamadas

# 7. Debug y análisis con GDB

# 8. Profiling

# 9. Conclusión
