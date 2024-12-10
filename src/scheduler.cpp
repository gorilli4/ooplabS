#include "scheduler.h"
#include "task.h"

Scheduler& Scheduler::instance() {
    static Scheduler scheduler;
    return scheduler;
}

void Scheduler::schedule(Task&& task) {
    tasks.push_back(std::move(task));
}


// Запуск планировщика
void Scheduler::run() {
    if (!tasks.empty()) {
        Task task = std::move(tasks.front());
        tasks.pop_front();
        task.resume();
        if (!task.done()) {
            tasks.push_back(std::move(task));
        }
    }
}