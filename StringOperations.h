/**
 * Меню
 * @file StringOperations.h
 * @author Сааль Степан
 */
#ifndef LAB6_STRINGOPERATIONS_H
#define LAB6_STRINGOPERATIONS_H
#include <iostream>
#include <string>
#include "StringFactory.h"

using namespace std;

/**
 * Меню для операций со строками
 */
class StringOperations {
public:
    /**
     * Показать меню
     */
    void showMenu()
    {
        mainMenu();
    }

private:
    /**
     * Конструктор
     */
    StringObject* objects[2] = {nullptr, nullptr};
    /**
     * Вывод главного меню
     */
    void mainMenu()
    {
        int choice;
        cout << endl << "Main menu:" << endl;
        cout << "1. Create object" << endl;
        cout << "2. Delete object" << endl;
        cout << "3. Show object" << endl;
        cout << "4. 1st object minus 2nd object" << endl;
        cout << "0. Exit" << endl;
        cin >> choice;
        mainMenuAction(choice);
    }

    /**
     * Выбор действия из главного меню
     * @param choice
     */
    void mainMenuAction(int choice)
    {
        switch (choice) {
            case 1: createObjectMenu(); break;
            case 2: deleteObjectMenu(); break;
            case 3: showObjectMenu(); break;
            case 4: subObjectsMenu(); break;
            case 0: cout << "Bye bye!"; return;
            default: cout << "Wrong number, try again" << endl;
        }
        mainMenu();
    }

    /**
     * Меню создания объекта
     */
    void createObjectMenu()
    {
        int number = chooseObject() - 1;
        string value;
        cout << endl << "Input value for new object:" << endl;
        cin >> value;
        objects[number] = StringFactory::createObject(value);
        cout << "Created (" << objects[number]->getType() << ") \""
             << objects[number]->getValue() << "\"" << endl;
    }

    /**
     * Меню удаления объекта
     */
    void deleteObjectMenu()
    {
        int number = chooseObject() - 1;
        if (objects[number] == nullptr) {
            cout << "Object doesn't exists" << endl;
            return;
        }
        StringFactory::deleteObject(objects[number]);
        objects[number] = nullptr;
        cout << "Object #" << number + 1 << " deleted" << endl;
    }

    /**
     * Меню отображения объекта
     */
    void showObjectMenu()
    {
        int number = chooseObject() - 1;
        if (objects[number] == nullptr) {
            cout << "Object doesn't exists" << endl;
            return;
        }
        cout << "Object: (" << objects[number]->getType() << ") \""
             << objects[number]->getValue() << "\"" << endl;
    }

    /**
     * Вычитание
     */
    void subObjectsMenu()
    {
        if (objects[0] == nullptr || objects[1] == nullptr) {
            cout << "One or both object(-s) doesn't exists" << endl;
            return;
        }
        StringObject* result = *objects[0] - *objects[1];
        cout << "(" << objects[0]->getType() << ") \"" << objects[0]->getValue() << "\"" << " - "
             << "(" << objects[1]->getType() << ") \"" << objects[1]->getValue() << "\"" << endl;
        cout << "Result: (" << result->getType() << ") \""
             << result->getValue() << "\"" << endl;
    }

    /**
     * Меню выбора объекта
     * @return
     */
    int chooseObject()
    {
        int choice;
        while (true) {
            cout << endl << "Choose object for action:" << endl;
            cout << "1. First object" << endl;
            cout << "2. Second object" << endl;
            cin >> choice;
            if (choice == 1 || choice == 2) return choice;
            cout << "Wrong number, try again" << endl;
        }
    }
};


#endif //LAB6_STRINGOPERATIONS_H
