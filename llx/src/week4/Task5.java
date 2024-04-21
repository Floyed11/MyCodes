package week4;

class PlusMinus04{
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
public class Task5{
    public static void main(String[] args){
        PlusMinus04 plusMinus = new PlusMinus04();
        plusMinus.num = 1000;
        Thread thread1 = new Thread(){
            @Override
            public void run(){
                while (true){
                    if(plusMinus.num == 1){
                        continue;
                    }
                    plusMinus.minusOne();
                    try {
                        sleep(10);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }}
            }};
        thread1.start();
        Thread thread2 = new Thread(){
            @Override
            public void run(){
                while (true){
                    plusMinus.plusOne();
                    try {
                        sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }}
            }};
        thread2.start();
    }}
