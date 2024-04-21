package week3;
//Task2: 通过实现 Runnable 接口的方式编写两个线程，一个线程负责打印字母，另一个线程负责打印数
//字，两个线程同时进行打印，要求打印出来的结果的形式为 a1b23c456d7891……z……（数字1-9循环2
//次）。将关键代码和总结的内容写到实验报告中
public class Task2 implements Runnable{
    public static void main(String[] args) {
        Task2 thread = new Task2();
        Thread thread1 = new Thread(thread,"线程一");
        Thread thread2 = new Thread(thread,"线程二");
        thread1.start();
        thread2.start();
    }

    @Override
    public void run() {
        if (Thread.currentThread().getName()=="线程一") {
            for (char i = 'a'; i <= 'z'; i++) {
                System.out.print(i);
            }
        }
        if (Thread.currentThread().getName()=="线程二") {
            for (int i = 0; i <= 9; i++) {
                System.out.print(i);
            }
            for (int i = 0; i <= 9; i++) {
                System.out.print(i);
            }
        }
    }
}
