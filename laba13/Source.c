#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

void task1();
void task2();
void task3();

int main()
{
    setlocale(LC_ALL, "RUS");
    task1();
    task2();
    task3();
}

void task1()
{
    char name[50];
    char greeting[100];

    puts("Пожалуйста, введите ваше имя: ");
    scanf("%49s", name);

    while (getchar() != '\n');

    for (int i = 0; name[i] != '\0'; i++)
    {
        name[i] = toupper(name[i]);
    }

    strcpy(greeting, "Привет, ");
    strcat(greeting, name);
    strcat(greeting, "!");

    while (strlen(greeting) < 40)
    {
        strcat(greeting, "!");
    }

    puts(greeting);
    printf("\n");
}

void task2()
{
    char text[200];
    printf("Введите строку для обработки (Задание 2, п.4):\n");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = 0;

    char result_text[400] = "";
    int len = strlen(text);

    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]) && (i + 1 == len || !isalpha(text[i + 1])))
        {
            strcat(result_text, "_");
        }

        char temp[2] = { text[i], '\0' };
        strcat(result_text, temp);
    }

    printf("Результат: %s\n\n", result_text);
}

void task3()
{
    char sentence[256];
    int sum_digits = 0;

    printf("\n=== Задание 3 (Вариант 7) ===\n");
    printf("Введите предложение: ");

    fgets(sentence, sizeof(sentence), stdin);

    for (int i = 0; sentence[i] != '\0'; i++) 
    {
        if (isdigit((unsigned char)sentence[i])) 
        {
            sum_digits += sentence[i] - '0';
        }
    }

    printf("Сумма всех цифр в предложении: %d\n", sum_digits);
}