//
//  FuzzyOperators.h
//  Fuzzy
//
//  Created by 张世杰 on 15/4/29.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#ifndef __Fuzzy__FuzzyOperators__
#define __Fuzzy__FuzzyOperators__

#include <stdio.h>
#include "FuzzyTerm.h"
#include <vector>


/*
 * 进行 “与” 运输
 */

class FzAND:public FuzzyTerm{
private:
    //储存进行 ”与“运算的几个模糊变量
    std::vector<FuzzyTerm*> m_Terms;
    //不允许使用等于号赋值
    FzAND& operator=(const FzAND&);
public:
    
    ~FzAND();
    
    //复制
    FzAND(const FzAND& fa);
    
    //构造函数
    FzAND(FuzzyTerm& op1,FuzzyTerm& op2);
    FzAND(FuzzyTerm& op1,FuzzyTerm& op2,FuzzyTerm& op3);
    FzAND(FuzzyTerm& op1,FuzzyTerm& op2,FuzzyTerm& op3,FuzzyTerm& op4);
    
    FuzzyTerm* Clone()const{return new FzAND(*this);}
    
    double GetDOM()const;
    
    void ClearDOM();
    void ORwithDOM(double val);
};



#endif /* defined(__Fuzzy__FuzzyOperators__) */
