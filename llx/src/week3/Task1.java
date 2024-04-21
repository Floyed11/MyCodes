package week3;
// Task1: 改写类中的 run() 方法，将每个线程的 ID 也打印出来，代码及运行结果写到实验报告中。
public class Task1 {
    public static void main (String[] Args) {
        ThreadTest01 Test01 = new ThreadTest01();
        ThreadTest01 Test02 = new ThreadTest01();
        ThreadTest01 Test03 = new ThreadTest01();
        Test01.start();
        Test02.start();
        Test03.start();
    }
}
class ThreadTest01 extends Thread {
    @Override
    public void run() {
        System.out.println(Thread.currentThread().threadId());
    }
}


