#ifndef TIMERLOOP_H
#define TIMERLOOP_H

#include <mutex>
#include <thread>
#include <vector>
#include "timer.h"

class TimerLoop
{
public:
    TimerLoop();
    ~TimerLoop();

private:
    void loop();

    std::atomic_bool m_running;
    std::mutex m_mutex;
    std::thread m_thread;

    std::vector<Timer *> m_timers;
};

#endif // TIMERLOOP_H