#include "Counter.h"

Counter::Counter() { value = 1; }
Counter::Counter(int start) { value = start; }
int Counter::get_value() { return value; }
void Counter::set_value(int value) { this->value = value; }
int Counter::increment() { return ++value; }
int Counter::decrement() { return --value; }