#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Счастливые билеты
void lucky_tickets(){
    int array[27] = {0};
    for (int i = 0; i < 10; i++){
        for (int k = 0; k < 10; k++){
            for (int j = 0; j < 10; j++){
                array[i + k + j] += 1;
            }
        }
    }
    int result = 0;
    for (int i = 0; i < 27; i++){
        result += array[i] * array[i];
    }
    printf("----------\nСчастливые билеты: %d\n----------", result);
}

// Две переменные
void swap(int* left, int* right){
        *left ^= *right;
        *right  ^= *left;
        *left ^= *right;
}

void two_variables(){
    int a = 1, b = 3;
    swap(&a, &b);
    printf("\nДве переменные:\n Входные данные: a = 1, b = 3\n Выходные данные: a = %d, b = %d\n----------", a, b);
}

// Нулевые элементы
void null_elements(){
    int array[31] = {0};
    int counter = 0;
    bool presence_of_zero_elements = true;
    while (presence_of_zero_elements){
        if (array[counter] == 0){
            counter += 1;
        }else{
            presence_of_zero_elements = false;
        }
    }
    printf("\nНулевые элементы:\n Размер массива: 31\n Вывод функции: %d\n----------", counter);
}

// Неполное частное

void incomplete_quotient(int a, int b){
    int peremenaya_a = a;
    if (b != 0){
        int counter = 0;
        if ((a >= 0 && b > 0) || (a <= 0 && b < 0)){
            while (a >= b){
                counter += 1;
                a -= b;
            }
            printf("\nНеполное частное:\n a = %d, b = %d\n a / b = %d", peremenaya_a, b, counter);
        }else{
            a = fabs(a);
            b = fabs(b);
            while (a >= b){
                counter += 1;
                a -= b;
            }
            printf("\nНеполное частное:\n a = %d, b = %d\n a / b = -%d", peremenaya_a, b, counter);
        }
    }else{
        printf("\nНеполное частное:\n Error: b не может ровняться нулю\n");
    }
}

// Баланс скобок
void balance_of_brackets(const char stroke[]){
    int counter = 0;
    int index_counter = 0;
    char zero_element = stroke[0]; 
    while (zero_element != '\0'){
        if (stroke[index_counter] == '('){
            counter += 1;
        }else if (stroke[index_counter] == ')'){
            counter -= 1;
        }
        zero_element = stroke[index_counter];
        index_counter += 1;
    }
    if (counter == 0){
            printf("----------\nБаланс скобок:\n Успешно\n----------");
    }else{
        printf("----------\nБаланс скобок:\n Error: Баланс скобок нарушен\n----------");
    }
}