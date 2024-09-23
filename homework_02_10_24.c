#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right  ^= *left;
        *left ^= *right;
    } 
}

void printArray(int array[], int lengh) {
    for (int i = 0; i < lengh; ++i) {
        printf("\n%d", array[i]);
    }
}

// Для себя
int byMatrixMultiplication(int n) {
    int matrix[] = {
        1, 1,
        1, 0
    };
    int matrixForMultiplication[] = {
        1, 1,
        1, 0
    };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= 2; j += 2) {
            int a = 0, b = 0;
            a = matrix[j] * matrixForMultiplication[0] + matrix[j + 1] * matrixForMultiplication[2];
            b = matrix[j] * matrixForMultiplication[1] + matrix[j + 1] * matrixForMultiplication[3];
            matrix[j] = a;
            matrix[j + 1] = b;
        }
    }
    
    printf("\n%d %d\n%d %d", matrix[0], matrix[1], matrix[2], matrix[3]);
}

// Полукусорт
void fillArray(int array[], int lengh) {
    for (int i = 0; i < lengh; ++i) {
        array[i] = rand();
    }
}
void halfBunch() {
    int array[100] = { 0 };
    fillArray(array, 100);

}


// Пузырёк и подсчёт
float bubbleSort(int array[], int lengh) {
    clock_t timeCounter = clock();
    for (int i = 0; i + 1 < lengh; ++i) {
        for (int j = 0; j + 1 < lengh; ++j) {
            if (array[j + 1] < array[j]) {
                swap(&array[j + 1], &array[j]);
            }
        }
    }
    timeCounter = clock() - timeCounter;
    return (float)timeCounter / CLOCKS_PER_SEC;
}
float countingSort(int array[], int lengh) {
    clock_t timeCounter = clock();
    int min = array[0], max = array[0], j = 0;
    for (int i = 0; i < lengh; ++i) {
        if (min > array[i]) {
            min = array[i];
        }
        if (max < array[i]) {
            max = array[i];
        }
    }
    int * auxiliaryArray = (int *) calloc(max, sizeof(int));
    for (int i = 0; i < lengh; ++i) {
        ++auxiliaryArray[array[i]];
    }
    for (int i = min; i <= max; ++i) {
        while (auxiliaryArray[i] > 0) {
            array[j] = i;
            ++j;
            auxiliaryArray[i]--;
        }
    }
    timeCounter = clock() - timeCounter;
    free(auxiliaryArray);
    return (float)timeCounter / CLOCKS_PER_SEC;
}
void bubbleAndCouting() {
    int lengh = 100000;
    int array[100000] = { 0 };
    fillArray(array, 100000);
    printf("\nBubble And Couting\n Bubble sort time: %fsec.\n Counting sort time: %fsec.\n----------",
    bubbleSort(array, lengh), countingSort(array, lengh));
}

// Возведение в степень
float ordinaryExponentiation(int number, int degree) {
    float result = 1;
    for (int i = 0; i < abs(degree); ++i) {
        result *= number;
    }
    if (degree >= 0){
        return result;
    } else {
        return (1 / result);
    }
}
float fastExponentiation(int number, int degree) {
    float result = 1;
    int degreeAbs = abs(degree);
    while(degreeAbs) {
        if (degreeAbs % 2 == 0) {
            degreeAbs /= 2;
            number *= number;
        }
        else {
            degreeAbs--;
            result *= number;
        }
    }
    if (degree >= 0) {
        return result;
    } else {
        return 1 / result;
    }
    
}

// Числа Фибоначчи
int recursivelyFibonacci(int number) {
    if (number == 0) {
        return 0;
    } else if (number <= 2) {
        return 1;
    }
    return (recursivelyFibonacci(number - 1) + recursivelyFibonacci(number - 2));
}
int iterativelyFibonacci(int number) {
    if (number == 0) {
        return 0;
    } else if (number <= 2) {
        return 1;
    }
    int fib1 = 1, fib2 = 1, c = 0;
    for (int i = 3; i <= number; ++i) {
        c = fib1 + fib2;
        fib1 = fib2;
        fib2 = c;
    }
    return fib2;
}
void fibonacci() {
    int number = 45;
    clock_t timeCounter1 = clock();
    recursivelyFibonacci(number);
    timeCounter1 = clock() - timeCounter1;
    clock_t timeCounter2 = clock();
    iterativelyFibonacci(number);
    timeCounter2 = clock() - timeCounter2;
    printf("\nFibonacci\n Recursively, number 45: %fsec.\n Iteratively, number 45: %fsec.", 
    (float)timeCounter1 / CLOCKS_PER_SEC, 
    (float)timeCounter2 / CLOCKS_PER_SEC);
}

// Тесты
bool arrayComparison(int array1[], int array2[], int lenghs) {
    bool result = true;
    for (int i = 0; i < lenghs; ++i) {
        if (array1[i] != array2[i]) {
            result = false;
        }
    }
    return result;
}

bool testBubbleSort(){
    int array[] = { 1, 4, 5, 3, 2 }, sortedArray[] = { 1, 2, 3, 4, 5 };
    bubbleSort(array, 5);
    return arrayComparison(array, sortedArray, 5);
}
bool testCoutingSort() {
    int array[] = { 1, 4, 5, 3, 2 }, sortedArray[] = { 1, 2, 3, 4, 5 };
    countingSort(array, 5);
    return arrayComparison(array, sortedArray, 5);
}
bool testOrdinaryExponentiation() {
    return ((ordinaryExponentiation(10, 2) == 100) && (ordinaryExponentiation(10, 0) == 1) 
    && (ordinaryExponentiation(10, -1) == 0,1) && (ordinaryExponentiation(10, 1) == 10));
}
bool testFastExponentiation() {
    return ((fastExponentiation(10, 2) == 100) && (fastExponentiation(10, 0) == 1) 
    && (fastExponentiation(10, -1) == 0,1) && (fastExponentiation(10, 1) == 10));
}
bool testRecursivelyFibonacci() {
    int array[10] = { 0 }, arrayFibonacciNumbers[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
    for (int i = 0; i < 10; ++i) {
        array[i] = recursivelyFibonacci(i);
    }
    return arrayComparison(array, arrayFibonacciNumbers, 10);
}
bool testIterativelyFibonacci() {
    int array[10] = { 0 }, arrayFibonacciNumbers[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    for (int i = 0; i < 10; ++i) {
        array[i] = iterativelyFibonacci(i);
    }
    return arrayComparison(array, arrayFibonacciNumbers, 10);
}
bool testProgram() {
    return testBubbleSort() && testCoutingSort() && testOrdinaryExponentiation() && testFastExponentiation() 
    && testRecursivelyFibonacci() && testIterativelyFibonacci();
}

int main(void) {
    if (!testProgram()) {
        printf("\nTest failed");
        return 0;
    }
    bubbleAndCouting();
    printf("\nRaising to a power\n Ordinary: %f\n Fast: %f\n----------", 
    ordinaryExponentiation(10, 1), 
    fastExponentiation(10, 1));  
    fibonacci();
}