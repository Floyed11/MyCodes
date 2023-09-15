count=0
flag=0
for i in range(0,36):
    for j in range(0,36):
        count+=1
        if (i+j>35)or(i*2+j*4>94):
            break
        if (i+j==35) and (i*2+j*4==94):
            print("鸡有%d, 兔有%d" %(i,j))
            flag=1
            break
    if flag==1 :break
print( "times:",count)