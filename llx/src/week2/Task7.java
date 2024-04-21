package week2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;
enum Color {
    RED(1),
    GREEN(2),
    BLUE(3);
    int type;

    Color(int _type) {
        this.type = _type;
    }

    public static class Task7 {
        public static void main(String[] args) {
            ArrayList<Color> list = new ArrayList<>();
            for (int i = 1; i <= 5; i++) {
                Collections.addAll(list, Color.values());
            }
            Random r = new Random(1234567);
//            Random r = new Random(1234567);
            Collections.shuffle(list, r);
            for (int i = 0; i < list.size(); i++) {
                Color c = list.get(i);
                switch (c) {
                    case RED:
                    System.out.print(c.RED.type);
                    break;
                    case BLUE:
                        System.out.print(c.BLUE.type );
                        break;
                    case GREEN:
                        System.out.print(c.GREEN.type );
                        break;
                    default:
                        System.out.print("UNKNOWN ");
                }
            }
        }
    }
}

