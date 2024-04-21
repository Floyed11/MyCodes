package week4;

public class Task1 {
    public static void main(String[] args) {
        PlusMinus PlusMinus = new PlusMinus();
        PlusMinus.num = 1000;
        int threadNum = 1000;
        Thread[] plusThread = new Thread[threadNum];
        Thread[] minThread = new Thread[threadNum];
        for(int i = 0 ;i< threadNum;i++)
        {
            Thread Thread1 = new Thread(() -> {
                try {
                    Thread.sleep (1000);
                }catch (InterruptedException e){
                    e.printStackTrace();
                }
//                synchronized (PlusMinus){
//// 此处的代码只有线程占用了 object1 之后才可以运行
//                    PlusMinus.minOne();
//                }
                PlusMinus.minOne();
            });
            Thread Thread2 = new Thread(() -> {
                try {
                    Thread.sleep (1000);
                }catch (InterruptedException e){
                    e.printStackTrace();
                }
//                synchronized (PlusMinus){
//                    // 此处的代码只有线程占用了 object1 之后才可以运行
//                    PlusMinus.plusOne();
//                }
                PlusMinus.plusOne();
            });
            Thread1.start();
            Thread2.start();
            plusThread[i] = Thread1;
            minThread[i] = Thread2;

        }
        for(Thread thread :plusThread){
            try{
                thread.join();
            }catch (InterruptedException e){
                e.printStackTrace();
            }
        }
//        week4.PlusMinus plusMinus = null;
        System.out.println("所有线程结束后的num值："+ PlusMinus.printNum());

    }
}
