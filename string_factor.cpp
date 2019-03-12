/*
    brief: 字符串相乘
    time: 20190312
    tips:
*/

#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <iostream>

std::string GetFac(const std::string &s1, const std::string &s2)
{
    // check param
    if(s1.empty() || "0" == s1 || s2.empty() || "0" == s2)
    {
        return "0";        
    }

    // reverse
    std::string sF1(s1.rbegin(), s1.rend());
    std::string sF2(s2.rbegin(), s2.rend());

    // 符号
    bool isNeg = false;
    if('-' == s1[0] && '-' != s2[0] || '-' == s2[0] && '-' != s1[0])
    {
        isNeg = true;
    }

    // 相乘
    std::vector<int> viRes(s1.size() + s2.size(), 0);
    for(int i = 0; i < sF1.size(); ++i)
    {
        if(sF1[i] < '0' || sF1[i] > '9')
        {
            break;
        }
        int f1 = sF1[i] - '0';
        for(int j = 0; j < sF2.size(); ++j)
        {
            if(sF2[j] < '0' || sF2[j] > '9')
            {
                break;
            }
            viRes[i + j] += (sF2[j] - '0') * f1;
        }
    }

    // 处理最后结果
    std::string sRes = "";
    int carry = 0;
    for(int i = 0 ; i < viRes.size(); ++i)
    {
        viRes[i] += carry;
        if(viRes[i] >= 10)
        {
            carry = viRes[i] / 10;
            viRes[i] %= 10;
        }
        else
        {
            carry = 0;
        }
        sRes.push_back(viRes[i] + '0');
    }

    // 最后整理
    size_t pos = sRes.find_last_not_of("0");
    if(std::string::npos == pos)
    {
        return "0";
    }
    sRes.erase(pos + 1);
    if(isNeg)
    {
        sRes.push_back('-');
    }
    std::reverse(sRes.begin(), sRes.end());
    return sRes;
}

int main()
{
    std::string s1, s2;
    while(std::cin >> s1 >> s2)
    {
        printf("%s * %s = %s\n", s1.c_str(), s2.c_str(), GetFac(s1, s2).c_str());        
    }
}