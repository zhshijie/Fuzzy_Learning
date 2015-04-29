//
//  FuzzyRule.h
//  Fuzzy
//
//  Created by 张世杰 on 15/4/29.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#ifndef __Fuzzy__FuzzyRule__
#define __Fuzzy__FuzzyRule__

#include <stdio.h>
#include "FuzzyTerm.h"

class FuzzyRule {
private:
    //前提条件（通常是几个模糊集合和操作符的一种组合）
    const FuzzyTerm * m_pAntecedent;
    //后果 （通常是一个单一的模糊集合，但可以是几个模糊集合一起进行与运算）
    FuzzyTerm * m_pConsequence;
    
    //不允许用户的操作
    FuzzyRule(const FuzzyRule&);
    FuzzyRule& operator = (const FuzzyRule&);
    
public:
    FuzzyRule(FuzzyTerm & ant,FuzzyTerm &con):m_pAntecedent(ant.Clone()),m_pConsequence(con.Clone()){}
    
    ~FuzzyRule(){delete m_pConsequence;delete m_pConsequence;}
    
    void SetConfidenceOfConsequentToZero(){m_pConsequence->ClearDOM();}
    
    //这个方法更新了后果条件的隶属值
    void Calculate()
    {
        m_pConsequence->ORwithDOM(m_pAntecedent->GetDOM());
    }
    
};

#endif /* defined(__Fuzzy__FuzzyRule__) */
