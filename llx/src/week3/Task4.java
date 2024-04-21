package week3;
//任务4: 完善代码，将助教线程设置为守护线程，当同学们下课时，助教线程自动结束。并将关键代码和结果
//写到实验报告中。
//通过调用 setDaemon(true) 方法将一个线程设置为守护线程（Daemon Thread）。
// 守护线程是一种特殊类型的线程，其作用是为其他线程提供服务，它的生命周期会依赖于其他非守护线程。
// 当所有非守护线程都执行完成时，
// JVM 会自动退出，同时销毁所有守护线程。
public class Task4 implements Runnable {
    public static void main(String[] args) throws InterruptedException {
        Task4 inClassroom = new Task4();
        Thread thread = new Thread(inClassroom, "助教");
        //thread.setDaemon(true);
        thread.start();
        for (int i = 0; i < 10; i++) {
            Thread.sleep(1000);
            System.out.println("同学们正在上课");
            if (i == 9) {
                System.out.println("同学们下课了");
            }
        }
    }

    @Override
    public void run() {
        int worktime = 0;
        while (true) {
            System.out.println("助教在教室的第" + worktime + "秒");
            try {
                Thread.currentThread().sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            worktime++;
        }
    }
}
