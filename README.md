# parking-control-system-c
An intelligent parking system built using foundational C concepts.

This project was developed with the purpose of demonstrating the foundational concepts of structured programming, memory safety, and the logic behind a program. It consists of a lightweight console application designed to automate the management, real-time tracking, and billing of a 12-slot parking lot (a 4 x 3 grid matrix).

# Features:
- Input Validation: Implemented using 'do-while' control loops to prevent out-of-range matrix coordinates and invalid hours, making it completely error-proof.
- Parallel Matrices: Utilizes synchronized matrices to independently track both the slot occupancy status (`0` for vacant, `1` for occupied) and the precise check-in times in decimal format.
- Automatic Billing: Simulates real-time billing by calculating the exact duration of the stay and automatically accumulating earnings into `caja_total` using **pointers and pass-by-reference** (`float *dinero_total`). 
- Dynamic Map: Generates a visual grid of the matrix that updates in real time to show occupied `[X]` and available `[D]` slots at any given moment.

# Key Concepts
- Buffer or Memory Clearing: Clears the system memory using (`fflush`), ensuring visual order within the console interface.
- Residual Memory Cleansing: Resets slot data back to `0.0` upon checkout to ensure no residual data leakage for future vehicles.
- Multidimensional Arrays or Matrices: Used to simulate a physical hardware layout, representing the actual parking slots.
- Pointers and Memory Reference: Implemented to modify variables in the (`main`) function from the scope of secondary functions.

# Console Visual Preview

```
-----BIENVENIDO AL ESTACIONAMIENTO-----
El limite del estacionamiento es: 12
Los puestos disponibles son: 12

------MENÚ-----
1. Disponibilidad de puestos
2. Mapa del estacionamiento
3. Entrada
4. Salida y Tarifa
5. Reporte de Caja
6. Salir
--------------_
Elige una opción del (1-6)
