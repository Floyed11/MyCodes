package week2;

import java.util.Arrays;
import java.util.Random;
class Fish implements Comparable<Fish> {
    int size;

    public Fish() {
        Random r = new Random();
        this.size = r.nextInt(100);
    }

    void print() {
        System.out.print(this.size + " < ");
    }

    @Override
    public int compareTo(Fish other) {
        return this.size - other.size;
    }
}

public class Task2 {
    public static void main(String[] args) {
        Fish[] fishes = new Fish[10];

        // 初始化10个 Fish 对象并放入数组
        for (int i = 0; i < 10; i++) {
            fishes[i] = new Fish();
        }

        // 对 Fish 对象数组按照 size 属性进行排序
        Arrays.sort(fishes);

        // 打印排序后的结果
        for (Fish fish : fishes) {
            fish.print();
        }
    }
}
