####################### 数据变量和常量#######################
## 实验目的：体验变量和常量
## 知识点：变量的内存实质
##        欢迎大家破坏性测试：）       
## email:ppu@cc.ecnu.edu.cn
## update:2022-10-8
###########################################################
print("###############start############"); 
print("1's memory location",id(1))
#数据变量
#num  #未赋值的变量，在引用的时候并会报错
#print(num)   
num=1  #赋值语句，注意=和数学中=的差异
print("My favorite number is %s because it is first.\n",num)
print("num's memory location",id(num),"num's type",type(num),"\n")
#体验变量不同，值相同的实质,对于基本数据类型体现了不可变
a=1
b1=a
b2=a
print("b1:",b1,"b2:",b2,"\n")
a=2
print("b1:",b1,"b2:",b2,"\n")
#体验变量值修改后，常量的地址不变
num=2
print("1's memory location",id(1))
print("num's memory location", id(num), "num's type", type(num), "\n")
#体验内存删除后,下面不注释会报异常错误
#del num
print("num's memory location",id(num))
print("2's memory location",id(2))
#变量可以跨类型修改
num="hello world!"
#多变量赋值
ming,xing='zhang','fei'
#Python优雅 swap
ming,xing=xing,ming
print("xingming:",xing,ming)
# Number数据类型的不同进制使用方法
# Output: 107
print("2#:",0b1101011)
# Output: 253 (251 + 2)
print("16#:",0xFB + 0b10)
# Output: 13
print("8#:",0o15)
#体验特殊的数据类型字符串
a='a'
#print(a+1) 该句话是错误的，数据类型不一致
print(a*28)
#体验布尔类型,真假李逵
ligui="True"
likui=True
print("typeof ligui",type(ligui),"typeof likui",type(likui))