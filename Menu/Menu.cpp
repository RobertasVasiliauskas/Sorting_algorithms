#include "Menu.h"
#include "../Sort/DifferentSorts/InsertSortNotBinary/InsertSortNotBinary.h"
#include "../Sort/DifferentSorts/QuickSort/QuickSort.h"
#include "../Sort/DifferentSorts/InsertionSortBinary/InsertionSortBinary.h"
#include "../Sort/DifferentSorts/HeapSort/HeapSort.h"

Menu::Menu()
{
    showFirstMenu();
}

void Menu::showTextFirstMenu()
{
    std::cout << "1. int" << std::endl << "2. float" << std::endl << "3. Read from file" << std::endl << "4. Exit"
              << std::endl;
}

void Menu::chooseVariableType()
{
    std::cout << "I choose:";
    std::cin >> variableType;
}

bool Menu::checkVariable(int min, int max, int variableToCheck)
{
    for (int i = min; i <= max; ++i)
    {
        if (i == variableToCheck) return true;
    }

    return false;
}

void Menu::showTextSecondMenu()
{
    std::cout <<
              "1. Set repeat time" << std::endl <<
              "2. Show array " << std::endl <<
              "3. Set writing to document mode(default false) " << std::endl <<
              "4. Insertion sort (not binary)" << std::endl <<
              "5. Insertion sort (binary)" << std::endl <<
              "6. Heap sort" << std::endl <<
              "7. Quick sort" << std::endl <<
              "8. Choose another variable type" << std::endl;
}

void Menu::showFirstMenu()
{
    while (firstMenu)
    {
        showTextFirstMenu();
        chooseVariableType();

        secondMenu = true;

        while (!checkVariable(1, 4, variableType))
        {
            std::cout << "wrong input, please write one more time" << std::endl;
            showTextFirstMenu();
            chooseVariableType();
        }

        switch (variableType)
        {
            // int
            case 1:
            {
                showTextLengthOfArray();
                chooseArrayLength();

                while (!checkVariable(1, 7, arrayLength))
                {
                    std::cout << "wrong input, please write one more time" << std::endl;
                    showTextLengthOfArray();
                    chooseArrayLength();
                }

                Data<int> dataInt(convertInputToSize(arrayLength));

                showSecondMenuInt(dataInt);

                break;
            }
                // float
            case 2:
            {
                showTextLengthOfArray();
                chooseArrayLength();

                while (!checkVariable(1, 7, arrayLength))
                {
                    std::cout << "wrong input, please write one more time" << std::endl;
                    showTextLengthOfArray();
                    chooseArrayLength();
                }

                Data<float> dataFloat(convertInputToSize(arrayLength));

                showSecondMenuFloat(dataFloat);

                break;
            }

            case 3:
            {
                Data<int> dataInt(0);
                Data<float> dataFloat(0);

                readFromFile(dataInt, dataFloat);

                break;
            }

            case 4:
            {
                firstMenu = false;
                break;
            }
        }
    }
}

void Menu::readFromFile(Data<int> dataInt, Data<float> dataFloat)
{
    int size;

    std::cout << "Enter file name: ";
    std::cin >> filename;

    std::ifstream file(filename);

    std::getline(file, stringTmp);

    size = stoi(stringTmp);

    std::getline(file, stringTmp);

    if (getType(filename) == 0)
    {
        dataFloat.freeDynamicArray();
        dataInt.resize(size);
        dataInt.setValue(0, stoi(stringTmp));
        tmp = 1;

        while (getline(file, stringTmp))
        {
            dataInt.setValue(tmp, stoi(stringTmp));
            tmp++;
        }

        secondMenu = true;
        showSecondMenuInt(dataInt);

        file.close();
    } else
    {
        dataInt.freeDynamicArray();
        dataFloat.resize(size);
        dataFloat.setValue(0, stof(stringTmp));
        tmp = 1;

        while (getline(file, stringTmp))
        {
            dataFloat.setValue(tmp, stof(stringTmp));
            tmp++;
        }

        secondMenu = true;
        showSecondMenuFloat(dataFloat);

        file.close();
    }
}

