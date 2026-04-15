# Simulador de Ecosistema — LP2 TP1

## Integrantes
- Alexandre Avalos
- Marcelo Romero

## Descripción
Aplicación de escritorio desarrollada en C++ que simula un ecosistema simple sobre una grilla bidimensional. El ecosistema contiene tres tipos de entidades vivas: plantas (P), herbívoros (H) y carnívoros (C), que interactúan entre sí siguiendo reglas definidas a lo largo de ciclos de simulación.

La arquitectura separa claramente la lógica del dominio (clases `EntidadViva`, `Planta`, `Herbivoro`, `Carnivoro`, `Ecosistema`) de la interfaz, siguiendo principios de Programación Orientada a Objetos: herencia, polimorfismo y encapsulamiento.

## Tecnologías utilizadas
- C++
- Qt Framework

## Objetivo
Aplicar Programación Orientada a Objetos y diseño modular en una simulación visual, separando claramente la lógica del dominio de la interfaz gráfica.

## Reglas del ecosistema
- **Plantas:** se reproducen en celdas vecinas (8 direcciones posibles) vacías cada ciclo. Mueren al superar la edad máxima (20 ciclos).
- **Herbívoros:** se mueven, buscan plantas vecinas para comer (+20 energía), pierden 10 de energía por ciclo. Mueren si la energía llega a 0 o superan los 20 ciclos de edad. Llegan al ecosistema por las esquinas cada 2 ciclos.
- **Carnívoros:** se mueven, buscan herbívoros vecinos para comer (+20 energía), pierden 10 de energía por ciclo. Mueren si la energía llega a 0 o superan los 20 ciclos de edad. Llegan al ecosistema por las esquinas cada 4 ciclos.

## Decisiones de diseño
- Se utilizó una jerarquía mínima de clases basada en `EntidadViva`.
- La simulación se organiza en ciclos.
- El tablero representa visualmente el estado del ecosistema.
- El motor del ecosistema fue desarrollado independientemente de la interfaz para facilitar mantenimiento e integración.

## Estructura del proyecto
```
├── main.cpp → punto de entrada para pruebas e integración.
├── Ecosistema.h / Ecosistema.cpp → motor principal de simulación.
├── EntidadViva.h / EntidadViva.cpp → clase abstracta base para las entidades del ecosistema.
├── Planta.h / Planta.cpp
├── Herbivoro.h / Herbivoro.cpp
├── Carnivoro.h / Carnivoro.cpp
├── generacionTablero.h / generacionTablero.cpp
```
## Jerarquía de clases
- `EntidadViva` (clase abstracta base)
- `Planta`
- `Herbivoro`
- `Carnivoro`
- `Ecosistema`

## Separación entre lógica e interfaz
La clase `Ecosistema` concentra la lógica de simulación.  
La interfaz gráfica Qt se encarga de representar visualmente la grilla, los contadores y los controles de ejecución, manteniendo separada la lógica del dominio de la capa visual.

## Requisitos
- Compilador C++11 o superior (g++)
- Sistema operativo: Windows / Linux / macOS

## Compilación y ejecución
1. Abrir el proyecto Qt en el entorno configurado para la materia.
2. Compilar el proyecto.
3. Ejecutar la aplicación.
4. Utilizar los controles de la interfaz para iniciar, pausar o reiniciar la simulación.
