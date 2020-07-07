/**
 * Символьная строка
 * @file SymbString.h
 * @author Сааль Степан
 */
#ifndef LAB6_SYMBSTRING_H
#define LAB6_SYMBSTRING_H

#include "String.h"
#include <exception>

using namespace std;

/**
 * Символьная строка
 */
class SymbString: public StringObject {
public:
    using StringObject::StringObject;

    /**
     * Операция вычитания
     * @param second
     * @return
     */
    StringObject* operator -(StringObject &second) override
    {
        string result = stringSubtraction(getValue(), second.getValue());
        return new SymbString(result);
    }

    /**
     * Получение типа
     * @return
     */
    string getType() final
    {
        return type;
    }

    /**
     * Получение численного значения
     * @return
     */
    int getDec() final
    {
        string error = getType() + " can't be converted to dec";
        throw runtime_error(error);
    }

private:
    /** тип */
    string type = "SymbString";
};


#endif //LAB6_SYMBSTRING_H
