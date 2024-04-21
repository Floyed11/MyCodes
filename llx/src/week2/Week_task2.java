package week2;

import java.time.Duration;
import java.time.Instant;

// Watch 类
class Watch {
    private Instant startTime;
    private Instant endTime;

    public Instant getStartTime() {
        return startTime;
    }
//
//    public void setStartTime(Instant startTime) {
//        this.startTime = startTime;
//    }
//
    public Instant getEndTime() {
        return endTime;
    }
//
//    public void setEndTime(Instant endTime) {
//        this.endTime = endTime;
//    }

    // 开始计时
    public Instant start() {
         startTime = Instant.now();
         return startTime;
    }

    // 停止计时
    public Instant stop() {
        endTime = Instant.now();
        return endTime;
    }
}

// StopWatch 类
class StopWatch extends Watch {
        public long getElapsedTime() {
        if (getStartTime() == null || getEndTime() == null) {
            return 0; // 如果开始时间或结束时间为空，则返回0
        } else {
            return Duration.between(getStartTime(), getEndTime()).toMillis(); // 返回毫秒数
        }
    }
}

public class Week_task2{
    public static void main(String[] args) {
        StopWatch stopWatch = new StopWatch();

        // 开始计时
        Instant start = stopWatch.start();
        System.out.println("now:"+start);
        // 模拟一些操作，比如一段时间的代码执行
        try {
            Thread.sleep(2000); // 模拟代码执行 2 秒钟
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        // 停止计时
        Instant end = stopWatch.stop();
        System.out.println("now:"+end);

        // 输出流逝时间
        System.out.println(stopWatch.getElapsedTime());
    }
}

