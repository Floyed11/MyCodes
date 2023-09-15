def qsort(arg,left,right):
    if left>=right:
        return
    cmp=arg[left]
    lp=left
    rp=right
    while lp<rp:
        while lp<rp and arg[lp]<=cmp:
            lp=lp+1
        while rp>=lp and arg[rp]>cmp:
            rp=rp-1
        if lp<rp:
            arg[lp],arg[rp]=arg[rp],arg[lp]
    arg[left],arg[rp]=arg[rp],arg[left]
    qsort(arg,left,rp-1)
    qsort(arg,rp+1,right)

a=(input("请输入待排序的数列："))
item = a.split(" ")
list0 = [int(x) for x in item]
qsort(list0,0,len(list0)-1)
print(list0)