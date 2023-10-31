#pragma once

class Counter {
private:
    int value;
public:
    Counter();
    Counter(int start);
    int get_value();
    void set_value(int value);
    int increment();
    int decrement();
};