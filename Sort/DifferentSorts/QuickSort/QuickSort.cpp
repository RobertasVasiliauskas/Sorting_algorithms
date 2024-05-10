//
// Created by rober on 3/6/2024.
//

#include "QuickSort.h"

template<typename T>
QuickSort<T>::QuickSort(bool writingMode, Data<T> &dataToSort, int repeatNumber): Sort<T>(writingMode, dataToSort,
                                                                                          repeatNumber)
{
    this->chooseArrayToSortType();
    this->arrayToSortType();

    for (int i = 0; i < repeatNumber; i++)
    {
        this->showProgressBar(i, repeatNumber);

        this->startTimeCheck();
        sortByFastSort(this->getDataToSort(), 0, dataToSort.getSize() - 1);
        this->endTimeCheck();

        if (this->getDataToSort().isSorted())
        {
            if (writingMode)
            {
                this->writeData("QuickSort", this->getDataToSort().getSize(), this->getSortOrderName());
            } else
            {
                this->getDataToSort().printArray();
            }
        } else
        {
            std::cout << "ERROR: QuickSort failed" << std::endl;
        }

        if (repeatNumber != 1)
        {
            this->arrayToSortType();
        }
    }
    this->getDataToSort().freeDynamicArray();
}


template<typename T>
QuickSort<T>::QuickSort(Data<T> &dataToSort, int sortToIndex): Sort<T>(0, dataToSort, 1)
{
    sortByFastSort(dataToSort, 0, sortToIndex - 1);
}



template<typename T>
void QuickSort<T>::sortByFastSort(Data<T> &unsortedArray, int left, int right)
{
    if (left < right)
    {
        T pivot = unsortedArray.getValue((left+right)/2);

        int i = left;
        int j = right;

        while (i <= j)
        {
            while (unsortedArray.getValue(i) < pivot)
            {
                i++;
            }

            while (unsortedArray.getValue(j) > pivot)
            {
                j--;
            }

            if (i <= j)
            {
                unsortedArray.swapValues(i, j);
                i++;
                j--;
            }
        }

        sortByFastSort(unsortedArray, left, j);
        sortByFastSort(unsortedArray, i, right);
    }
}
