//
//  main.cpp
//  FileWriter
//
//  Created by Anas Saeed on 09/02/2015.
//  Copyright (c) 2015 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <fstream>
int main(int argc, const char * argv[])
{

    std::string text = "123456789";
    int timesToWrite= 10;
    std::ofstream writer;
    writer.open("file1.txt");
    for (int i = 0;i<timesToWrite;i++){
        writer <<text << std::endl;
    }
//    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

