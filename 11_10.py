list1=[21,4,'a','bgh',88,67,32,55,44,100,33,22]
l=len(list1)
for i in list1:
    if type(i) != int:
        list1.remove(i)
print(list1)