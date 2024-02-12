# FindClusterExtreme

FindClusterExtreme is an assignment I completed my junior year of studying Computer Science. FindClusterExtreme is
a function that takes an array of floats and the integer size of the array and retrieves the pair of numbers with the
largest sorted-order distance betwen them. This function has O(n) runtime.

## Installation

This program can be run in any environment that can compile C code. 

You can use the below command to compile the code in a PowerShell or Linux window with GCC.
```gcc main.c lab3.c -Wall -Werror
```

## Usage

Included with the program files are text files labeled "sequence#.txt" for numbers 1-6. Each text file contains incrementing numbers with a pair of numbers that are furthest apart.
Using "write.c", you can create your own sequence of incrementing numbers by changing the variable "n".

You can also change the name of the file that is read in "main.c" to test your own sequence or a different sequence with FindClusterExtreme.

Running the program will read the numbers in a text file into an array, shuffle the array, and then pass the array to FindClusterExtreme, bubbleSort, and mergeSort.
The runtimes for each function are recorded and displayed to the user for comparison.

Note: Running larger datasets may cause a noticable delay in displaying output. Bubblesort has an O(n^2) and is run after FindClusterExtreme for comparison, this delay is expected.


