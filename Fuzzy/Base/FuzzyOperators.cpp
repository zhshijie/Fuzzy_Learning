//
//  FuzzyOperators.cpp
//  Fuzzy
//
//  Created by 张世杰 on 15/4/29.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#include "FuzzyOperators.h"


/*
 * 进行 “与” 运输
 */


//析构函数
FzAND::~FzAND()
{
    std::vector<FuzzyTerm*>::const_iterator curTerm;
    for (curTerm = m_Terms.begin();curTerm!= m_Terms.end(); ++curTerm) {
        delete *curTerm;
    }
}

//复制
FzAND::FzAND(const FzAND& fa)
{
    std::vector<FuzzyTerm*>::const_iterator curTerm;
    for (curTerm = m_Terms.begin(); curTerm != m_Terms.end();++curTerm )
    {
        m_Terms.push_back((*curTerm)->Clone());
    }
}

//构造函数
FzAND::FzAND(FuzzyTerm& op1,FuzzyTerm&op2)
{
    m_Terms.push_back(op1.Clone());
    m_Terms.push_back(op2.Clone());
}


FzAND::FzAND(FuzzyTerm& op1,FuzzyTerm& op2,FuzzyTerm& op3)
{
    m_Terms.push_back(op1.Clone());
    m_Terms.push_back(op2.Clone());
    m_Terms.push_back(op3.Clone());
}

FzAND::FzAND(FuzzyTerm& op1,FuzzyTerm& op2,FuzzyTerm& op3,FuzzyTerm& op4)
{
    m_Terms.push_back(op1.Clone());
    m_Terms.push_back(op2.Clone());
    m_Terms.push_back(op3.Clone());
    m_Terms.push_back(op4.Clone());
}



//获得隶属值
double FzAND::GetDOM()const
{
    double minDOM = 1000;

    std::vector<FuzzyTerm*>::const_iterator curTerm;
    for (curTerm = m_Terms.begin(); curTerm!=m_Terms.end(); ++curTerm) {
        if ((*curTerm)->GetDOM()<minDOM) {
            minDOM = (*curTerm)->GetDOM();
        }
    }
    return minDOM;
}

void FzAND:: ClearDOM()
{
    std::vector<FuzzyTerm*>::const_iterator curTerm;
    for (curTerm = m_Terms.begin(); curTerm!=m_Terms.end(); ++curTerm) {
             (*curTerm)->ClearDOM();
    }
}
void FzAND::ORwithDOM(double val){
    std::vector<FuzzyTerm*>::const_iterator curTerm;
    for (curTerm = m_Terms.begin(); curTerm!=m_Terms.end(); ++curTerm) {
        (*curTerm)->ORwithDOM(val);
    }
}






