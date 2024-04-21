package week2;
import java.util.Scanner;


class Employee {
    String name;
    int month;
    public Employee(String name, int month) {
        this.name = name;
        this.month = month;
    }
}
class SaleEmployee extends  Employee {

    int count;
    double rate;
    double salary;

    public SaleEmployee(String name, int month, int count, double rate, int basic) {
        super(name, month);
        this.count = count;
        this.rate = rate;

        salary = rate * count + basic;
    }
}
 class SalarieEmployee extends Employee {
    double salary;

    public SalarieEmployee(String name, int month, int salary, int month_now) {
        super(name, month);
        this.salary = salary;

        if (month_now == month) {
            salary += 100;
        }

    }
}
 class HourEmployee extends Employee {
     int salary_per_hour;
     int hour;
     int salary;

     public HourEmployee(String name, int month, int salary_per_hour, int hour) {
         super(name, month);
         this.salary_per_hour = salary_per_hour;
         this.hour = hour;
         salary = salary_per_hour * hour;

     }
 }


public class Task3 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("请输入月份：");
        int currentMonth = scanner.nextInt();
        HourEmployee HourEmployee = new HourEmployee("小红",9,15,10);
        SalarieEmployee SalarieEmployee  = new SalarieEmployee("小明",8,8000,currentMonth);
        SaleEmployee SaleEmployee = new SaleEmployee("小李",1,6000,0.15,3000);
        System.out.println(HourEmployee.salary);
        System.out.println(SaleEmployee.salary);
        System.out.println(SalarieEmployee.salary);

    }
}