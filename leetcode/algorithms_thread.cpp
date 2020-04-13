#include "common.h"
#include <mutex>
#include <condition_variable>
#include <thread>
#include <functional>
using namespace std;
class FooBar
{
private:
    int n;

public:
    int m_count = 1;
    mutex m_mutex;
    condition_variable m_conbar;
    condition_variable m_confoo;
    FooBar(int n)
    {
        this->n = n;
    }

    void foo()
    {

        for (int i = 0; i < n; i++) {
            unique_lock<mutex> locker(m_mutex);
            // printFoo() outputs "foo". Do not change or remove this line.
            m_confoo.wait(locker, [this]() {return m_count % 2 == 1; });
            printf("foo");
            m_count++;
            m_conbar.notify_one();
        }
    }

    void bar()
    {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> locker(m_mutex);
            // printBar() outputs "bar". Do not change or remove this line.
            m_conbar.wait(locker, [this]() {return m_count % 2 == 0; });
            printf("bar\n");
            m_count++;
            m_confoo.notify_one();
        }
    }
};

FooBar kFooBar(3);

int main()
{
    thread t1(&FooBar::bar, &kFooBar);
    thread t2(&FooBar::foo, &kFooBar);

    t1.join();
    t2.join();
    system("pause");
    return 0;
}