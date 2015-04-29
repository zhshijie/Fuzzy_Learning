//
//  main.cpp
//  Fuzzy
//
//  Created by 张世杰 on 15/4/28.
//  Copyright (c) 2015年 张世杰. All rights reserved.
//

#include <iostream>
#include "FuzzyModule.h"
#include "FuzzyVariable.h"
#include "FzSet.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    FuzzyModule fm;
    FuzzyVariable &DistToTarget = fm.CreateFLV("DistToTarget");
    
    FzSet Target_Close = DistToTarget.AddLeftShoulderSet("Target_Close", 0, 25, 150);
    FzSet Target_Mediun = DistToTarget.AddTriangularSet("Target_Mediun", 25, 150, 300);
    FzSet Target_Far = DistToTarget.AddRightShoulderSet("Target_Far", 150, 300, 500);
    
    
    

    fm.Fuzzify("DistToTarget", 25);

    double df = fm.DeFuzzify("DistToTarget", FuzzyModule::max_av);
    printf("%f",df);
    
    return 0;
}
