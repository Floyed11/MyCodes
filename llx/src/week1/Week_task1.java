package week1;

//public class Week_task1 {
//    public static void main (String Args[]){
//        for (int i = 0 ;i < 5 ;i++)
//        {
//            for(int j = 0 ;j<=i;j++)
//            {
//                System.out.print('*');
//            }
//            System.out.print('\n');
//        }
//
//    }
//
//}
//import java.util.Arrays;
//public class Week_task1 {
//    public static void main(String[] args) {
//        int a[] = new int[] { 18, 62, 68, 82, 65, 9 };
//        System.out.println("排序之前 :");
//        System.out.println(Arrays.toString(a));
//        Arrays.sort(a);
//        System.out.println("排序之后:");
//        System.out.println(Arrays.toString(a));
//        int stem = Arrays.binarySearch(a,68);
//        System.out.println(stem);
//    }
//}
import java.util.Scanner;
import java.io.PrintWriter;
import java.util.Arrays;

public class Week_task1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        PrintWriter writer = new PrintWriter(System.out);

        writer.println("请输入10个数字:");
        //writer.flush();
        //System.out.println("请输入10个数字: ");
        // 读取输入的10个数字
        int[] numbers = new int[10];
        for (int i = 0; i < 10; i++) {
            writer.println("请输入第 " + (i + 1) + " 个数字: ");
            // writer.flush();
            //System.out.print("请输入第 " + (i + 1) + " 个数字: ");
            numbers[i] = scanner.nextInt();
        }

        // 对数字进行排序
        Arrays.sort(numbers);

        // 输出排序后的数字
        writer.println("排序后的数字为:");
        for (int number : numbers) {
            writer.print(number + " ");
            //writer.flush();
        }

        // 关闭资源
        scanner.close();
        writer.close();
    }
}