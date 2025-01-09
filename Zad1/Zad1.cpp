#include <iostream>
#include <vector>

// Целевое выражение - вариант 7
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

// Генерация Совершенной Дизъюнктивной Нормальной Формы (СДНФ)
void generatePureDisjunctiveForm() {
    std::vector<std::string> terms;

    for (int i = 0; i < 32; ++i)
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func = taskExpression(a, b, c, d, e);

        if (taskExpression(a, b, c, d, e)) {
            std::string term = "";

            term += a ? "a" : "!a";
            term += b ? "b" : "!b";
            term += c ? "c" : "!c";
            term += d ? "d" : "!d";
            term += e ? "e" : "!e";

            terms.push_back("(" + term + ")");
        }
    }

    std::cout << "\nСовершенная дизъюнктивная нормальная форма (СДНФ):\n";

    for (const auto& term : terms) {
        std::cout << term << " || ";
    }

    std::cout << "false\n";
}

// Генерация Совершенной Конъюнктивной Нормальной Формы (СКНФ)
void generatePureConjunctiveForm() {
    std::vector<std::string> clauses;
    for (int i = 0; i < 32; ++i)
    {
        bool a = i & 16;
        bool b = i & 8;
        bool c = i & 4;
        bool d = i & 2;
        bool e = i & 1;
        bool func = taskExpression(a, b, c, d, e);

        if (!taskExpression(a, b, c, d, e)) {
            std::string clause = "";

            clause += a ? "!a" : "a";
            clause += b ? "!b" : "b";
            clause += c ? "!c" : "c";
            clause += d ? "!d" : "d";
            clause += e ? "!e" : "e";

            clauses.push_back("(" + clause + ")");
        }
    }

    std::cout << "\nСовершенная конъюнктивная нормальная форма (СКНФ):\n";

    for (const auto& clause : clauses) {
        std::cout << clause << " * ";
    }

    std::cout << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");

    generateTruthTable();
    generatePureDisjunctiveForm();
    generatePureConjunctiveForm();
}