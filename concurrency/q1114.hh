//
// Created by Helianthus Xie on 2022/5/14.
//

#ifndef LEETCODE_Q1114_HH
#define LEETCODE_Q1114_HH

class Foo {
public:
    Foo()
    {
        m_mutex1.lock();
        m_mutex2.lock();
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        m_mutex1.unlock();
    }

    void second(function<void()> printSecond)
    {
        m_mutex1.lock();
        printSecond();
        m_mutex1.unlock();
        m_mutex2.unlock();
    }

    void third(function<void()> printThird)
    {
        m_mutex2.lock();
        printThird();
        m_mutex2.unlock();
    }

private:
    std::mutex m_mutex1, m_mutex2;
};

// unique_lock, RAII
#if 0
class Foo {
public:
    Foo() : m_lock1(m_mutex1, std::try_to_lock), m_lock2(m_mutex2, std::try_to_lock)
    {
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        m_lock1.unlock();
    }

    void second(function<void()> printSecond)
    {
        std::lock_guard<std::mutex> guard(m_mutex1);
        printSecond();
        m_lock2.unlock();
    }

    void third(function<void()> printThird)
    {
        std::lock_guard<std::mutex> guard(m_mutex2);
        printThird();
    }

private:
    std::mutex m_mutex1, m_mutex2;
    std::unique_lock<std::mutex> m_lock1, m_lock2;
};
#endif

// condition_variable
#if 0
class Foo {
public:
    Foo()
    {

    }

    void first(function<void()> printFirst)
    {
        printFirst();
        m_k = 1;
        m_cv.notify_all();
    }

    void second(function<void()> printSecond)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [this]() {
            return m_k == 1;
        });
        printSecond();
        m_k = 2;
        m_cv.notify_one();
    }

    void third(function<void()> printThird)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_cv.wait(lock, [this]() {
            return m_k == 2;
        });
        printThird();
    }

private:
    std::condition_variable m_cv;
    std::mutex m_mutex;
    int m_k = 0;
};
#endif

// semaphore
#if 0
#include <semaphore.h>
class Foo {
public:

    Foo()
    {
        sem_init(&m_sem1, 0, 0), sem_init(&m_sem2, 0, 0);
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        sem_post(&m_sem1);
    }

    void second(function<void()> printSecond)
    {
        sem_wait(&m_sem1);
        printSecond();
        sem_post(&m_sem2);
    }

    void third(function<void()> printThird)
    {
        sem_wait(&m_sem2);
        printThird();
    }

private:
    sem_t m_sem1, m_sem2;
};
#endif

// promise
#if 0
class Foo {
public:

    Foo()
    {
    }

    void first(function<void()> printFirst)
    {
        printFirst();
        m_promise1.set_value();
    }

    void second(function<void()> printSecond)
    {
        m_promise1.get_future().wait();
        printSecond();
        m_promise2.set_value();
    }

    void third(function<void()> printThird)
    {
        m_promise2.get_future().wait();
        printThird();
    }

private:
    std::promise<void> m_promise1, m_promise2;
};
#endif

// package_task
#if 0
class Foo {
public:

    void first(function<void()> printFirst) {
        printFirst();
        m_pt1();
    }
    void second(function<void()> printSecond) {
        m_pt1.get_future().wait();
        printSecond();
        m_pt2();
    }

    void third(function<void()> printThird) {
        m_pt2.get_future().wait();
        printThird();
    }

private:
    std::function<void()> m_task = []() {};
    std::packaged_task<void()> m_pt1{m_task}, m_pt2{m_task};
};
#endif

// atomic
#if 0
class Foo {
public:
    void first(function<void()> printFirst)
    {
        printFirst();
        m_val1 = true;
    }

    void second(function<void()> printSecond)
    {
        while (!m_val1)
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        printSecond();
        m_val2 = true;
    }

    void third(function<void()> printThird)
    {
        while (!m_val2)
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        printThird();
    }

private:
    std::atomic<bool> m_val1{false};
    std::atomic<bool> m_val2{false};
};
#endif
#endif //LEETCODE_Q1114_HH
