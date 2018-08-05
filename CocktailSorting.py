# ************************************************
# 	File：CocktailSorting.py
# 	Author:qiaoconglovelife@163.com
# 	Date:20160809
# 	LastModified Data:20160809
# 	Brief:

#       改进冒泡排序
#       改进鸡尾酒排序

# *************************************************

def BubbleSort(alist):
    n=len(alist)


    for i in range(n-1, 1, -1):
        for j in range(0, i):
            if(alist[j]>alist[j+1]):
                alist[j],alist[j+1]=alist[j+1],alist[j]
        print("[%d] ==> %s" % (n-1-i, alist))

def CocktailSorting(alist):
    n=len(alist)

    left,right=0,n-1
    is_swaped=1

    while(left<right and is_swaped):
        # 从左至右
        is_swaped=0
        for j in range(left, right-1):
            if(alist[j]>alist[j+1]):
                alist[j],alist[j+1]=alist[j+1],alist[j]
                is_swaped=1
        print("left to right ==> %s" % alist)
        right-=1
        if not (left<right and is_swaped):
            break
        
        # 从右至左
        is_swaped=0
        for j in range(right-1, left, -1):
            if(alist[j]>alist[j+1]):
                alist[j],alist[j+1]=alist[j+1],alist[j]
                is_swaped=1
        print("right to left ==> %s" % alist)








if (__name__ == '__main__'):
    alist=[9,1,2,3,4,5,6,7,8,1]
    print("before ==> %s" % alist)

    print("begin Bubble Sort========================")
    BubbleSort(alist)

    print("begin Cocktail Sort========================")
    CocktailSorting(alist)
        




