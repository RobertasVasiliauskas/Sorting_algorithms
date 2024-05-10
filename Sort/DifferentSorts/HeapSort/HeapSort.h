//
// Created by rober on 3/10/2024.
//

#ifndef AIZO_1_HEAPSORT_H
#define AIZO_1_HEAPSORT_H

#include "../../Sort.h"

template <typename T>
class HeapSort : public Sort<T>
{
    public:
    /**
     * Konstruktor obiektu
     * @param writingMode 1, jeżeli chcemy wypisać do pliku
     * @param dataToSort tablica do posortowania
     * @param repeatNumber ilość powtórzeń
     */
    HeapSort(bool writingMode, Data<T> &dataToSort, int repeatNumber);

    /**
     * Funkcja, która sortuje tablice przy użyciu kopca
     * @param unsortedArray nieposortowana tablica
     */
    void sortByHeapSort(Data<T> &unsortedArray);

    /**
     * Funkcja, która naprawia kopiec
     * @param unsortedArray kopiec
     * @param size wielkość kopca
     * @param index korzeń kopca
     */
    void heapify(Data<T> &unsortedArray, int size, int index);
};

template class HeapSort<int>;
template class HeapSort<float>;

#endif //AIZO_1_HEAPSORT_H
