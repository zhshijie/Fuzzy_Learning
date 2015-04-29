//
//  FzSet.h
//  Fuzzy
//
//  Created by 张世杰 on 15/4/29.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#ifndef __Fuzzy__FzSet__
#define __Fuzzy__FzSet__

#include <stdio.h>
#include "FuzzyTerm.h"
#include "FuzzySet.h"

class FzSet:public FuzzyTerm {
private:
    friend class FzVery;
    friend class FzFairly;
private:
    FuzzySet &m_Set;
public:
    
    FzSet(FuzzySet &fs):m_Set(fs){}
    
    FuzzyTerm* Clone()const{return new FzSet(*this);}
    double     GetDOM()const {return m_Set.GetDOM();}
    void       ClearDOM(){m_Set.ClearDOM();}
    void       ORwithDOM(double val){m_Set.ORwithDOM(val);}
    
};
#endif /* defined(__Fuzzy__FzSet__) */
