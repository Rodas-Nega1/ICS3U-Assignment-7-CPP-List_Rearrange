// Copyright (c) 2021 Rodas Nega All rights reserved.
//
// Created by: Rodas Nega
// Created on: Oct 2021
// This program uses two arrays with randomly generated numbers
//   and sorts them from least to greatest


#include <iostream>
#include <random>
#include <ctime>
#include <list>
#include <vector>


std::vector<int> RearrangeList(std::vector<int> listOfRandomNumbers1,
std::vector<int> listOfRandomNumbers2) {
    // this function finds the concatenates and sorts two arrays into one
    std::vector<int> combinedList;
    std::vector<int> mergedList;
    int minValue;
    int xValue;
    int tempVar;
    int some_counter = 0;
    int remove_counter = 0;

    // process
    for (int aSingleElement : listOfRandomNumbers1) {
        combinedList.push_back(aSingleElement);
    }
    for (int aSingleElement2 : listOfRandomNumbers2) {
        combinedList.push_back(aSingleElement2);
    }

    while (combinedList.size()) {
        minValue = combinedList.front();
        some_counter = 0;
        remove_counter = 0;
        for (int xValue : combinedList) {
            if (xValue < minValue) {
                minValue = xValue;
                remove_counter = some_counter;
            }
            some_counter++;
        }
        mergedList.push_back(minValue);
        combinedList.erase(combinedList.begin()+remove_counter);
    }

    return mergedList;
}


int main() {
    // this function uses two arrays to generate 10 random numbers
    //  from 1-100 and outputs the lists

    std::vector<int> randomGeneratedNumbers1;
    std::vector<int> randomGeneratedNumbers2;
    int numberInArray1;
    int numberInArray2;
    std::vector<int> orderedList;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 100);
    // [0, 100]


    // output
    for (int loopCounter = 0; loopCounter < 5; loopCounter++) {
        numberInArray1 = idist(rgen);
        numberInArray2 = idist(rgen);
        randomGeneratedNumbers1.push_back(numberInArray1);
        randomGeneratedNumbers2.push_back(numberInArray2);
    }

    std::cout << "When these lists concatenate: ";
    for (int listElement : randomGeneratedNumbers1) {
        std::cout << listElement << " ";
    }

    for (int listElement2 : randomGeneratedNumbers2) {
        std::cout << listElement2 << " ";
    }
    orderedList = RearrangeList(randomGeneratedNumbers1,
    randomGeneratedNumbers2);
    std::cout << "" << std::endl;
    std::cout << "\nThe smallest number is ";
    for (int listElement3 : orderedList) {
        std::cout << listElement3 << " ";
    }

    std::cout << "" << std::endl;
    std::cout << "\nDone." << std::endl;
}
