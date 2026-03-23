# Microbenchmark de CPU en Sistemas Embebidos

Este directorio contiene un conjunto de pruebas diseñadas para analizar el impacto de la **frecuencia de reloj** y la **arquitectura del procesador** en el tiempo de ejecución de programas simples.

El objetivo es evaluar cómo varía el rendimiento al modificar la frecuencia de CPU y comparar distintas arquitecturas ejecutando exactamente la misma carga de trabajo.

---

## Objetivos

- Analizar la relación entre **frecuencia de CPU** y **tiempo de ejecución**
- Comparar rendimiento entre arquitecturas:
  - ESP32-S3
  - RP2350 (Raspberry Pi Pico 2)
- Evaluar diferencias entre:
  - Operaciones con enteros
  - Operaciones en punto flotante
- Identificar desvíos respecto al modelo ideal:

$$Tiempo ∝ 1 / Frecuencia$$

---

## Metodología

Se implementan dos microbenchmarks principales:

1. **Test de enteros**
2. **Test de punto flotante**

Ambos consisten en bucles con gran cantidad de iteraciones que realizan operaciones aritméticas simples.

### Consideraciones clave

Para que la comparación sea válida:

- Se utiliza **el mismo código base** en todas las plataformas
- Se fija la **misma cantidad de iteraciones**
- Se evita la optimización del compilador mediante uso de `volatile`
- Se mide el tiempo con **timers de alta resolución**
- Se evita incluir I/O dentro de los bucles
- Se ejecuta en condiciones controladas (sin tareas concurrentes)

El objetivo es aproximarse a una **igualdad de condiciones**, permitiendo que las diferencias observadas respondan principalmente a:

- Frecuencia de reloj
- Arquitectura del procesador
- Presencia o ausencia de FPU

---

## Experimentos

Para cada plataforma:

1. Ejecutar los tests a distintas frecuencias de CPU
2. Medir tiempo de ejecución (µs)
3. Comparar:
   - Tiempo vs frecuencia
   - Enteros vs floats
   - Diferencias entre arquitecturas

---

## Resultados esperados

- Al aumentar la frecuencia el tiempo debería disminuir aproximadamente de forma inversamente proporcional.
- Operaciones con enteros escalan más linealmente con la frecuencia.
- Operaciones con floats dependen fuertemente de la FPU.
- Diferencias entre arquitecturas pueden generar variaciones incluso a igual frecuencia.

---

## Limitaciones

Este enfoque corresponde a un **microbenchmark**, lo que implica:

- Ventaja: alto control del experimento
- Desventaja: menor representatividad de aplicaciones reales

Factores no modelados completamente:

- Jerarquía de memoria
- Caché
- Pipeline
- Interrupciones del sistema

---

## Referencias conceptuales

El diseño de estas pruebas se inspira en benchmarks clásicos utilizados en la evaluación de procesadores:

- CoreMark (desarrollado por EEMBC)
- Dhrystone (benchmark sintético de enteros)
- Whetstone (benchmark de punto flotante)

---

## Extensión: uso de CoreMark

Como complemento, se puede ejecutar [**Coremark**](https://www.eembc.org/coremark/) en ambas plataformas.

Esto permite:

- Comparar resultados del microbenchmark con un benchmark estandarizado
- Validar tendencias observadas
- Obtener una métrica más representativa del rendimiento general del sistema

---

## Conclusión

Este conjunto de pruebas permite observar cómo:

- La frecuencia impacta directamente en el tiempo de ejecución
- La arquitectura del procesador influye significativamente en el rendimiento
- La presencia de FPU es determinante en operaciones de punto flotante

El enfoque busca aislar variables para lograr una comparación lo más justa posible dentro de las limitaciones de un sistema embebido real.