/*
    brief: 字符串相乘 golang版本
    time: 20190312
    tips:
*/

package main

import (
    "fmt"
)

func ReverseString(s string) string {
    if("" == s){
        return ""
    }
    sb := []byte(s)
    for i, j := 0, len(sb) - 1; i < j; i, j = i + 1, j - 1 {
        sb[i], sb[j] = sb[j], sb[i]
    }
    return string(sb)
}

func GetFac(s1, s2 string) string{
    // check param
    if "" == s1 || "0" == s1 || "" == s2 || "0" == s2{
        return "0"      
    }

    // 符号
    isNeg := false
    if '-' == s1[0] && '-' != s2[0] || '-' == s2[0] && '-' != s1[0]{
        isNeg = true
    }

    // reverse
    s1 = ReverseString(s1)
    s2 = ReverseString(s2)

    // 相乘
    resArray := make([]int, len(s1)+len(s2))
    for i := 0; i < len(s1); i ++ {
        if '+' == s1[i] || '-' == s1[i] {
            break
        }
        f1 := int(s1[i] - '0')
        for j := 0; j < len(s2); j ++ {
            if '+' == s2[j] || '-' == s2[j] {
                break;
            }
            resArray[i + j] += int(s2[j] - '0') * f1
        }
    }

    // 处理最后结果
    resString := make([]byte, len(resArray))
    carry := 0
    for index, val := range resArray {
        val += carry
        if val >= 10 {
            carry = val / 10
            val %= 10
        }else{
            carry = 0
        }
        resString[index] = byte(val + '0')
    }

    // 最后整理
    i := len(resString) - 1
    for ; i >= 0; i-- {
        if resString[i] != '0' {
            break
        }
    }
    if isNeg {
        i++
        resString[i] = '-'
    }
    
    return ReverseString(string(resString[0 : i+1]));
}

func main(){
    var s1, s2 string
    for{
        fmt.Scanf("%s", &s1)
        fmt.Scanf("%s", &s2)
    
        resString := GetFac(s1, s2)
        fmt.Printf("factor:%s\n", resString)
    }
    
}
