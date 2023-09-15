string=input("输入字符串：")
up_cou=0
low_cou=0
num_cou=0
el_cou=0
for char in string:
    if char>='A' and char<='Z':
        up_cou+=1
    elif char>='a' and char<='z':
        low_cou+=1
    elif char.isdigit():
        num_cou+=1
    else:
        el_cou+=1
print("大写字母个数: {}\n小写字母个数: {}\n数字个数: {}\n其他字符个数：{}\n".format(up_cou,low_cou,num_cou,el_cou))
