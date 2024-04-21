package week3;

public class Thread01 {
    public static void main(String Args[]) throws InterruptedException {
        Cat cat = new Cat();
        cat.start();//真正开新线程的方法，主现成不会阻塞 会继续运行
        //主和子现成交替执行
        System.out.println("主线程名称" + Thread.currentThread().getName());
        for (int i = 0; i < 10; i++) {
            System.out.println(i);
           Thread.sleep(1000);
        }
    }

       static  class Cat extends Thread {
        public void run() {
            while (true) {
                int time = 0;
                System.out.println("喵喵" + (++time) + Thread.currentThread().getName());

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if (time == 80) {
                    break;
                }
            }
        }
    }
}
//cat类当作线程使用 调用start时会调用run方法
//如果直接调用run 并没有开线程
