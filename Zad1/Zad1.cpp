#include <iostream>
#include <vector>


// шапка таблицы
void printHeader() 
{
    std::cout << "a\tb\tc\td\te\tF\n";
    std::cout << "-----------------------------------------\n";
}


// целевое выражение - вариант 7
bool taskExpression(bool a, bool b, bool c, bool d, bool e) 
{
    return (!a || b) && c && (d || !e);
}

// генератор СДНФ
void generatePureDisjuctiveForm()
{
    std::vector<std::string> res;

    // через побитовое И проходим всю таблицу истинности
    // для каждой строки высчитываем значение
    for (int i = 0; i < 32; i++) 
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func = taskExpression(a, b, c, d, e);

        // формирование СДНФ
        // если результат булевой функции == true
        // формируем конъюнкцию всех переменных
        if (func)
        {
            std::string exp;

            // через тернарный оператор подставляем нужное значение перменных
            std::string exp_a = a ? "a" : "!a";
            std::string exp_b = b ? "b" : "!b";
            std::string exp_c = c ? "c" : "!c";
            std::string exp_d = d ? "d" : "!d";
            std::string exp_e = e ? "e" : "!e";
            
            // формируем члены СДНФ
            exp += "(" + exp_a + " && " + exp_b + " && " + exp_c + " && " + exp_d + " && " + exp_e + ")";

            // пушим член СДНФ в массив
            res.push_back(exp);
        }
    }

    // вывод СДНФ
    std::cout << "\nСовершенная дизъюнктивная нормальная форма (СДНФ):\n";

    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i];

        // обработка последнего члена
        if (i != res.size() - 1)
        {
            std::cout << " || ";
        }
    }
}

// генератор СКНФ
void generatePureConjuctiveForm()
{
    std::vector<std::string> res;

    // через побитовое И проходим всю таблицу истинности
    // для каждой строки высчитываем значение
    for (int i = 0; i < 32; i++) 
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func = taskExpression(a, b, c, d, e);

        // формирование СКНФ
        // если результат булевой функции == false
        // формируем дизъюнкцию всех переменных
        if (!func)
        {
            std::string exp;

            // через тернарный оператор подставляем нужное значение перменных
            std::string exp_a = a ? "!a" : "a";
            std::string exp_b = b ? "!b" : "b";
            std::string exp_c = c ? "!c" : "c";
            std::string exp_d = d ? "!d" : "d";
            std::string exp_e = e ? "!e" : "e";
            
            // формируем члены СКНФ
            exp += "(" + exp_a + " || " + exp_b + " || " + exp_c + " || " + exp_d + " || " + exp_e + ")";
            
            // пушим член СКНФ в массив
            res.push_back(exp);
        }
    }

    // вывод СКНФ
    std::cout << "\nСовершенная конъюнктивная нормальная форма:\n";

    for (int i = 0; i < res.size(); i++)
    {
        std::cout << res[i];

        // обработка последнего члена
        if (i != res.size() - 1)
        {
            std::cout << " * ";
        }
    }
}

// генератор таблицы истинности
void generateTruthTable() 
{
    // через побитовое И генерируем таблицу истинности
    // для каждой возможной комбинации высчитываем функцию
    for (int i = 0; i < 32; i++) 
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func_res = taskExpression(a, b, c, d, e);

        // вывод строки
        std::cout << a << "\t" << b << "\t" << c << "\t" << d << "\t" << e << "\t" << func_res << std::endl;
    }
}

int main() 
{
    // Вариант 2
    setlocale(LC_ALL, "Rus");

    // выводим шапку таблицы
    printHeader();
    // выводим таблицу истинности
    generateTruthTable();

    // генерим СДНФ и выводим
    generatePureDisjuctiveForm();
    std::cout << std::endl;
    // генерим СКНФ и выводим
    generatePureConjuctiveForm();
}
