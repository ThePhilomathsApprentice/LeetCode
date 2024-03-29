#include <semaphore.h>

class Foo
{
private:
    sem_t sem1;
    sem_t sem2;
    sem_t sem3;

public:
    Foo()
    {
        sem_init(&sem1, 0, 1);
        sem_init(&sem2, 0, 0);
        sem_init(&sem3, 0, 0);
    }

    void first(function<void()> printFirst)
    {
        sem_wait(&sem1);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&sem2);
    }

    void second(function<void()> printSecond)
    {
        sem_wait(&sem2);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&sem3);
    }

    void third(function<void()> printThird)
    {
        sem_wait(&sem3);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        sem_post(&sem1);
    }
};
