//
//  FuzzySet.cpp
//  Fuzzy
//
//  Created by 张世杰 on 15/4/28.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#include "FuzzySet.h"



//根据一个值，计算三角模糊形的隶属值
double FuzzySet_Triangle::CalculateDOM(double val)const
{
    //检查三角形左边或右边的偏移量是零的情况（以防止下面的除零错误）
    if ((m_dRightOffset == 0.0&&m_dPeakPoint == val) ||(m_dLeftOffset == 0.0&&m_dPeakPoint == val)) {
        return 1.0;
    }
    
    if ((val <= m_dPeakPoint)&&(val >=(m_dPeakPoint-m_dLeftOffset))) {
        double grad = 1.0/m_dLeftOffset;
        return  grad*(val - (m_dPeakPoint -m_dLeftOffset));
    }
    
    if ((val >=m_dPeakPoint)&&val <= m_dPeakPoint+m_dRightOffset) {
        double grad = 1.0/-m_dRightOffset;
        return grad*(val - m_dPeakPoint)+1.0;
    }
    //这个模糊语言变量的范围之外，返回值为0
    else
    {
        return 0;
    }
}



double FuzzySet_RightShoulder::CalculateDOM(double val)const
{
    //偏移值为0的情况
    if (m_dLeftOffset == 0.0&& val == m_dPeakPoint) {
        return 1.0;
    }
    
    //若是在中间的左边，寻找隶属度
    if ((val <m_dPeakPoint)&&val>=m_dPeakPoint-m_dLeftOffset) {
        double grad = 1.0/m_dLeftOffset;
        return grad*(val - (m_dPeakPoint-m_dLeftOffset));
    }
    //若在中间的右边，寻找隶属度
    else if (val>m_dPeakPoint)
    {
        return 1.0;
    }
    else{
        return 0.0;
    }
}



double FuzzySet_LeftShoulder::CalculateDOM(double val)const{
    //偏移值为0的情况
    if (m_dRightOffset == 0.0&& val == m_dPeakPoint) {
        return 1.0;
    }
    
    //若是在中间的右边，寻找隶属度
    if ((val >m_dPeakPoint)&&val<=m_dPeakPoint+m_dRightOffset) {
        double grad = -1.0/m_dRightOffset;
        return grad*(val - (m_dPeakPoint+ m_dLeftOffset)) +1;
    }
    //若在中间的右边，寻找隶属度
    else if (val<m_dPeakPoint)
    {
        return 1.0;
    }
    else{
        return 0.0;
    }

}