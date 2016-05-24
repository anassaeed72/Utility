//
//  main.cpp
//  DuplicateRemover
//
//  Created by Anas Saeed on 16/08/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#include <iostream>
#include <fstream>
#include<algorithm>
#include <map>
#include <vector>
struct target_less
{
    template<class It>
    bool operator()(It const &a, It const &b) const { return *a < *b; }
};
struct target_equal
{
    template<class It>
    bool operator()(It const &a, It const &b) const { return *a == *b; }
};
template<class It> It uniquify(It begin, It const end)
{
    std::vector<It> v;
    v.reserve(static_cast<size_t>(std::distance(begin, end)));
    for (It i = begin; i != end; ++i)
    { v.push_back(i); }
    std::sort(v.begin(), v.end(), target_less());
    v.erase(std::unique(v.begin(), v.end(), target_equal()), v.end());
    std::sort(v.begin(), v.end());
    size_t j = 0;
    for (It i = begin; i != end && j != v.size(); ++i)
    {
        if (i == v[j])
        {
            using std::iter_swap; iter_swap(i, begin);
            ++j;
            ++begin;
        }
    }
    return begin;
}
int main(int argc, const char * argv[])
{
    std::ifstream reader;
    reader.open("output.txt");
    std::string temp;
    char delChar = 13;
    std::map<std::string,int> duplicateDatabase;
    std::map<std::string,int>::iterator duplicateDatabaseIterator;

    std::ofstream writer;
    writer.open("realOutput.txt");
    int lines_done = 0;
    std::vector<std::string> database;
    while (std::getline(reader, temp)) {
        database.push_back(temp);
        
    }
    database.erase(uniquify(database.begin(), database.end()), database.end());

    for (int i = 0; i < database.size(); i++) {
        std::cout << database[i] << std::endl;
        writer << database[i] << std::endl;
    }
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

