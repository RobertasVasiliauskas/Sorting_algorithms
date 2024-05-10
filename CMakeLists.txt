cmake_minimum_required(VERSION 3.27)
project(AIZO_1)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")
set(SOURCE_FILES main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(AIZO_1 Menu/main.cpp
        Sort/Sort.cpp
        Sort/Sort.h
        Data/Data.cpp
        Data/Data.h
        Menu/Menu.cpp
        Menu/Menu.h
        Sort/DifferentSorts/InsertSortNotBinary/InsertSortNotBinary.cpp
        Sort/DifferentSorts/InsertSortNotBinary/InsertSortNotBinary.h
        Sort/DifferentSorts/QuickSort/QuickSort.cpp
        Sort/DifferentSorts/QuickSort/QuickSort.h
        Sort/DifferentSorts/InsertionSortBinary/InsertionSortBinary.cpp
        Sort/DifferentSorts/InsertionSortBinary/InsertionSortBinary.h
        Sort/DifferentSorts/HeapSort/HeapSort.cpp
        Sort/DifferentSorts/HeapSort/HeapSort.h
)
