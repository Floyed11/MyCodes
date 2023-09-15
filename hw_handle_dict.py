stu_score = {'zhangsan':'98.123', 'lisi':'58.456','wangwu':'67.986', 'laowang':99.22,'xiaoxia':'57.333', 'liming': 'Null', 'zhangjin':'154.213','jingsong':'-24.345','liusong':',','niuniu':'Null','lili':-13.123}
num=int(input("请输入有效数字："))

def handle_dict(dict1,number):
    dict2=dict(filter(lambda x:(type(x[1]) is int )or(type(x[1]) is float)or(x[1].count('.')==1 and x[1].split('.')[-1].isdigit())or(x[1].isdigit()),list(stu_score.items())))
    #print(list(dict2))
    for i in dict2.keys():
        dict2[i]=round(float(dict2[i]),number)
    print(dict2)

handle_dict(stu_score,num)