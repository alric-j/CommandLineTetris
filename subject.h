#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>
#include <memory>
#include "info.h"

class Observer;

class Subject {
    std::vector<std::shared_ptr<Observer>> observers;
    
    public:
    void attach(std::shared_ptr<Observer>);  
    void notifyObservers(bool);
    virtual Info getInfo() = 0;
};

#endif
