package week4;
public class Task3 {
    private static final Object resource1 = new Object();
    private static final Object resource2 = new Object();
    private static final Object resource3 = new Object();

    public static void main(String[] args) {
        Thread thread1 = new Thread(() -> {
            synchronized (resource1) {
                System.out.println("Thread1 正在占用resource 1...");

                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                System.out.println("Thread1 等待 resource 2...");
                synchronized (resource2) {
                    System.out.println("Thread1 正在占用 resource 1 and 2...");
                }
            }
        });

        Thread thread2 = new Thread(() -> {
            synchronized (resource2) {
                System.out.println("Thread2 正在占用 resource 2...");

                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                System.out.println("Thread2 正在等待 resource 3...");
                synchronized (resource3) {
                    System.out.println("Thread2 正在占用 resource 2 and 3...");
                }
            }
        });

        Thread thread3 = new Thread(() -> {
            synchronized (resource3) {
                System.out.println("Thread3 正在占用 resource 3...");

                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }

                System.out.println("Thread3  正在等待 resource 1...");
                synchronized (resource1) {
                    System.out.println("Thread3 正在占用 resource 1 and 3...");
                }
            }
        });

        // 启动线程
        thread1.start();
        thread2.start();
        thread3.start();
    }
}

