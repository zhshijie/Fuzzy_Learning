//
//  FuzzyVariable.cpp
//  Fuzzy
//
//  Created by 张世杰 on 15/4/29.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#include "FuzzyVariable.h"
#include "FzSet.h"
#include <cassert>

FuzzyVariable::~FuzzyVariable()
{
    MemberSets::iterator it;
    for (it = m_MemberSets.begin(); it != m_MemberSets.end(); it++) {
        delete it->second;
    }
}


//模糊化一个值，要通过计算它在这个变量的子集中的隶属度
void FuzzyVariable::Fuzzify(double val)
{
    assert(val>=m_dMinRange&&val<= m_dMaxRange&&"<FuzzyVariable::Fuzzify>: value out of range");
    
    MemberSets::iterator it;
    for (it = m_MemberSets.begin(); it!=m_MemberSets.end(); ++it) {
        
       it->second->SetDOM( it->second->CalculateDOM(val));
    }
}






//使用最大值平均的方法对这个变量去模糊化
double FuzzyVariable:: DeFuzzifyMaxAv()const{
    double bottom = 0.0;
    double top = 0.0;
    
    MemberSets::const_iterator it;
    for (it = m_MemberSets.begin(); it!=m_MemberSets.end(); it++) {
        bottom += it->second->GetDOM();
        
        top += it->second->GetRepresentativeVal() * it->second->GetDOM();
    }
    
    if (bottom == 0) {
        return 0.0;
    }
    
    return  top/bottom;
}
//用中心法对这个变量去模糊化
double FuzzyVariable:: DeFuzzifyCentroid(int NumSamples)const
{
    double StepSize = (m_dMaxRange-m_dMinRange)/NumSamples;
    double TotalArea = 0.0;
    double SumOfMoments = 0.0;
    for (int samp=1; samp<=NumSamples; ++samp)
    {
        //for each set get the contribution to the area. This is the lower of the
        //value returned from CalculateDOM or the actual DOM of the fuzzified
        //value itself
        MemberSets::const_iterator curSet = m_MemberSets.begin();
        for (; curSet != m_MemberSets.end(); ++curSet)
        {
            double contribution =
            curSet->second->CalculateDOM(m_dMinRange + samp * StepSize)<
            curSet->second->GetDOM()?curSet->second->CalculateDOM(m_dMinRange + samp * StepSize):curSet->second->GetDOM();
            
            TotalArea += contribution;
            
            SumOfMoments += (m_dMinRange + samp * StepSize)  * contribution;
        }
    }
    if (TotalArea == 0) {
        return 0.0;
    }
    
    return SumOfMoments/TotalArea;
}

FzSet FuzzyVariable::AddLeftShoulderSet(std::string name,
                         double minBound,
                         double peak,
                         double maxBound)
{
    m_MemberSets[name] = new FuzzySet_LeftShoulder(peak,
                                               peak-minBound,
                                               maxBound-peak);
    //adjust range if necessary
    AdjustRangeToFit(minBound, maxBound);
    
    return FzSet(*m_MemberSets[name]);

   }
FzSet FuzzyVariable::AddRightShoulderSet(std::string name,
                          double minBound,
                          double peak,
                          double maxBound)
{
    m_MemberSets[name] = new FuzzySet_RightShoulder(peak,peak-minBound,maxBound-peak);
    AdjustRangeToFit(minBound, maxBound);
    return FzSet(*m_MemberSets[name]);
}

FzSet FuzzyVariable::AddTriangularSet(std::string name,
                                      double       minBound,
                                      double       peak,
                                      double       maxBound)
{
    m_MemberSets[name] = new FuzzySet_Triangle(peak,
                                               peak-minBound,
                                               maxBound-peak);
    //adjust range if necessary
    AdjustRangeToFit(minBound, maxBound);
    
    return FzSet(*m_MemberSets[name]);
}


void FuzzyVariable::AdjustRangeToFit(double minBound, double maxBound)
{
    if (minBound < m_dMinRange) m_dMinRange = minBound;
    if (maxBound > m_dMaxRange) m_dMaxRange = maxBound;
}




