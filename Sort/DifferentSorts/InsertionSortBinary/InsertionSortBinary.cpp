//
// Created by rober on 3/10/2024.
//

#include "InsertionSortBinary.h"

template<typename T>
InsertSortBinary<T>::InsertSortBinary(bool writingMode, Data<T> &dataToSort, int repeatNumber): Sort<T>(writingMode, dataToSort, repeatNumber)
{

    this->chooseArrayToSortType();
    this->arrayToSortType();

    for (int i = 0; i < repeatNumber; ++i)
    {
        this->showProgressBar(i, repeatNumber);

        this->startTimeCheck();
        sortByInsertionBinary(this->getDataToSort());
        this->endTimeCheck();

        if (this->getDataToSort().isSorted())
        {
            if (writingMode)
            {
                this->writeData("InsertSortBinary", this->getDataToSort().getSize(), this->getSortOrderName());
            } else
            {
                this->getDataToSort().printArray();
            }
        } else
        {
            std::cout << "ERROR: InsertSortBinary failed" << std::endl;
        }

        if(repeatNumber != 1)
        {
            this->arrayToSortType();
        }

    }
    this->getDataToSort().freeDynamicArray();
}

template<typename T>
void InsertSortBinary<T>::sortByInsertionBinary(Data<T> &unsortedArray)
{

    for (int i = 1; i < unsortedArray.getSize(); ++i)
    {
        T key = unsortedArray.getValue(i);
        int j = i;

        int low = 0;
        int high = i - 1;
        int insertionPoint = i;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (key < unsortedArray.getValue(mid))
            {
                insertionPoint = mid;
                high = mid - 1;
            } else
            {
                low = mid + 1;
            }
        }

        for (int x = i; x > insertionPoint; --x)
        {
            unsortedArray.setValue(x, unsortedArray.getValue(x - 1));
        }

        unsortedArray.setValue(insertionPoint, key);
    }
}
