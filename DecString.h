/**
 * Численная строка
 * @file DecString.h
 * @author Сааль Степан
 */
#ifndef LAB6_DECSTRING_H
#define LAB6_DECSTRING_H

#include "String.h"

using namespace std;

/**
 * Численная строка
 */
class DecString: public StringObject {
public:
    using StringObject::StringObject;

    /**
     * Операция вычитания
     * @param second
     * @return
     */
    StringObject* operator -(StringObject &second) override
    {
        if (second.getType() == "SymbString") {
            string result = stringSubtraction(getValue(), second.getValue());
            return new SymbString(result);
        } else {
            int result = getDec() - second.getDec();
            string stringResult(to_string(result));
            return new DecString(stringResult);
        }
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
        return stoi(getValue());
    }

private:
    /** тип */
    string type = "DecString";
};


#endif //LAB6_DECSTRING_H
