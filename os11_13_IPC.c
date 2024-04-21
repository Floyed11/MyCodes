/* 方案一：使用互斥锁保护一个记录叉子是否被使用的变量，
 * 每当一个哲学家想要就餐时，检查两边的叉子是否没有被使用。
 * 如果两边的都空闲，那么就拿起叉子。
 */

#define semaphore int
#define N 5
#define LEFT (i + 4) % N
#define RIGHT (i + 1) % N

semaphore mutex = 0;
int forks[5] = {0, 0, 0, 0, 0}; 
void philosopher(int i)
{
    while (1)
    {
        think();            
        P(mutex);
        if (forks[LEFT] == 0 && forks[RIGHT] == 0){
            forks[LEFT] = 1;
            forks[RIGHT] = 1;
            V(mutex);
            eat();
            P(mutex);
            forks[LEFT] = 0;
            forks[RIGHT] = 0;
        }     
        V(mutex);     
    }
}

/* 方案二：1～4号哲学家都先拿起左边的叉子，再拿起右边的叉子。放下时
* 则相反，先放下右边的叉子，再放下左边的叉子。5号哲学家则相反，先拿起
* 右边的叉子，再拿起左边的叉子。放下时则相反，先放下左边的叉子，再放下
* 右边的叉子。
 */

semaphore flag[5] = {0, 0, 0, 0, 0};

void philosopher(int i)
{
    while (1)
    {
        if (i == 4){
            P(flag[RIGHT]);
            P(flag[LEFT]);
            eat();
            V(flag[LEFT]);
            V(flag[RIGHT]);
        }
        else {
            P(flag[LEFT]);
            P(flag[RIGHT]);
            eat();
            V(flag[RIGHT]);
            V(flag[LEFT]);
        }
    }
}