#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

// Счастливые билеты
void luckyTickets() {
    int array[28] = { 0 };
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) {
            for (int j = 0; j < 10; j++) {
                ++array[i + k + j];
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 28; i++) {
        result += array[i] * array[i];
    }
    printf("----------\nСчастливые билеты: %d\n----------", result);
}

// Две переменные
void swap(int* left, int* right) {
    if (left != right) {
        *left ^= *right;
        *right  ^= *left;
        *left ^= *right;
    } 
}

void twoVariables() {
    int a = 1, b = 3;
    swap(&a, &b);
    printf("\nДве переменные:\n Входные данные: a = 1, b = 3\n Выходные данные: a = %d, b = %d\n----------", a, b);
}

// Нулевые элементы
void nullElements(int array[]) {
    int counter = 0;
    while (array[counter] == 0) {
        ++counter;
    }
    printf("\nНулевые элементы:\n Размер массива: %d\n----------", counter);
}

// Неполное частное
int incompleteQuotient(const int a,const int b, int *errorCode) {
    if (b == 0){
        *errorCode = 1;
        return 0;
    }
    *errorCode = 0;
    int dividend = fabs(a), divider = fabs(b);
    int counter = 0;
    while (dividend >= divider) {
        dividend -= divider;
        ++counter;
    }
    if ((a >= 0 && b > 0) || (a < 0 && b < 0)) {
        return counter;
    }else if ((dividend == 0) || (b < 0)) {
        return -counter;
    }else {
        return -counter - 1;
    }
}

// Баланс скобок
void balanceOfBrackets(const char string[]) {
    int counter = 0;
    int indexCounter = 0;
    while (string[indexCounter] != '\0') {
        if (string[indexCounter] == '(') {
            counter += 1;
        }else if (string[indexCounter] == ')') {
            counter -= 1;
        }
        if (counter < 0) {
            break;
        }
        indexCounter += 1;
    }
    if (counter == 0) {
        printf("\nБаланс скобок:\n Успешно\n----------");
    }else {
        printf("\nБаланс скобок:\n Error: Баланс скобок нарушен\n----------");
    }
}

// Простые числа
void primeNumbers(int theGivenNumber) {
    printf("\nПростые числа:\n");
    for (int number = 2; number <= theGivenNumber; ++number) {
        int counter = 0;
        for (int divider = 1; divider < trunc(sqrt(number) + 1); ++divider) {
            if (number % divider == 0) {
                counter += 2;
            }
        }
        if (counter == 2) {
            printf(" %d", number);
        }
    }
    printf("\n----------");
}

// Подстрока
int countString(char *string, char *substring) {
    int stringLen = strlen(string);
    int substringLen = strlen(substring);
    int counter = 0;
    for (int i = 0; i < stringLen - substringLen + 1; ++i) {
        char sliseString[substringLen];
        for (int j = 0; j < substringLen; ++j) {
            sliseString[j] = string[i + j];
        }
        if (strcmp(sliseString, substring) == '\0') {
            ++counter;
        }
    }
    return counter;
}

// Массив
int lenghArray(int array[]) {
    int counter = 0;
    while (array[counter] != '\0' ) {
        ++counter;
    }
    return counter;
    
}

void flippingAnArray(int array[], int arrayLen) {
    for (int i = 0; i < arrayLen / 2; ++i) {
        swap(&array[i], &array[arrayLen - 1 - i]);
    }
}

void changingArraySegments(int array[], int m) {
    int arrayLen = lenghArray(array);
    for (int i = 0; i < m / 2; ++i) {
        swap(&array[i], &array[m - 1 - i]);
    }
    for (int i = 0; i < (arrayLen - m) / 2 ; ++i){
        swap(&array[m + i], &array[arrayLen - 1 - i]);
    }
    flippingAnArray(array, arrayLen);
    for (int i = 0; i < arrayLen; ++i){
        printf("%d ", array[i]);
    }
}



int main(void) {
    luckyTickets();
    twoVariables();

    int arrayForNullElements[31] = { 0 };
    nullElements(arrayForNullElements);

    int errorCode = 0;
    int result = incompleteQuotient(-13, 5, &errorCode);
    if (errorCode != 0){
        printf("\nНеполное частное:\n Error: Нельзя делить на ноль\n---------");
    }else{
        printf("\nНеполное частное:\n Ответ: %d\n----------", result); 
    }

    balanceOfBrackets("())()");
    primeNumbers(100);
    printf("\nПодстрока:\n Количество подстрок: %d\n----------", countString("qwqwqwqw", "qw"));

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    int arrayLen = lenghArray(array);
    printf("\nМассив:\n Вывод: ");
    changingArraySegments(array, 5);
    printf("\n----------\n");
}
