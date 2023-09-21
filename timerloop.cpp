#include "timerloop.h"

TimerLoop::TimerLoop()
{
    m_thread = std::thread(&TimerLoop::loop, this);
}

TimerLoop::~TimerLoop()
{
    m_running = false;
    if (m_thread.joinable())
    {
        m_thread.join();
    }

    m_timers.clear();
}

void TimerLoop::loop()
{
    m_running = true;

    while (m_running)
    {
        // TODO: Process Timers to launch functions
    }
}