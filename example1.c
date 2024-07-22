#include <stdio.h>

int main() {
    int num1, num2, sum;
    
    // Запрос ввода первого числа
    printf("Введите первое число: ");
    scanf("%d", &num1);
    
    // Запрос ввода второго числа
    printf("Введите второе число: ");
    scanf("%d", &num2);
    
    // Вычисление суммы
    sum = num1 + num2;
    
    // Вывод результата
    printf("Сумма чисел %d и %d равна %d\n", num1, num2, sum);
    
    return 0;
}
