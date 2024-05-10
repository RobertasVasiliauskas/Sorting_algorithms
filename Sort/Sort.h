#ifndef AIZO_1_SORT_H
#define AIZO_1_SORT_H

#include "../Data/data.h"
#include <fstream>
#include <cstdlib>
#include <chrono>
#include <string>
#include <windows.h>

template<typename T>
class Sort
{
private:
    bool writingMode = false;
    int repeatNumber = 0;
    int tmp = 0;
    Data<T> dataToSort;
    std::chrono::time_point<std::chrono::steady_clock> startTime;
    std::chrono::time_point<std::chrono::steady_clock> endTime;

public:

    /**
     * Konstruktor objektu Sort
     * @param writingMode 1, jeżeli wypisujemy dane
     * @param dataToSort tablica do posortowania
     * @param repeatNumber ilość powtórzeń sortowań
     */
    Sort(bool writingMode, Data<T> &dataToSort, int repeatNumber);

    /**
     * Funkcja, która zwraca kopie danych do posortowania
     * @return kopia danych do posortowania
     */
    Data<T> &getDataToSort();

    /**
     * zapisuje czas początku pomiaru
     */
    void startTimeCheck();

    /**
     * zapisuje czas końca pomiaru
     */
    void endTimeCheck();

    /**
     * Funkcja, która wypisuje wyniki do pliku
     * @param sortingMethodName nazwa algorytmu sortowania
     * @param size rozmiar tablicy do posortowania
     * @param sortOrder przypadek specjalny dla sortowania
     */
    void writeData(std::string sortingMethodName, int size, std::string sortOrder);

    /**
     * Funkcja, która ustawia przypadek specjalny dla sortowania
     */
    void arrayToSortType();

    /**
     * Funkcja, która ustawia, który przypadek chcemy posortować
     */
    void chooseArrayToSortType();

    /**
     * Funkcja, która wyświetla ile zostało zrobionych sortowań
     * @param currentCycle aktualna iteracja
     * @param totalCycles ilość powtórzeń
     */
    void showProgressBar(int currentCycle, int totalCycles);

    /**
     * Funkcja, która zwraca nazwę algorytmu do posortowania
     * @return nazwa algorytmu
     */
    std::string getSortOrderName();
};
template
class Sort<int>;

template
class Sort<float>;

#endif //AIZO_1_SORT_H
