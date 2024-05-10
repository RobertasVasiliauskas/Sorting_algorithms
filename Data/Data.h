#ifndef AIZO_1_DATA_H
#define AIZO_1_DATA_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <random>
#include <bits/stdc++.h>

template <typename T>
class Data
{
private:
    int SIZE; // 1000 2000 5000 10000 20000 50000 100000
    T *pointer;

public:

    /**
     * konstruktor klasy Data
     * @param size
     */
    Data(int size);

    /**
     * Funkcja zwracająca rozmiar tablicy
     * @return rozmiar tablicy
     */
    int getSize() const;

    /**
     * Funkcja, która zmienia rozmiar tablicy i kopiuje wartości z poprzedniej tablicy
     * @param newSize nowy rozmiar tablicy
     */
    void resize(int newSize);

    /**
     * Funkcja, która zwraca wartość tablicy z podanego indeksu
     * @param index indeks wartości tablicy
     * @return wartość tablicy
     */
    T getValue(int index);

    /**
     * Funkcja, która ustawia wartość pod zadanym indeksem
     * @param index indeks do wstawienia wartości
     * @param value wartość, którą chcemy wstawić
     */
    void setValue(int index, T value);

    /**
     * Funkcja, która wypełnia tablice pseudo-przypadkowymi wartościami
     */
    void fillArrayWithRandomNumbers();

    /**
     * Funkcja, która zwalnia pamięć
     */
    void freeDynamicArray();

    /**
     * Funkcja, która zamienia dwie wartości z podanych indeksów
     * @param indexOne indeks pierwszej wartości
     * @param indexTwo indeks drugiej wartości
     */
    void swapValues(int indexOne, int indexTwo);

    /**
     * Funkcja, która wyświetla tablice
     */
    void printArray();

    /**
     * Funkcja, która sprawdza czy tablica jest posortowana
     * @return prawda, jeżeli posortowana
     */
    bool isSorted();
};


template
class Data<int>;

template
class Data<float>;

#endif //AIZO_1_DATA_H
