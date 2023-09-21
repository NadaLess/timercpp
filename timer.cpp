#include "timer.h"
#include <iostream>

Timer::Timer(std::function<void()> function, bool triggerOnce) 
: m_function(function),
  m_loop(!triggerOnce),
  m_exit(false)
{

}

Timer::~Timer() {
    std::cout << "Destroy Timer" << std::endl;

    stop();
}

void Timer::start(const int timeout) {
    m_exit = false;

    m_thread = std::thread([=]() {
        std::cout << "Starting Timer" << std::endl;

        std::unique_lock<std::mutex> lock(m_mutex);

        do {
            auto status = m_cv.wait_for(lock, std::chrono::milliseconds(timeout));
            if (status == std::cv_status::timeout) {
                std::cout << "Execute Timer" << std::endl;
                m_function();
            } else {
                std::cout << "Timer canceled" << std::endl;
                break;
            }
        } while (m_loop && !m_exit);

        std::cout << "Ending Timer" << std::endl;
    });    
}

void Timer::stop() {
    std::cout << "Stopping Timer" << std::endl;

    m_cv.notify_one();
    m_exit = true;

    if (m_thread.joinable()) {
        m_thread.join();
    }
}

void Timer::triggerOnce() {
    m_loop = false;
}