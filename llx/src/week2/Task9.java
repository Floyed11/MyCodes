package week2;

//package week2;
//
//public class Task9 {
//    public static void main(String[] args) {
//        try {
//            int age = -10;
//            if (age < 0) {
//                throw new IllegalArgumentException("年龄不能为负数");
//            }
//        } catch (IllegalArgumentException e) {
//            System.out.println("捕获到非法参数异常：" + e.getMessage());
//        }
//    }
//}
//public class Task9 {
//    public static void main(String[] args) {
//        try {
//            int result = 10 / 0; // 尝试进行除零操作，导致算术异常
//            System.out.println(result);
//        } catch (ArithmeticException e) {
//            System.out.println("捕获到算术异常：" + e.getMessage());
//        }
//    }
//}
//public class Task9 {
//    public static void main(String[] args) {
//        try {
//            Object obj = "Hello";
//            Integer num = (Integer) obj; // 尝试将字符串类型转换为整数类型，导致类型转换异常
//            System.out.println(num);
//        } catch (ClassCastException e) {
//            System.out.println("捕获到类型转换异常：" + e.getMessage());
//        }
//    }
//}
//public class Task9 {
//    public static void main(String[] args) {
//        try {
//            String str = null;
//            System.out.println(str.length()); // 尝试调用空对象的方法，导致空指针异常
//        } catch (NullPointerException e) {
//            System.out.println("捕获到空指针异常：" + e.getMessage());
//        }
//    }
//}
public class Task9 {
    public static void main(String[] args) {
        try {
            int[] arr = {1, 2, 3};
            System.out.println(arr[3]); // 访问数组索引超出范围，导致数组越界异常
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("捕获到数组越界异常：" + e.getMessage());
        }
    }
}

