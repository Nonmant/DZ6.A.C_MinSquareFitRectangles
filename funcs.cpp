//https://contest.yandex.ru/contest/27844/problems/C/

#include "funcs.h"
#include <bits/stdc++.h>

//! @brief Index of last false. If everything is more return 0
template<typename F1, typename F2>
unsigned long long binSearchLowerBound(F1 valueGenerate,
                           F2 valueCheck,
                                       unsigned long long left, unsigned long long right){
    while (left<right){
        unsigned long long cur = (left + right + 1)/2;
        auto value = valueGenerate(cur);
        if(valueCheck(value)){
            left = cur;
        } else {
            right = cur-1;
        }
    }
    return right;
}

unsigned long long getDiplomasNumber(int w, int h, unsigned long long side){
    unsigned long long columns = side/w;
    unsigned long long rows = side/h;
    return columns*rows;
}

void parseFile(std::istream & input, std::ostream & output){

    int w, h, n;
    input >> w >> h >> n;
    unsigned long long left = 1, right = std::max(w,h)*n;
    auto a = binSearchLowerBound(
            [&w, &h](unsigned long long side){
                return getDiplomasNumber(w,h,side);
                },
                [&n](unsigned long long number){return number < n;},
                    left, right);

    while (getDiplomasNumber(w,h,a)<n) ++a;

    output << a;
}
