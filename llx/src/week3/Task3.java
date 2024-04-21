package week3;

import java.util.Objects;

//Task3: 完善代码，用 join 方法该写 ThreadTest03 类实现正常的逻辑，并将关键代码和结果写到实验报告
//中。
public class Task3 implements Runnable {
    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName());
    }

    public static void main(String[] args) throws InterruptedException {
        Task3 join = new Task3();
        Thread thread1 = new Thread(join, "上课铃响");
        Thread thread2 = new Thread(join, "老师上课");
        Thread thread3 = new Thread(join, "下课铃响");
        Thread thread4 = new Thread(join, "老师下课");
//        thread1.start();
//        thread2.start();
//        thread3.start();
//        thread4.start();
//        if (Objects.equals(Thread.currentThread().getName(), "老师上课")){
//            thread2.join();
//        }
//        if (Objects.equals(Thread.currentThread().getName(), "老师下课")){
//            thread4.join();
//        }
        thread1.start();
        thread1.join(); // 等待thread1执行完成
        thread2.start();
        thread2.join(); // 等待thread2执行完成
        thread3.start();
        thread3.join(); // 等待thread3执行完成
        thread4.start();

    }
}