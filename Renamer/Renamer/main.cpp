//
//  main.cpp
//  Renamer
//
//  Created by Anas Saeed on 18/01/2016.
//  Copyright © 2016 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include<dirent.h>
#include<stdio.h>
#include <cstdio>
int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::vector<std::string> filesToRead;
    int base = 0;
    std::string identifier = "m";
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
    std::string filename = "";
    for ( auto x: filesToRead) {
        char from[50];
        strcpy(from, x.c_str());
        filename = identifier + std::to_string(base++) + ".jpg";
        char to[50];
        strcpy(to, filename.c_str());
        std::rename(from, to);
    }
    
    return 0;
}
