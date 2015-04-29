//
//  FuzzyModule.cpp
//  Fuzzy
//
//  Created by 张世杰 on 15/4/28.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#include "FuzzyModule.h"
#include "FuzzyTerm.h"


void FuzzyModule::AddRule(FuzzyTerm &antecedent, FuzzyTerm &consequence)
{
    m_Rules.push_back(new FuzzyRule(antecedent,consequence));
}


