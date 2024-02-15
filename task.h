#pragma once
#include<QtCore>
#include <functional>
#include <iostream>

class Task : public QObject
{
    Q_OBJECT
public:
    explicit Task(QObject* parent = nullptr) : QObject(parent) {}

    template<typename Callable, typename... Args>
    static void timeMethod(const std::string& name, Callable&& callable, Args&&... args)
    {
        QElapsedTimer timer;

        // Start the timer
        timer.start();

        // Execute the callable with the provided arguments
        std::invoke(std::forward<Callable>(callable), std::forward<Args>(args)...);

        // Measure and print the elapsed time
        qint64 elapsed = timer.elapsed();
        std::cout << name << " " << elapsed << " milliseconds." << std::endl;
    }
};