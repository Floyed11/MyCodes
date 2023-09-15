# from functools import reduce
# n=int(input('n = '))
# list0=[i for i in range(1,n+1)]
# print(reduce(lambda x,y:x+y,list0))

try:
    num=float(input("输入一个数："))
    assert num >=0
except TypeError:
    print("类型错误")
except AssertionError:
    print("输入了负数")
else:
    print("输入的是非负数")