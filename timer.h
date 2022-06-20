//
// Created by c w on 2022/6/21.
//
//timer.h
#ifndef W_TIMER_H
#define W_TIMER_H

#include <iostream>
#include <string>
#include <chrono>

/**
* Timer will start automatically when it's created and it will not stop until the Stop is called.
* User can get time interval from a running timer multiple times calling GetElapsed.
*/
class Timer {
public:

    /**
    * Start timing right after this timer is constructed.
    */
    Timer() : _name("default timer") {
        ResetTimer2Now();
    }

    /**
    * Start timing right after this timer is constructed.
    */
    explicit Timer(std::string name) : _name(std::move(name)) {
        ResetTimer2Now();
    }

    /**
    * Start this timer. Re-assign the _start_time field to the current time.
    */
    inline void ResetTimer2Now() {
        std::cout << "Timer [" << _name << "] starts" << std::endl;
        _start_time = std::chrono::steady_clock::now();
        _stopped = false;
    }


    /**
    * Stop the timer. Assign current time to field _end_time.
    */
    void Stop() {
        std::cout << "Timer [" << _name << "] stops" << std::endl;
        this->_end_time = std::chrono::steady_clock::now();
        _stopped = true;
    }

    /**
    * Get the time interval in ms from when the timer started timing to when this method is called.
    * Return a constant if this timer is stopped.
    * Calling of this method will not affect the timer's running.
    * @return The result time interval.
    */
    inline double GetElapsed() const {
        if (!_stopped) {
            std::chrono::duration<double> elapse_time = std::chrono::steady_clock::now() - _start_time;
            double result = elapse_time.count() * 1000;

            return (long) (result * 1 + 0.5) / 1.0;
        }

        std::chrono::duration<double> elapse_time = _end_time - _start_time;
        double result = elapse_time.count() * 1000;

        return (long) (result * 1 + 0.5) / 1.0;
    }

    /**
    * Log the elapsed time after this timer being started. User can determine whether to reset the
    * start time to now which means the
    * @param restart If restart this timer after logging the result.
    * @param unit_ms Use ms as time unit if true, s if false.
    * @param tip Tip words which was seperated with the result by ":".
    * @param kill If kill the program after logging the result.
    */
    void Log(const std::string &tip = "",
             bool unit_ms = true, bool kill = false
    ) const {
        if (unit_ms) {
            if (tip.length() > 0)
                std::cout << tip + ":" << GetElapsed() << "ms" << std::endl;
            else
                std::cout << _name + ":" << GetElapsed() << "ms" << std::endl;
        } else {
            if (tip.length() > 0)
                std::cout << tip + ":" << GetElapsed() / 1000.0 << "s" << std::endl;
            else
                std::cout << _name + ":" << GetElapsed() / 1000.0 << "s" << std::endl;
        }

        if (kill)
            exit(5);
    }


private:
    std::chrono::steady_clock::time_point _start_time;
    std::chrono::steady_clock::time_point _end_time;
    std::string _name;
    bool _stopped = true;
}; // timer

#endif //W_TIMER_H

