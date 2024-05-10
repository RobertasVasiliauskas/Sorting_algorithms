//
// Created by rober on 3/10/2024.
//

#include "HeapSort.h"

template<typename T>
HeapSort<T>::HeapSort(bool writingMode, Data<T> &dataToSort, int repeatNumber): Sort<T>(writingMode, dataToSort, repeatNumber)
{
    this->chooseArrayToSortType();
    this->arrayToSortType();

    for (int i = 0; i < repeatNumber; ++i)
    {
        this->showProgressBar(i, repeatNumber);

        this->startTimeCheck();
        sortByHeapSort(this->getDataToSort());
        this->endTimeCheck();

        if (this->getDataToSort().isSorted())
        {
            if (writingMode)
            {
                this->writeData("HeapSort", this->getDataToSort().getSize(), this->getSortOrderName());
            } else
            {
                this->getDataToSort().printArray();
            }
        } else
        {
            std::cout << "ERROR: Heap failed" << std::endl;
        }

        if(repeatNumber != 1)
        {
            this->arrayToSortType();
        }
    }
    this->getDataToSort().freeDynamicArray();
}

template<typename T>
void HeapSort<T>::sortByHeapSort(Data<T> &unsortedArray)
{
    for (int i = unsortedArray.getSize() / 2 - 1; i >= 0; i--)
    {
        heapify(unsortedArray, unsortedArray.getSize(), i);
    }

    for (int i = unsortedArray.getSize() - 1; i >= 0; i--)
    {
        unsortedArray.swapValues(0, i);
        heapify(unsortedArray, i, 0);
    }
}

template<typename T>
void HeapSort<T>::heapify(Data<T> &unsortedArray, int size, int index)
{
    int largest = index;
    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if (l < size && unsortedArray.getValue(l) > unsortedArray.getValue(largest))
    {
        largest = l;
    }

    if (r < size && unsortedArray.getValue(r) > unsortedArray.getValue(largest))
    {
        largest = r;
    }

    if (largest != index)
    {
        unsortedArray.swapValues(index, largest);
        heapify(unsortedArray, size, largest);
    }
}

