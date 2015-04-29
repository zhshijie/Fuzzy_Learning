//
//  FuzzyVariable.h
//  Fuzzy
//
//  Created by 张世杰 on 15/4/29.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#ifndef __Fuzzy__FuzzyVariable__
#define __Fuzzy__FuzzyVariable__

#include <stdio.h>
#include <map>
#include <string>
#include "FuzzySet.h"

class FzSet;

class FuzzyVariable {
private:
    typedef std::map<std::string,FuzzySet*> MemberSets;
private:
    //不允许拷贝
    FuzzyVariable(const FuzzyVariable&);
    FuzzyVariable& operator=(const FuzzyVariable&);
private:
    //这个变量范围的最小的模糊集合的一个地图
    MemberSets m_MemberSets;
    //这个变量范围的最大值和最小值
    double m_dMinRange;
    double m_dMaxRange;
    //用一个集合的最高的和最低的边界值调用这个方法，每次添加一个新集合，去相应地调整最高和最低范围值
    void AdjustRangeToFit(double min,double max);
    //当通过FuzzyModule::CreateFLV()创建一个实例的时候，客户检索对模糊变量的一个引用。为了防止客户删除实例，FuzzyVariable的自毁器被定义为私有的，FuzzyModule类被定义成友好的
    ~FuzzyVariable();
    friend class FuzzyModule;
public:
    
    FuzzyVariable():m_dMinRange(0.0),m_dMaxRange(0.0){}
    
    //以下方法创建集合的实例，以方法名来命名，并把它们添加到成员集合的地图中。每次任何类型的集合被添加到m_dMinRange，m_dMaxRange相应地被调整。所有的方法返回一个代理类，他代表创建的实例。当创建规则库的时候，这个代理集合可以被用作操作数
    FzSet AddLeftShoulderSet(std::string name,
                             double minBound,
                             double pead,
                             double maxBound);
    FzSet AddRightShoulderSet(std::string name,
                             double minBound,
                             double pead,
                             double maxBound);
    FzSet AddTriangularSet(std::string name,
                             double minBound,
                             double pead,
                             double maxBound);
    FzSet AddSingletonSet(std::string name,
                             double minBound,
                             double pead,
                             double maxBound);
    
    //模糊化一个值，要通过计算它在这个变量的子集中的隶属度
    void Fuzzify(double val);
    //使用最大值平均的方法对这个变量去模糊化
    double DeFuzzifyMaxAv()const;
    //用中心法对这个变量去模糊化
    double DeFuzzifyCentroid(int NumSamples)const;
};

#endif /* defined(__Fuzzy__FuzzyVariable__) */
