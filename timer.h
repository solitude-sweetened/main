#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
    using clock = std::chrono::high_resolution_clock;
    clock::time_point start_time;
    public:
        void start() {
            start_time = clock::now();
        }
        long long elapsedMs() const {
            using namespace std::chrono;
            return duration_cast<milliseconds>(clock::now() - start_time).count();
        }
};

#endif