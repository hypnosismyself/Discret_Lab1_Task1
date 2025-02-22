﻿#include <iostream>
#include <vector>

/*
 * Целевое выражение - вариант 7
 * :params - значение логической переменной
    bool a
    bool b
    bool c
    bool d
    bool e

    :return int
 */
bool taskExpression(bool a, bool b, bool c, bool d, bool e) 
{
    return (!a || b) && c && (d || !e);
}

// Генератор таблицы истинности
void generateTruthTable() 
{
    std::cout << "\t\tТаблица истинности" << std::endl;
    std::cout << "a\tb\tc\td\te\tF\n";
    std::cout << "-----------------------------------------\n";

    // генерация таблицы через побитовое И
    // если хотя бы в одном разряде 1, то значение равно 1
    // иначе 0
    for (int i = 0; i < 32; ++i)
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func = taskExpression(a, b, c, d, e);

        std::cout << a << "\t"
                  << b << "\t"
                  << c << "\t"
                  << d << "\t"
                  << e << "\t"
                  << func << std::endl;
    }
}

// Генератор Совершенной Дизъюнктивной Нормальной Формы (СДНФ)
void generatePureDisjunctiveForm() 
{
    std::vector<std::string> result;

    for (int i = 0; i < 32; ++i)
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func = taskExpression(a, b, c, d, e);

        // формирование конъюнкций
        if (taskExpression(a, b, c, d, e)) {
            std::string term = "";

            term += a ? "a" : "!a";
            term += b ? "b" : "!b";
            term += c ? "c" : "!c";
            term += d ? "d" : "!d";
            term += e ? "e" : "!e";

            result.push_back("(" + term + ")");
        }
    }

    std::cout << "\nСовершенная дизъюнктивная нормальная форма (СДНФ):\n";

    for (auto term : result)
    {
        std::cout << term << " || ";
    }

    std::cout << "false\n";
}

// Генератор Совершенной Конъюнктивной Нормальной Формы (СКНФ)
void generatePureConjunctiveForm() 
{
    // массив дизъюнкций
    std::vector<std::string> result;

    for (int i = 0; i < 32; ++i)
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func = taskExpression(a, b, c, d, e);

        // формирование дизъюнкции для каждой строки таблицы истинности
        if (!taskExpression(a, b, c, d, e)) {
            std::string term = "";

            term += a ? "!a" : "a";
            term += b ? "!b" : "b";
            term += c ? "!c" : "c";
            term += d ? "!d" : "d";
            term += e ? "!e" : "e";

            result.push_back("(" + term + ")");
        }
    }

    std::cout << "\nСовершенная конъюнктивная нормальная форма (СКНФ):\n";

    for (auto term : result)
    {
        std::cout << term << " * ";
    }

    std::cout << "\n";
}

int main() 
{
    // русская локаль
    setlocale(LC_ALL, "Russian");
    
    // зовем методы по заданию
    generateTruthTable();
    generatePureDisjunctiveForm();
    generatePureConjunctiveForm();
}