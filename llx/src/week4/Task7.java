package week4;
class PlusMinus03 {
    volatile int num;
    public void plusOne(){
        synchronized (this){
            this.num = this.num + 1;
            printNum();
        }}
    public void minusOne() {
        synchronized (this) {
            this.num = this.num - 1;
            printNum();
        }}
    public void printNum(){
        System.out.println("num = " + this.num);
    }
}
public class Task7 {
    public static void main(String[] args){
        PlusMinus03 plusMinus = new PlusMinus03();
        plusMinus.num = 1000;
        Thread thread1 = new Thread(){
            @Override
            public void run() {
                while (true) {
                    if (plusMinus.num == 1) {
                        continue;
                    }
                    synchronized (plusMinus) {
                        plusMinus.minusOne();
                        try {
                            sleep(10);
                            plusMinus.notify();
                        } catch (InterruptedException e) {
                            e.printStackTrace();
                        }
                    }
                }
            }
            };

        Thread thread2 = new Thread(){
            @Override
            public void run() {
                while (true) {
                synchronized (plusMinus) {

                    plusMinus.plusOne();
                    try {
                        sleep(100);
                        plusMinus.wait();

                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                }
            }
            };

        thread1.start();
        thread2.start();
    }}