int Menu::getType(std::string filename)
{
    std::string stringTmp;

    std::ifstream file(filename);

    getline(file, stringTmp);

    while (getline(file, stringTmp))
    {
        for (int i = 0; i < stringTmp.length(); ++i)
        {
            if (stringTmp[i] == '.') return 1;
        }
    }

    file.close();
    return 0;
}


void Menu::chooseMenuVariable()
{
    std::cout << "I choose:";
    std::cin >> variableMenu;
}

void Menu::showTextLengthOfArray()
{
    std::cout << "Choose length of array" << std::endl <<
              "1. 1000" << std::endl <<
              "2. 2000" << std::endl <<
              "3. 5000" << std::endl <<
              "4. 10000" << std::endl <<
              "5. 20000" << std::endl <<
              "6. 50000" << std::endl <<
              "7. 100000" << std::endl;
}

void Menu::chooseArrayLength()
{
    std::cout << "I choose:";
    std::cin >> arrayLength;
}

int Menu::convertInputToSize(int arrayLength)
{
    switch (arrayLength)
    {
        case 1:
            return 1000;
        case 2:
            return 2000;
        case 3:
            return 5000;
        case 4:
            return 10000;
        case 5:
            return 20000;
        case 6:
            return 50000;
        case 7:
            return 100000;
        default:
            return -1;
    }
}

void Menu::setRepeatNumber(int variable)
{
    repeatNumber = variable;
}

void Menu::showRepeatNumberText()
{
    std::cout << "Enter repeat times: " << std::endl;
}

void Menu::showSecondMenuInt(Data<int> dataInt)
{
    while (secondMenu)
    {
        showTextSecondMenu();
        chooseMenuVariable();

        while (!checkVariable(1, 8, variableMenu))
        {
            std::cout << "wrong input, please write one more time" << std::endl;
            showTextSecondMenu();
            chooseMenuVariable();
        }

        switch (variableMenu)
        {
            case 1:
            {
                showRepeatNumberText();
                std::cin >> tmp;
                setRepeatNumber(tmp);
                break;
            }
            case 2:
            {
                dataInt.printArray();
                break;
            }
            case 3:
            {
                writingMode = !writingMode;
                break;
            }
            case 4:
            {
                InsertSortNotBinary(writingMode, dataInt, repeatNumber);
                break;
            }
            case 5:
            {
                InsertSortBinary(writingMode, dataInt, repeatNumber);
                break;
            }
            case 6:
            {
                HeapSort(writingMode, dataInt, repeatNumber);
                break;
            }
            case 7:
            {
                QuickSort(writingMode, dataInt, repeatNumber);
                break;
            }
            case 8:
            {
                secondMenu = false;
                dataInt.resize(0);
                dataInt.freeDynamicArray();
                break;
            }
        }
    }
}

void Menu::showSecondMenuFloat(Data<float> dataFloat)
{
    while (secondMenu)
    {
        showTextSecondMenu();
        chooseMenuVariable();

        while (!checkVariable(1, 8, variableMenu))
        {
            std::cout << "wrong input, please write one more time" << std::endl;
            showTextSecondMenu();
            chooseMenuVariable();
        }

        switch (variableMenu)
        {
            case 1:
            {
                showRepeatNumberText();
                std::cin >> tmp;
                setRepeatNumber(tmp);
                break;
            }
            case 2:
            {
                dataFloat.printArray();
                break;
            }
            case 3:
            {
                writingMode = !writingMode;
                break;
            }
            case 4:
            {
                InsertSortNotBinary(writingMode, dataFloat, repeatNumber);
                break;
            }
            case 5:
            {
                InsertSortBinary(writingMode, dataFloat, repeatNumber);
                break;
            }
            case 6:
            {
                HeapSort(writingMode, dataFloat, repeatNumber);
                break;
            }
            case 7:
            {
                QuickSort(writingMode, dataFloat, repeatNumber);
                break;
            }
            case 8:
            {
                secondMenu = false;
                dataFloat.resize(0);
                dataFloat.freeDynamicArray();
                break;
            }
        }
    }
}




