//
//  FuzzyModule.h
//  Fuzzy
//
//  Created by 张世杰 on 15/4/28.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#ifndef __Fuzzy__FuzzyModule__
#define __Fuzzy__FuzzyModule__

#include <stdio.h>
#include <map>
#include <string>
#include <vector>


class FuzzyVariable;
class FuzzyRule;
class FuzzyTerm;

class FuzzyModule {
    
private:
    typedef std::map<std::string, FuzzyVariable*> VarMap;
public:
    //客户必须把这些值中的其中一个传递给去模糊方法。这个模块仅仅支持最大值平均法和中心法
    enum DefuzzifyType{max_av,centroid};
    enum {NumSamplesToUseForCentroid = 15};
    
private:
    //在这个模块中用到的所有模糊变量的地图
    VarMap m_Variables;
    //一个包含所有模糊规则的变量
    std::vector<FuzzyRule*> m_Rules;
    //将每种规则的后果的隶属归零，由去模糊方法Defuzzify()使用
    inline void SetConfidencesOfConsequentsToZero();
public:
    ~FuzzyModule();
    //创建一个新的“空”模糊变量，并返回一个对它的引用
    FuzzyVariable& CreateFLV(const std::string& VarName);
    //给模块添加一个规则
    void AddRule(FuzzyTerm& antecedent,FuzzyTerm& consequence);
    //这个方法调用指定的模糊语言变量的模糊化方法
    inline void Fuzzify(const std::string& NameOfFLV,double val);
    //给定一个模糊变量和一个模糊化方法，返回一个普通值
    inline double DeFuzzify(const std::string& key,DefuzzifyType method);
};


#endif /* defined(__Fuzzy__FuzzyModule__) */
