'''
count=0
flag=0
for i in range(0,36):
    r=35
    l=0
    for j in range(0,36):
        count+=1
        mid = (r+l)//2
        if (i+mid == 35) and (i*2+mid * 4 == 94):
            print("鸡有%d, 兔有%d" %(i,mid))
            flag=1
        if l >= r :
            break
        if (i*2+mid*4 <94):
            l = mid+1
        elif (i*2+mid*4 >=94):
            r = mid-1
    if flag==1 :break
print( "times:",count)
'''
'''
list1=[[3,2],1,2,3,[1,2]]
point1=0
for i in range(1,len(list1)):
    if type(list1[i])==type([1]):
        if len(list1[i])!=len(list1[point1]):
            flag=0
            continue
        flag=1
        for j in range(0,len(list1[point1])):
            if list1[point1].count(list1[point1][j])!=list1[i].count(list1[point1][j]):
                flag=0
print(flag)
'''
'''
str='123ABC123'
print(str.isupper()
'''
'''a=(1,2,3,6,5,4)
c = [9,8,7,'a','b','c']
b = tuple(c)
c[0] = 2
list_change=list(a)
list_change[0]=10
a=tuple(list_change)
print(b)'''
'''print(*zip([1,2,3],[4,5,6],[7,8,9]))
dict_queue={"d":0,'a':1,'s':2,'e':3}
print(dict_queue.get('d'))'''
# # s=input()
# # t=input()
# # print(s)
# for i in range(10):
#     pass
# else:
#     print("pass")


# def flag(item0):
#     value0 =list(item0)[1]
#     if type(value0) is int or type(value0) is float:
#         return True
#     if value0.count('-')>0:
#         value0=value0[1:]
#     if value0.count(".")>0:
#         list0=value0.split('.')
#         return list0[0].isdigit() and list0[1].isdigit()
#     else:
#         return value0.isdigit()

# def getkey(k):
#     if k>10:
#         return (k % 10) *(k // 10)
#     else:
#         return k%10
# list0=[1,5,7,8,13,19,20,23,29]
# dict0={}
# for i in list0:
#     dict0[getkey(i)]=i

# 0 1 2 3 4 5 6 7 8 9 --- 18
# str1 = "East China University" 
# str2 = str1[:9] + " Normal " + str1[-10:] 
# print(str2)
# vote=['鲁智深','柴进','宋江','吴用','林冲','卢俊义','柴进','柴进','孙二娘','史进','吴用','卢俊义','柴进','林冲','宋江','宋江','卢俊义','吴用','吴用']
# dict1={'鲁智深':0,'柴进':0,'宋江':0,'吴用':0,'林冲':0,'卢俊义':0,'孙二娘':0,'史进':0}
# for i in vote:
#     dict1[i]+=1
# sort_dict1=sorted(dict1.items(),key=lambda x:x[1],reverse=True)
# for i in sort_dict1:
#     print(i[0],i[1],end='')
#     print("次")
# count=0
# print(18)
# for i in range(4):
#     if i==0:continue
#     for j in range(4):
#         if i==j:continue
#         for k in range(4):
#             if k==i or k==j:continue
#             count+=1
#             print(i*100+j*10+k,end=' ')
#             if count%10==0:print()
# def hcf(x,y):
#     if x<y:
#         x,y=y,x
#     while(x % y !=0):
#         x,y=y,x%y
#     return y
# def lcd(x,y):
#     return int(x*y/hcf(x,y))
# a,b=map(int,input().split(' '))
# print(hcf(a,b),lcd(a,b))
# count=2
# dict1={0:0,1:1}
# def doit(n):
#     global count
#     if n==0:return 0
#     if n==1:return 1
#     if n in dict1.keys():return dict1[n]
#     count+=1
#     dict1[n]=doit(n-1)+doit(n-2)
#     return dict1[n]
# n=int(input())
# doit(n)
# print("fib={},count={}".format(dict1[n],count))
# print("请输入利润信息：")
# y=input()
# x=y.split('"')
# x=str(x[1])
# list1=x.split(" ")
# list2=[]
# for i in range(0,len(list1),2):
#     list2.append([list1[i],list1[i+1]])
# print("各店名和利润如下：")
# print(list2)
# ans=0
# ans_index=''
# for i in list2:
#     if i[1]>ans:
#         ans=i[1]
#         ans_index=i[0]
# a=2023  
# print(a,'\n',a,sep='')
# a=[]
# a.append([1,2])
# print(a[0])
# a.append([2,3])
# print(a[1])
import torch
from scipy.stats import norm

def create_normal_map(offset=0.9677083, use_extra_value=True):

    if use_extra_value:
        # one more positive value, this is an asymmetric type
        v1 = norm.ppf(torch.linspace(offset, 0.5, 9)[:-1]).tolist()
        v2 = [0]*(256-15) ## we have 15 non-zero values in this data type
        v3 = (-norm.ppf(torch.linspace(offset, 0.5, 8)[:-1])).tolist()
        v = v1 + v2 + v3
    else:
        v1 = norm.ppf(torch.linspace(offset, 0.5, 8)[:-1]).tolist()
        v2 = [0]*(256-14) ## we have 14 non-zero values in this data type
        v3 = (-norm.ppf(torch.linspace(offset, 0.5, 8)[:-1])).tolist()
        v = v1 + v2 + v3

    values = torch.Tensor(v)
    values = values.sort().values
    values /= values.max()
    assert values.numel() == 256
    return values

print(create_normal_map())