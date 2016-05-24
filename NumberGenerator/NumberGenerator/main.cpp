//
//  main.cpp
//  NumberGenerator
//
//  Created by Anas Saeed on 16/08/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <fstream>
std::string series;
// the declarations
char single(int in);
std::string int_string(int input);
char single(int in){
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
int singlely(char in);
int string_int(std::string input);
std::string reverser(std::string in);
// the definitions
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
int string_int(std::string input){
    int out = 0;
    input = reverser(input);
    int num = 1;
    for ( auto x: input){
        out = out + singlely(x)*num;
        num = num*10;
    }
    return out;
}
std::string reverser(std::string in){
    std::string output;
    for (int i = in.length()-1; i>=0; i--) {
        output = output + in[i];
    }
    return output;
}
std::string int_string(int input){
    std::string output;
    int num = 10;
    if (input == 0) {
        return "0";
    }
    while (input >0) {
        int dummy = input%num;
        input = input/num;
        //        num = num*10;
        output = output + single(dummy);
    }
    return reverser(output);
}
std::string formating(int input){
    std::string output  = int_string(input);
    for (int i = output.length(); i < 7; i++) {
        output = "0" + output;
    }
    output = series + output;
    return output;
}
int main(int argc, const char * argv[]) {
    series ="0333";
    bool first = true;
    int numbersToWrite = 200;
        std::ifstream tempReader;
        tempReader.open("temp.txt");
        int intial = 0;
        std::string temp;
        std::getline(tempReader, temp);
        std::string temp2;
        std::getline(tempReader,temp2);
        int numbersDone = string_int(temp2);
        numbersDone = numbersDone+ numbersToWrite;
        intial = string_int(temp);
        int end = intial + numbersToWrite;
        std::string stringLengthTemp = int_string(end);
        if (stringLengthTemp.length() > 7) {
            std::cout <<"length greater please retry\n";
            return 0;
        }
        std::ofstream tempWriter;
        tempWriter.open("temp.txt");
        tempWriter << end << std::endl;
        tempWriter << numbersDone;
//        std::cout << "Numbers Done " << numbersDone << "\n ";
        std::ofstream writer;
        std::string fileName;

            fileName = "input.txt";
        writer.open(fileName);
        int counter = 0;
        for (int j = intial; j < end; j++) {
            if (counter%10 == 0 && counter > 1 ) {
                writer <<"Anas\nAnas\n";
                std::cout << formating(j) << std::endl;
            }
            counter++;
            writer << formating(j) << std::endl;
        }
        writer <<"Anas\nAnas\nSaeed";

    std::cout << "Numbers Done " << numbersDone << "\n";
    if ( numbersDone > 9000){
        for ( int i = 0;i < 100;i++)
        std::cout <<"Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert Alert \n";
    }
        std::cout << "DONE!\n";
    return 0;
}

