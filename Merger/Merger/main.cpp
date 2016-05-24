//
//  main.cpp
//  Merger
//
//  Created by Anas Saeed on 18/08/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include<dirent.h>
#include<stdio.h>
int main(int argc, const char * argv[])
{
    std::vector<std::string> filesToRead;

    DIR *pDIR;
    struct dirent *entry;
    if( (pDIR=opendir("./")) ){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                std::string temp =entry->d_name;
                if (temp == ".DS_Store" || temp == "Merger" || temp == "realOutput.txt") {
                    continue;
                }
                std::cout << temp<< "\n";
                filesToRead.push_back(temp);
            }
        }
        closedir(pDIR);
    }
    std::vector<std::string> numbers;
    for ( auto x: filesToRead) {
        std::ifstream reader;
        reader.open(x);
        std::string temp;
        char delChar = 13;
        while (std::getline(reader, temp, delChar)) {
            numbers.push_back(temp);
        }
    }
    std::sort(numbers.begin(), numbers.end());
    std::ofstream writer;
    writer.open("realOutput.txt");
    for ( auto x: numbers ) {
        writer << x << std::endl;
    }
    // insert code here...
    std::cout << "Done!\n";
    return 0;
}

