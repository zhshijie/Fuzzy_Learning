//
//  FuzzyTerm.h
//  Fuzzy
//
//  Created by 张世杰 on 15/4/29.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#ifndef __Fuzzy__FuzzyTerm__
#define __Fuzzy__FuzzyTerm__

#include <stdio.h>


class FuzzyTerm {
    
public:
    virtual ~FuzzyTerm(){};
    //所有条件必须实现一个虚构造函数
    virtual FuzzyTerm* Clone()const = 0;
    //找到这个条件的隶属度
    virtual double GetDOM()const = 0;
    //清除这个条件的隶属度
    virtual void ClearDOM() = 0;
    //当满足一条规则时，用于更新后果的隶属度方法
    virtual void ORwithDOM(double val) = 0;
};

#endif /* defined(__Fuzzy__FuzzyTerm__) */
