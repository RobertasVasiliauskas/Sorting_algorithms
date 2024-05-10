#include "InsertSortNotBinary.h"
#include <iostream>

template<typename T>
InsertSortNotBinary<T>::InsertSortNotBinary(bool writingMode, Data<T> &dataToSort, int repeatNumber): Sort<T>(writingMode, dataToSort, repeatNumber)
{
    this->chooseArrayToSortType();
    this->arrayToSortType();

    for (int i = 0; i < repeatNumber; i++)
    {
        this->showProgressBar(i, repeatNumber);

        this->startTimeCheck();
        sortByInsertionNotBinary(this->getDataToSort());
        this->endTimeCheck();

        if (this->getDataToSort().isSorted())
        {
            if (writingMode)
            {
                this->writeData("InsertSortNotBinary", this->getDataToSort().getSize(), this->getSortOrderName());
            } else
            {
                this->getDataToSort().printArray();
            }
        }
        else
        {
            std::cout << "ERROR: InsertSortNotBinary failed" << std::endl;
        }

        if(repeatNumber != 1)
        {
            this->arrayToSortType();
        }
    }
    this->getDataToSort().freeDynamicArray();
}

template<typename T>
void InsertSortNotBinary<T>::sortByInsertionNotBinary(Data<T> &unsortedArray)
{
    for (int i = 1; i < unsortedArray.getSize(); i++) {
        T key = unsortedArray.getValue(i);
        int j = i - 1;

        while (j >= 0 && unsortedArray.getValue(j) > key) {
            unsortedArray.setValue(j + 1, unsortedArray.getValue(j));
            j = j - 1;
        }
        unsortedArray.setValue(j + 1, key);
    }
}
