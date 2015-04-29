//
//  FuzzyModule.cpp
//  Fuzzy
//
//  Created by 张世杰 on 15/4/28.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#include "FuzzyModule.h"
#include "FuzzyTerm.h"


FuzzyModule::~FuzzyModule()
{
    VarMap::iterator curVar = m_Variables.begin();
    for (curVar; curVar != m_Variables.end(); ++curVar)
    {
        delete curVar->second;
    }
    
    std::vector<FuzzyRule*>::iterator curRule = m_Rules.begin();
    for (curRule; curRule != m_Rules.end(); ++curRule)
    {
        delete *curRule;
    }
}

void FuzzyModule::AddRule(FuzzyTerm &antecedent, FuzzyTerm &consequence)
{
    m_Rules.push_back(new FuzzyRule(antecedent,consequence));
}


FuzzyVariable& FuzzyModule::CreateFLV(const std::string& VarName)
{
   
        m_Variables[VarName] = new FuzzyVariable();;
        
        return *m_Variables[VarName];

}
