#ifndef AIZO_1_INSERTSORTNOTBINARY_H
#define AIZO_1_INSERTSORTNOTBINARY_H


#include "../../Sort.h"

template <typename T>
class InsertSortNotBinary : public Sort<T>
{
public:
    /**
     * Konstruktor obiektu
     * @param writingMode 1, jeżeli chcemy wypisać do pliku
     * @param dataToSort tablica do posortowania
     * @param repeatNumber ilość powtórzeń
     */
    InsertSortNotBinary(bool writingMode, Data<T> &dataToSort, int repeatNumber);

    /**
     * Funkcja, która sortuje tablice przy użyciu algorytmu sortowania przez wstawianie i poszukiwania binarnego
     * @param unsortedArray nieposortowana tablica
     */
    void sortByInsertionNotBinary(Data<T> &unsortedArray);
};

template class InsertSortNotBinary<int>;
template class InsertSortNotBinary<float>;

#endif //AIZO_1_INSERTSORTNOTBINARY_H
