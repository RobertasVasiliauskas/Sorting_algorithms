
#include "Data.h"

template<typename T>
Data<T>::Data(int size)
{
    this->SIZE = size;
    this->pointer = new T[size];

   fillArrayWithRandomNumbers();
}

template<typename T>
void Data<T>::fillArrayWithRandomNumbers()
{
    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_real_distribution<float> dist(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());

    for (int i = 0; i < this->SIZE; ++i)
    {
        pointer[i] = dist(eng);
    }
}

template<typename T>
void Data<T>::freeDynamicArray()
{
    delete []pointer;
}

template<typename T>
void Data<T>::printArray()
{
    for (int i = 0; i < this->SIZE; ++i)
    {
        std::cout << i + 1 << " " << pointer[i] << std::endl;
    }
}

template<typename T>
bool Data<T>::isSorted()
{
    for (int i = 0; i < this->SIZE - 1; ++i)
    {
        if(pointer[i] > pointer[i+1]) return false;
    }

    return true;
}

template<typename T>
int Data<T>::getSize() const
{
    return SIZE;
}

template<typename T>
void Data<T>::resize(int newSize)
{
    if (newSize == SIZE)
    {
        return;
    }

    T* newArray = new T[newSize];

    int elementsToCopy = (newSize < SIZE) ? newSize : SIZE;

    for (int i = 0; i < elementsToCopy; ++i)
    {
        newArray[i] = pointer[i];
    }

    delete[] pointer;

    pointer = newArray;
    SIZE = newSize;
}

template<typename T>
T Data<T>::getValue(int index)
{
    return pointer[index];
}

template<typename T>
void Data<T>::setValue(int index, T value)
{
    if (index >= 0 && index < SIZE)
    {
        pointer[index] = value;
    }
    else
    {
        std::cerr << "Error: Index out of bounds." << std::endl;
    }
}

template<typename T>
void Data<T>::swapValues(int indexOne, int indexTwo)
{
    std::swap(pointer[indexOne], pointer[indexTwo]);
}

