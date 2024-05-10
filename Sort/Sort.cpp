#include "Sort.h"
#include "./DifferentSorts/QuickSort/QuickSort.h"

template<typename T>
Sort<T>::Sort(bool writingMode, Data<T> &dataToSort, int repeatNumber) : writingMode(writingMode),
                                                                         dataToSort(dataToSort.getSize()),
                                                                         repeatNumber(repeatNumber)
{

    this->dataToSort = Data<T>(dataToSort.getSize());
    this->repeatNumber = repeatNumber;

    for (int i = 0; i < dataToSort.getSize(); ++i)
    {
        this->dataToSort.setValue(i, dataToSort.getValue(i));
    }

    this->writingMode = writingMode;
}

template<typename T>
Data<T> &Sort<T>::getDataToSort()
{
    return dataToSort;
}

template<typename T>
void Sort<T>::startTimeCheck()
{
    this->startTime = std::chrono::steady_clock::now();
}

template<typename T>
void Sort<T>::endTimeCheck()
{
    endTime = std::chrono::steady_clock::now();
}

template<typename T>
void Sort<T>::writeData(std::string sortingMethodName, int size, std::string sortOrder)
{
    const char *userProfile = std::getenv("USERPROFILE");

    if (userProfile != nullptr)
    {
        std::string desktopPath = std::string(userProfile) + "\\Desktop\\collectedData.csv";
        std::ofstream outputFile(desktopPath, std::ofstream::app);
        outputFile << typeid(T).name() << "," << sortingMethodName << "," << size << "," << sortOrder << ", "
                   << std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime).count() << std::endl;

        outputFile.close();
    } else
    {
        std::cerr << "Error: USERPROFILE environment variable not found.\n";
    }

}

template<typename T>
void Sort<T>::chooseArrayToSortType()
{
    std::cout << "1. Random" << std::endl;
    std::cout << "2. Ascending" << std::endl;
    std::cout << "3. Descending" << std::endl;
    std::cout << "4. 33% Sorted" << std::endl;
    std::cout << "5. 66% Sorted" << std::endl;
    std::cout << "6. Dont change" << std::endl;

    std::cout << "I choose: ";
    std::cin >> tmp;
}

template<typename T>
void Sort<T>::arrayToSortType()
{
    switch (tmp)
    {
        case 1:
            dataToSort.fillArrayWithRandomNumbers();
            break;
        case 2:
            dataToSort.fillArrayWithRandomNumbers();
            QuickSort(this->dataToSort, this->dataToSort.getSize());

            break;
        case 3:
            dataToSort.fillArrayWithRandomNumbers();
            QuickSort(this->dataToSort, this->dataToSort.getSize());

            for (int i = 0; i < dataToSort.getSize() / 2; ++i)
            {
                dataToSort.swapValues(i, dataToSort.getSize() - i - 1);
            }

            break;
        case 4: {
            dataToSort.fillArrayWithRandomNumbers();

            QuickSort(this->dataToSort, 0.33 * this->dataToSort.getSize());

            T max = dataToSort.getValue(0.33 * this->dataToSort.getSize());

            for (int i = 0.33 * this->dataToSort.getSize(); i < this->dataToSort.getSize() - 1; ++i) {
                dataToSort.setValue(i, dataToSort.getValue(i) + max);
            }

            break;
        }
        case 5: {
            dataToSort.fillArrayWithRandomNumbers();
            QuickSort(this->dataToSort, 0.66 * this->dataToSort.getSize());

            T max = dataToSort.getValue(0.66 * this->dataToSort.getSize());

            for (int i = 0.66 * this->dataToSort.getSize(); i < this->dataToSort.getSize() - 1; ++i) {
                dataToSort.setValue(i, dataToSort.getValue(i) + max);
            }

            break;
        }
        case 6:
            break;
    }
}

template<typename T>
std::string Sort<T>::getSortOrderName()
{
    switch (tmp)
    {
        case 1:
            return "Random";
        case 2:
            return "Ascending";
        case 3:
            return "Descending";
        case 4:
            return "33% sorted";
        case 5:
            return "66% sorted";
        case 6:
            return "Doesnt change";
    }
}

template<typename T>
void Sort<T>::showProgressBar(int currentCycle, int totalCycles)
{
    float progress = (float) currentCycle / totalCycles;
    int barWidth = 70;

    std::cout << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << int(progress * 100.0) << " %\r";
    std::cout.flush();

    std::cout << std::endl;
}



