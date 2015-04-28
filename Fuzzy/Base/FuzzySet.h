//
//  FuzzySet.h
//  Fuzzy
//
//  Created by 张世杰 on 15/4/28.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#ifndef __Fuzzy__FuzzySet__
#define __Fuzzy__FuzzySet__

#include <stdio.h>

class FuzzySet {
protected:
    //在这个集合中，将保持这个隶属度为一个给定的值
    double m_dDOM;
    //这个集合的隶属函数的最大值。例如，如果集合是三角形的，那么这将是三角形的顶点。如果这个集合是一个平台，那么这个值将是这个平台的中点。这个值是在构造函数中设置的，这样可以避免在运行时计算这个中点值。
    double m_dRepresentativeValue;
    
public:
    FuzzySet(double RepVal):m_dDOM(0.0),m_dRepresentativeValue(RepVal){}
    //返回给定值在这个集合中的隶属度。注意：这里并没有把m_dDOM设置成作为参数传递的值的隶属度。这是因为中心法这种去模糊化的方法确实作为采样点值的隶属度的。
    virtual double CalculateDOM(double val)const = 0;
    
    //如果这个模糊集合是一个结果模糊语言变量的一部分，并且它符合一条规则，那么这种方法设置隶属度参数值的最大或这个集合存在的m_dDOM值（在这个背景下，隶属度代表一种置信度水平）
    void ORwithDOM(double val);
    
    //附属方法
    double GetRepresentativeVal()const;
    void ClearDOM(){m_dDOM = 0.0;}
    double GetDOM()const {return m_dDOM;}
    void SetDOM(double val);
};

#endif /* defined(__Fuzzy__FuzzySet__) */
