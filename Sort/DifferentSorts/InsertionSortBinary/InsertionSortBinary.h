//
// Created by rober on 3/10/2024.
//

#ifndef AIZO_1_INSERTIONSORTBINARY_H
#define AIZO_1_INSERTIONSORTBINARY_H


#include "../../Sort.h"

template <typename T>
class InsertSortBinary : public Sort<T>
{
public:
    /**
     * Konstruktor obiektu
     * @param writingMode 1, jeżeli chcemy wypisać do pliku
     * @param dataToSort tablica do posortowania
     * @param repeatNumber ilość powtórzeń
     */
    InsertSortBinary(bool writingMode, Data<T> &dataToSort, int repeatNumber);

    /**
     * Funkcja, która sortuje tablice przy użyciu algorytmu sortowania przez wstawianie
     * @param unsortedArray nieposortowana tablica
     */
    void sortByInsertionBinary(Data<T> &unsortedArray);
};

template class InsertSortBinary<int>;
template class InsertSortBinary<float>;


#endif //AIZO_1_INSERTIONSORTBINARY_H
