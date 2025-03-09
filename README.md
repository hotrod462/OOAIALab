# Object Oriented Analysis of Algorithms Lab

This repository contains the source code developed for the Object Oriented Analysis of Algorithms lab. It demonstrates the use of object-oriented programming techniques in C++ to implement and analyze various algorithms and data structures.

## Repository Structure

- **`Lab3_CS23B102/CS23B102_L3.cpp`**: Implements a `Graph` class with operator overloading and STL usage.
  - **Operator Overloading:**
    - `+`: Union of two graphs.
    - `-`: Intersection of edges between two graphs.
    - `!`: Complement of the graph.
  - **Core Graph Operations:**
    - `addEdge()`: Adds an edge.
    - `removeEdge()`: Removes an edge.
    - `printGraph()`: Displays the graph.
    - `isReachable()`: Checks connectivity using BFS.
  - **Overloaded Stream Operators:** `>>` and `<<` for graph input/output.
  - **Compilation:** `g++ Lab3_CS23B102/CS23B102_L3.cpp -o lab3 -std=c++11`
  - **Execution:** `./lab3`
  - **Commands:** `Graph`, `printGraph`, `add_edge`, `remove_edge`, `complement`, `isReachable`, `union`, `intersection`, `end`.

- **`Lab4_CS23B102/Lab4Design.cpp`**: Implements a `QNS` (Quantum Nano Suit) and `Avenger` class, demonstrating operator overloading and object interaction.
  - **`QNS` Class:** Represents a suit with attributes like power level, durability, energy storage, and heat level.
    - **Operator Overloading:**
      - `+`: Combines suits (adds energy storage, power level and durability).
      - `-`: Simulates damage (reduces durability, increases energy storage and heat).
      - `*`: Boosts power (increases power level, energy, and heat).
      - `/`: Reduces heat (decreases heat level, potentially reactivating the suit).
      - `==`: Compares suits based on power level and durability.
      - `<`: Compares suits based on the sum of power level and durability.
      - `->`: Used by the Avenger class.
    - **Methods:** Includes getters, setters, `boostPower()`, `isOverheat()`, and `isDestructed()`.
  - **`Avenger` Class:** Represents an avenger with a name, suit (`QNS`), and attack strength.
     - **Operator Overloading**
        -  `->`: Accesses the suit's members.
     - **Methods:** `attack()`, `upgradeSuit()`, `repair()`, `canAttack()`, `isAlive()`, `printStatus()`, `getName()`, `getSuit()`.
  - **Compilation:** (Assuming a similar setup) `g++ Lab4_CS23B102/Lab4Design.cpp -o lab4 -std=c++11`
  - **Execution:** `./lab4`

- **`Lab6_CS23B102/Lab6.cpp`**: Contains implementations for:
    -   **`FibGenerator` struct**:
        -   Generates Fibonacci numbers using matrix exponentiation.
        -   `matMul()`: Performs matrix multiplication.
        -   `matPower()`: Calculates the power of a matrix.
        -   `fib()`: Returns the i-th Fibonacci number.
        -   `operator()`: Overloads the function call operator to return fib(i).
    - **`PrimeCalculator` class (Incomplete)**:
        - Intended to find and manage prime numbers within a given range.
        - `findPrimes()`: (Not fully implemented) Supposed to find primes within a range.
        - `printPrimes()`: Prints the found primes.
        - `printPrimeSum()`: Calculates the sum of found primes.
    - **`NumberAnalyzer` class**:
        - Analyzes a given number (`x`).
        - `findDivisors()`: Finds all divisors of `x`.
        - `isSquareFree()`: Checks if the number has a square factor.
        - `countDivisors()`: Returns the number of divisors.
        - `sumOfDivisors()`: Calculates the sum of divisors.
    - **Compilation:** `g++ Lab6_CS23B102/Lab6.cpp -o lab6 -std=c++11`
    - **Execution:** `./lab6`

- **`Lab7_CS23B102/Lab7.cpp`**: Focuses on operations related to a 2D board, including sorting, inversion counting, and finding the closest pair of points.
    - **`Comparator` struct**: Defines a custom comparator for sorting.
        - `sortOrder`: Stores the sorting order ("ascending" or "descending").
        - `operator()`:  Compares two long long integers based on `sortOrder`.
    - **`Board` class**: Represents a 2D board.
        - `initBoard()`: Initializes the board with a given size.
        - `createMat()`: Reads input to populate the board.
        - `sortRows()`: Sorts rows based on the provided `Comparator`.
        - `mergeSort()`: Performs merge sort on a vector.
        - `merge()`: Merges two sorted sub-arrays, counting inversions.
        - `countInversions()`: Counts total inversions on the board.
        - `display()`: Prints the board.
    - **`Olympics` class**:
        - `populatePts()`: Populates points.
        - `closestPair()`: Finds the closest pair of points.
        - `dist()`: Calculates the distance between two points.
        - `bruteForce()`: Brute-force method to find the closest pair.
        - `stripClosest()`: Finds the closest pair within a strip.
    - **Commands:** `CREATE_2D`, `SORT_2D`, `INVERSION_2D`, `DISPLAY_2D`, `CLOSEST_2D`, `END`.
    - **Compilation:** `g++ Lab7_CS23B102/Lab7.cpp -o lab7 -std=c++11`
    - **Execution:** `./lab7`

## General Notes

- The code extensively uses object-oriented principles, including classes, structs, operator overloading, and the Standard Template Library (STL).
- Each lab (`Lab3`, `Lab4`, `Lab6`, `Lab7`) has its own specific set of commands and functionalities, as described above.
- Ensure you have a C++11 compatible compiler (like g++) to compile and run the code.

Happy coding!