/**
 * Объект строки
 * @file String.h
 * @author Сааль Степан
 */
#ifndef LAB6_STRING_H
#define LAB6_STRING_H

#include <string>

using namespace std;

/**
 * Объект строки
 */
class StringObject {

public:
    explicit StringObject(string &value) : value(value) {}

    /**
     * Получать значение
     * @return string значение
     */
    string getValue()
    {
        return value;
    }

    /**
     * Операция вычитания
     * @param second
     * @return
     */
    virtual StringObject* operator -(StringObject &second) = 0;
    /**
     * Получить тип строки
     * @return
     */
    virtual string getType() = 0;
    /**
     * Получить численное значение строки
     * @return
     */
    virtual int getDec() = 0;

private:
    /** значение */
    string value;

protected:
    /**
     * Вычитание строк
     * @param reduced
     * @param subtrahend
     * @return
     */
    string stringSubtraction(const string& reduced, const string& subtrahend)
    {
        string result = reduced;
        int position;

        while ((position = result.find(subtrahend)) != std::string::npos) {
            result.erase(position, subtrahend.size());
        }

        return result;
    }

};


#endif //LAB6_STRING_H
