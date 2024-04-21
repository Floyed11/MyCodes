package week3;
//yield() 方法会让线程回到就绪状态，直接等到 CPU 重新分配资源，但只有优先级和该线程相等或大于该线程
//的其他线程才有机会被执行
//Task5: 完善代码，将两个线程设置为不同的优先级，并将第一个线程设置为让步状态。将关键代码和总结的
//内容写到实验报告中，并总结线程让步的特点
class MyRunnable01 implements Runnable{
    @Override
    public void run(){
        for(int i = 1; i < 100; i++){
            System.out.println("线程"+
                    Thread.currentThread().getName()
                    +"第" + i + "次执行！");
           Thread.yield();

        }}
}
class MyRunnable02 implements Runnable{
    @Override
    public void run(){
        for(int i = 1; i < 100; i++){
            System.out.println("线程"+ Thread.currentThread().getName() +"第" + i +
                    "次执行！");
        }}
}
public class Task5 {
    public static void main(String[] args) throws InterruptedException{
        Thread t1 = new Thread(new MyRunnable01(),"线程1");
        Thread t2 = new Thread(new MyRunnable02(),"线程2");
        t1.setPriority(10);
        t2.setPriority(1);
        t1.start();
        t2.start();
    }
}
