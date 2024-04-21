package week2;

import java.util.Scanner;

public class Task8 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入月份：");
        var MonthNow = scanner.nextInt();
        System.out.print("请输入年份：");
        var YearNow  = scanner.nextInt();
        if (YearNow%4==0&&YearNow%100!=0) {
            var DayCount1 = switch (MonthNow) {

                case 1, 3, 5, 7, 8, 10, 12 -> "这个月有31天";
                case 4, 6, 9, 11 -> "这个月有30天";
                case 2 -> "这个月有29天";
                default -> throw new RuntimeException("Invaild MonthNow");
            };
            System.out.print(DayCount1);
        }
        else {
            var DayCount = switch (MonthNow) {

                case 1, 3, 5, 7, 8, 10, 12 -> "这个月有31天";
                case 4, 6, 9, 11 -> "这个月有30天";
                case 2 -> "这个月有28天";
                default -> throw new RuntimeException("Invaild MonthNow");
            };
            System.out.print(DayCount);
        }
    }
}
