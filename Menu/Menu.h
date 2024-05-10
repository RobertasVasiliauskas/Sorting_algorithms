#ifndef AIZO_1_MENU_H
#define AIZO_1_MENU_H

#include <iostream>
#include <fstream>
#include "../Data/Data.h"
#include <string>

class Menu
{
    private:

    int variableType = 0;
    int variableMenu = 0;
    int arrayLength = 0;
    int repeatNumber = 1;
    int tmp;
    std::string filename;
    std::string stringTmp;
    bool writingMode = false;
    bool firstMenu = true;
    bool secondMenu = true;

    /**
     * Funkcja, która wyświetla pierwszy poziom menu
     */
    void showFirstMenu();

    /**
     * Funkcja, która wyświetla tekst pierwszego poziomu menu
     */
    static void showTextFirstMenu();

    /**
     * Funkcja, która ustawia jaki punkt pierwszego poziomu menu chcemy wybrać
     */
    void chooseVariableType();

    /**
     * Funkcja, która sprawdza czy wartość ustawiona na punkt, który chcemy odwiedzić istnieje
     * @param min minimalny numer menu
     * @param max maksymalny numer menu
     * @param variableToCheck wartość do sprawdzenia
     * @return prawda, jeżeli istnieje taki punkt menu
     */
    static bool checkVariable(int min, int max, int variableToCheck);

    /**
     * Funkcja, która wyświetla drugi poziom menu
     */
    static void showTextSecondMenu();

    /**
     * Funkcja, która ustawia jaki punkt drugiego poziomu menu chcemy wybrać
     */
    void chooseMenuVariable();

    /**
     * Funkcja, która wyświetla możliwe rozmiary tablicy
     */
    static void showTextLengthOfArray();

    /**
     * Funkcja, która ustawia wielkość generowanej tablicy
     */
    void chooseArrayLength();

    /**
     * Funkcja, Funkcja, która ustawia wielkość generowanej tablicy
     * @param arrayLength
     * @return wielkość generowanej tablicy
     */
    static int convertInputToSize(int arrayLength);

    /**
     * Funkcja, która ustawia ilość powtórzeń
     * @param variable ilość powtórzeń
     */
    void setRepeatNumber(int variable);

    /**
     * Funkcja, która wyświetla tekst do wpisywania ilości powtórzeń
     */
    static void showRepeatNumberText();

    /**
     * Funkcja, która odczytuje dane z pliku
     * @param dataInt tablica bez rozmiaru
     * @param dataFloat tablica bez rozmiaru
     */
    void readFromFile(Data<int> dataInt, Data<float> dataFloat);

    /**
     * Funkcja, która ustala typ danych z pliku
     * @param filename nazwa pliku
     * @return 0, jeżeli int
     */
    static int getType(std::string filename);

    /**
     * Funkcja, która wyświetla drugi poziom menu dla wartości int, jeżeli wczytujemy dane
     * @param dataInt tablica odczytana z pliku
     */
    void showSecondMenuInt(Data<int> dataInt);

    /**
     * Funkcja, która wyświetla drugi poziom menu dla wartości int, jeżeli wczytujemy dane
     * @param dataFloat tablica odczytana z pliku
     */
    void showSecondMenuFloat(Data<float> dataFloat);

    public:

    /**
     * Konstruktor objektu Menu
     */
    Menu();

};


#endif //AIZO_1_MENU_H
