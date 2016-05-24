//
//  main.cpp
//  MCQs
//
//  Created by Anas Saeed on 01/08/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>
#include "MCQ.h"
#include "Short.h"
// the declarations
wchar_t single(int in);
int string_int(std::wstring input);
int singlely(char in);
std::wstring reverser(std::wstring in);
std::wstring int_string(int input);
std::vector<std::wstring> stringSplit(std::wstring);
bool included(int input);
// the global variables
std::vector<int> chaptersToInclude;


// the defintions
std::vector<std::wstring> stringSplit(std::wstring input){
    std::wstring chapter;
    std::wstring output;
    bool comma = false;
    for ( auto x: input){
        if (x == ',') {
            comma = true;
            continue;
        }
        if (comma) {
            output  = output + x;
        } else{
            chapter = chapter + x;
        }
    }
    std::vector<std::wstring> myVec;
    myVec.push_back(chapter);
    myVec.push_back(output);
    return myVec;
}
bool included(int input){
    for ( auto x : chaptersToInclude){
        if (x == input) {
            return true;
        }
    }
    return false;
}
wchar_t single(int in){
    if (in == 0) {
        return '0';
    }
    if (in == 1) {
        return '1';
    }
    if (in == 2) {
        return '2';
    }
    if (in == 3) {
        return '3';
    }
    if (in == 4) {
        return '4';
    }
    if (in == 5) {
        return '5';
    }
    if (in == 6) {
        return '6';
    }
    if (in == 7) {
        return '7';
    }
    if (in == 8) {
        return '8';
    }
    return '9';
}
int singlely(char in){
    if (in =='0') {
        return 0;
    }
    if (in =='1') {
        return 1;
    }
    if (in =='2') {
        return 2;
    }
    if (in =='3') {
        return 3;
    }
    if (in =='4') {
        return 4;
    }
    if (in =='5') {
        return 5;
    }
    if (in =='6') {
        return 6;
    }
    if (in =='7') {
        return 7;
    }
    if (in =='8') {
        return 8;
    }
    return 9;
}
std::wstring reverser(std::wstring in){
    std::wstring output;
    for (int i = in.length()-1; i>=0; i--) {
        output = output + in[i];
    }
    return output;
}
std::wstring int_string(int input){
    std::wstring output;
    int num = 10;
    if (input == 0) {
        return L"0";
    }
    while (input >0) {
        int dummy = input%num;
        input = input/num;
        //        num = num*10;
        output = output + single(dummy);
    }
    return reverser(output);
}
int string_int(std::wstring input){
    int out = 0;
    input = reverser(input);
    int num = 1;
    for ( auto x: input){
        out = out + singlely(x)*num;
        num = num*10;
    }
    return out;
}
int main(int argc, const char * argv[])
{
    std::wstring tab = L"           ";
    std::wofstream writer;
    writer.open("output.txt");
    long numberOfMCQsInDatabase = 0;
    int numberOfMCQsToAdd = 0;
    int numberOfShortsToAdd = 0;
    std::cout << "Please enter the number of MCQs to be added" << std::endl;
    std::cin >> numberOfMCQsToAdd;
    std::cout << "Please enter the number of Short Question to be added" << std::endl;
    std::cin >> numberOfShortsToAdd;

    std::vector<MCQ>databaseMCQs;
    std::wifstream reader;
    reader.open("MCQs.txt");
    
    chaptersToInclude.push_back(1);
    // for the mcqs
    wchar_t delChar = 10;
    while (true) {
        std::wstring one;
        std::wstring two;
        std::wstring three;
        std::wstring four;
        std::wstring five;
        std::wstring six;
        std::getline(reader, one,delChar);
        std::getline(reader, two,delChar);
        std::getline(reader, three,delChar);
        std::getline(reader, four,delChar);
        std::getline(reader, five,delChar);
        std::getline(reader, six,delChar);
        if (one == L"end" || two == L"end" || three == L"end" || four == L"end" || five == L"end" || six == L"end") {
//            std::cout << "here";
            break;
        }
        //std::wcout << two << "\n";
        MCQ temp(one, two, three, four, five, six);
        databaseMCQs.push_back(temp);
        numberOfMCQsInDatabase++;
    }
    std::vector<MCQ> added;
    for (int i = 0; i < numberOfMCQsToAdd; i++) {
        long index = random()% numberOfMCQsInDatabase;
//        std::cout << index << std::endl;
        MCQ temp = databaseMCQs[index];
        bool present = false;
        for (auto x: added){
            if (x == temp) {
                present = true;
            }
        }
        if ( present ) {
           // added.push_back(temp);

            i = i-1;
            continue;
        }
        added.push_back(temp);
        std::wcout << temp.question << "\n";

        writer <<tab<<int_string(i+1) <<L") "<< temp.question << std::endl;
        writer << tab  << L"    a) " << temp.firstOption << std::endl;
        writer << tab  << L"    b) " << temp.secondOption << std::endl;
        writer << tab  << L"    c) " << temp.thirdOption << std::endl;
        writer << tab  << L"    d) " << temp.fourthOption << std::endl<< std::endl << std::endl;
    }
    std::cout << "Done MCQs\n";

     //  for the short answer questions
    std::wifstream readerShort;
    readerShort.open("Short.txt");
    std::wstring temp;
    std::vector<Short> databaseShort;
    long numberOfShortsInDatabase = 0;
    while (std::getline(readerShort,temp , delChar)) {
        if (temp == L"end") {
            break;
        }
        numberOfShortsInDatabase++;
        Short toadd(stringSplit(temp)[0],stringSplit(temp)[1]);
        databaseShort.push_back(toadd);
//        std::wcout << stringSplit(temp)[0] << L" "  <<stringSplit(temp)[1] << std::endl;
    }
    writer << "The short question" << std::endl;
    std::vector<Short> addedShort;
    for (int i = 0; i < numberOfShortsToAdd; i++) {
        long index = random()% numberOfShortsInDatabase;
        Short temp = databaseShort[1];
        bool present = false;
        for ( auto x : addedShort){
            if (x == temp) {
                present = true;
            }
        }
        if (present == true) {
            i = i-1;
            continue;
        }
        writer << tab << int_string(i+1) <<L") " <<temp.question << std::endl << std::endl;
    }
    return 0;
}

