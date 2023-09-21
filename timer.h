#ifndef TIMER_H
#define TIMER_H

#include <mutex>
#include <thread>

class Timer
{
    public:
    Timer(std::function<void()> f, bool triggerOnce = false);
    ~Timer();

    void start(const int timeout);
    void stop();

    void triggerOnce();

    private:
    std::condition_variable m_cv;
    std::atomic_bool m_loop;
    std::atomic_bool m_exit;
    std::mutex m_mutex;
    std::thread m_thread;

    std::function<void()> m_function;
};

#endif // TIMER_H