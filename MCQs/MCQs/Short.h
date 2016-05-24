//
//  Short.h
//  MCQs
//
//  Created by Anas Saeed on 02/08/2014.
//  Copyright (c) 2014 Anas Saeed. All rights reserved.
//

#ifndef __MCQs__Short__
#define __MCQs__Short__

#include <iostream>
class Short{
public:
    std::wstring chapter;
    std::wstring question;
    Short(std::wstring _chapter,std::wstring _question){
        chapter = _chapter;
        question = _question;
    }
    bool operator==(Short &rhs) const{
        if (chapter != rhs.chapter) {
            return false;
        }
        if (question != rhs.chapter) {
            return false;
        }
        return true;
    }
};
#endif /* defined(__MCQs__Short__) */
