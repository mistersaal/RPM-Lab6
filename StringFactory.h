/**
 * Фабрика строк
 * @file StringFactory
 * @author Сааль Степан
 */
#ifndef LAB6_STRINGFACTORY_H
#define LAB6_STRINGFACTORY_H
#include <string>
#include "String.h"
#include "SymbString.h"
#include "DecString.h"

using namespace std;

/**
 * Фабрика строк
 */
class StringFactory {
public:
    /**
     * Создание объекта в зависимости от типа
     * @param value
     * @return
     */
    static StringObject* createObject(string& value)
    {
        string type;

        if (detectType(value) == "dec") {
            return new DecString(value);
        } else {
            return new SymbString(value);
        }

    }

    /**
     * Удаление объекта
     * @param object
     */
    static void deleteObject(StringObject* object)
    {
        delete object;
    }

    /**
     * Определение типа
     * @param value
     * @return
     */
    static string detectType(const string& value)
    {
        for (char c: value) {
            if (c >= '0' && c <= '9') {
                continue;
            } else {
                return "string";
            }
        }
        return "dec";
    }
};


#endif //LAB6_STRINGFACTORY_H
