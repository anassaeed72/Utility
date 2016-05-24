//
//  main.cpp
//  LineCounter
//
//  Created by Anas Saeed on 03/09/2015.
//  Copyright (c) 2015 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <dirent.h>
#include <stdio.h>
int masterCountLines = 0;
int masterCountFiles = 0;
std::string fileNameFormatter(std::string fileName){
    if (fileName[0] != 47 ) {
        return fileName;
    }
    std::string realFileName;
    for (int i  =1; i < fileName.length(); i++) {
        realFileName+=fileName[i];
    }
    return  realFileName;
}
void printResultForOneFile(std::string fileName, int count){
    std::cout <<"File: " << fileName <<"  Lines: " << count<<"\n";
}
void countLinesForOneFile(std::string fileName){
    std::ifstream reader;
    reader.open(fileName);
    std::string oneLine;
    int count = 0;
    masterCountFiles++;
    while (std::getline(reader,oneLine)) {
        masterCountLines++;
        count++;
    }
    masterCountLines++;
    count++;
    printResultForOneFile(fileName,count);
}
void printMasterOutput(){
    std::cout <<"\n\n\n\n\nTotal Result\n" <<"Files:- " <<masterCountFiles << " Lines: " <<masterCountLines <<"\n";
}
bool hasDot(std::string fileName){
    for ( auto x: fileName){
        if (x =='.') {
            return true;
        }
    }
    return false;
}
bool matchesList(std::string extension){
    std::vector<std::string> approved = {"java","cpp","rb","py"};
    for ( auto x: approved){
        if (x == extension) {
            return true;
        }
    }
    return false;
}
bool isCodeFile(std::string fileName){
    std::string extension = "";
    bool add = false;
    for ( auto x: fileName){
        if (x =='.') {
            add = true;
            continue;
        }
        if (add) {
            extension+=x;
        }
    }
    return matchesList(extension);
    
}
void listFileNames(std::string directory){
    std::vector<std::string> filesToRead;
    
    DIR *pDIR;
    struct dirent *entry;
    std::string dirTemp = "./" + directory;
    const char* dir = dirTemp.c_str();
    if( (pDIR=opendir(dir)) ){
        while((entry = readdir(pDIR))){
            if( strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 ){
                std::string temp =entry->d_name;
                if ( temp == "LineCounter" || temp == "realOutput.txt") {
                    continue;
                }
                if (hasDot(temp) == false) {
                    temp = directory +"/" + temp;
                    listFileNames(temp);
                    continue;
                }
                if (isCodeFile(temp) == false) {
                    continue;
                }
                if (directory.length() !=0) {
                    temp = directory +"/" +temp;
                }
                countLinesForOneFile(fileNameFormatter(temp));
                }
        }
        closedir(pDIR);
    }
}
int main(int argc, const char * argv[]) {
    listFileNames("");
    printMasterOutput();
    return 0;
}

