变量 操作符 控制流程 数组 字符串 I/O 类和对象
转义字符 文档注释 /** */ java代码规范 DOS命令
相对路径 绝对路径 

变量 数据类型 编码 数据类型转换
int double char ' ' String " "

加号的拼接运算 “100”+98 一边为字符串即拼接 String 10098

数据类型 

整数 byte[1] short[2] int [4] long[8]

字符型 char[2] 

布尔型 boolean[1] true false

引用数据类型 类（String） 接口 数组

int 数字默认为int long需加l 或L
long = 1L;

float double 默认为double float 需加f或F

8.1/3 为接近2.7的数 2.6999

JAVA　API文档　
API 应用程序编程接口 （类）
包 {接口 类 异常 枚举}

类 {字段 构造方法 成员方法}
ArrayLIst类有几种方法 
先找包 Java.util 再找类 
char 英文或汉字 数字 转义字符 ‘ ’  \转义 
char 字符本质为整数 输出对应unicode 码 可以计算
字符串 双引号
存储a 码值 二进制 存储
读取相反
字符编码表 
布尔类型 boolean true false
自动类型转换 ：精度小的类型自动转换为精度大的

精度大的付给小的报错

char int long float double 

byte short int long float double

int a = 'c'; 对的
double d = 80;对的

自动转换注意事项 
1：多种类型混合计算 都变成最大精度 
2：byte short 和char之间不会自动转换
3：byte short 和char可以进行计算
4：布尔类型不参与转换
5：表达式结果是精度最大的

基本数据类型 与 字符串的 转换 
1：基本 + “ ”
2：通过基本数据类型的包装类调用parseXX方法

String s = "144";
int num1 = Integer.parseInt(s);
//Integer 类 
double num2 = Double.parseDouble(s);
Float.parseFloat(s)
确保可以转换为基本 像 “123” 
“hello”就不能转换
逻辑运算符

数组 
int a [] =new int [];
输入函数 input.nextDouble();
有默认值0 引用传递 传递地址 

int[]arr1 = {1,2,3};
int[]arr2 = arr1; arr2会影响arr1
?如何数组拷贝呢
int[]arr1 = {1,2,3};
int[]arr2 = new int [arr1.length];
for 循环 遍历输入

?如何数组反转呢
?如何数组扩容呢
myScanner,nextInt();
