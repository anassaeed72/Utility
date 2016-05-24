//
//  MCQ.h
//  MCQs
//
//  Created by Anas Saeed on 01/08/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#ifndef __MCQs__MCQ__
#define __MCQs__MCQ__

#include <iostream>
class MCQ{
public:
    std::wstring chapter;
    std::wstring question;
    std::wstring firstOption;
    std::wstring secondOption;
    std::wstring thirdOption;
    std::wstring fourthOption;
    
    MCQ(std::wstring _chapter,std::wstring _question,std::wstring _firstOption,std::wstring _secondOption,std::wstring _thirdOption,std::wstring _fourthOption){
        chapter = _chapter;
        question = _question;
        firstOption = _firstOption;
        secondOption = _secondOption;
        thirdOption = _thirdOption;
        fourthOption = _fourthOption;
    }
    bool operator==(MCQ &rhs)const{
        if (chapter != rhs.chapter) {
            return false;
        }
        if (question != rhs.question) {
            return false;
        }
        if (firstOption != rhs.firstOption) {
            return false;
        }
        if ( secondOption != rhs.secondOption){
            return false;
        }
        if (thirdOption != rhs.thirdOption) {
            return false;
        }
        if (fourthOption != rhs.fourthOption) {
            return false;
        }
        return true;
    }
};
#endif /* defined(__MCQs__MCQ__) */
