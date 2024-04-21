package week4;

public class PlusMinus{

    public volatile int num;
//    synchronized (num){

        public synchronized void plusOne () {
        num = num + 1;
    }
        public  synchronized void minOne () {
        num = num - 1;
    }
        public  synchronized int printNum () {
        return num;
    }
    }
//}
