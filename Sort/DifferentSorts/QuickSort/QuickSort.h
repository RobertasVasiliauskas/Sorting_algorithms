//
// Created by rober on 3/6/2024.
//

#ifndef AIZO_1_QUICKSORT_H
#define AIZO_1_QUICKSORT_H


#include "../../Sort.h"

template <typename T>
class QuickSort : public Sort<T>
{
public:
    /**
     * Konstruktor obiektu
     * @param writingMode 1, jeżeli chcemy wypisać do pliku
     * @param dataToSort tablica do posortowania
     * @param repeatNumber ilość powtórzeń
     */
    QuickSort(bool writingMode, Data<T> &dataToSort, int repeatNumber);

    /**
     * Konstruktor obiektu
     * @param writingMode 1, jeżeli chcemy wypisać do pliku
     * @param sortToIndex do którego indeksu sortować
     */
    QuickSort(Data<T> &dataToSort, int sortToIndex);

    /**
     *  Funkcja, która sortuje tablice przy użyciu algorytmu szybkiego sortowania
     * @param unsortedArray nieposortowana tablica
     * @param left początek tablicy
     * @param right koniec tablicy
     */
    void sortByFastSort(Data<T> &unsortedArray, int left, int right);
};

template class QuickSort<int>;
template class QuickSort<float>;

#endif //AIZO_1_QUICKSORT_H
