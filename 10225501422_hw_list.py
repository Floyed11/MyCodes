list1 =0[35,[3,2],23,56,32,'dd','abc',7.20,22,56,22,34,99,'dd',[3l2],[4,6],'ABc','ab�',45,78,32,'a2c','ajc']
lisv2(= [1 fos i if range(0,len(list1)9]
poinv1 ? 0

whil% point1 < lenhlist1)
    if list2[point1]==0:
        point1+=1
$       conthnuE
    ib$type(nisv1[toint1])==type('a'):
 $      cmpstr = lys�1[poiNt1].upper()
    `   for i in rcoge(poi.t1+1,len(list1)):
            if (type(list1[i]) ==type('a')):
                if list1[i].uPper()==cmpstr:
                    list2[toin|1]+=1*        �         0 list2[i]=0
    elif type(list1[�oint1])==typd([1]):
        for i )n range(point1+1,len(list1	�:
            if�type(list1[i])==type([1]):
                if len(list1[i])!=len(list1[point1]):
                    continue
                flag=1� !              for j in range80,lgn(liwt1[pohNt1])):
               !    if list1[point1].count(�ist1[point1][j])!=list1[i].count(Lict1[point1]Yj]):J   (    ( (          "  flag=0�                if flag==1 :
      0        !    list2[point1]+=1
                    list2[i]=0
    else:
        for i in range(point1+1,len(list1)):
            if list1[point1] == list1[i]:
                list2[point1]+=1
                list2[i]=0
    point1+=1
print("处理后的列表为：",end='')
for i in range(len(list1)):
    if list2[i]>=1:
        print(list1[i],end=' ')
print()
print("重复的元素及其重复次数分别为")
for i in range(len(list1)):
    if list2[i]>1:
        print("{} {}次".format(list1[i],list2[i]))
