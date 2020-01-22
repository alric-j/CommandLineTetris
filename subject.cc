#include "subject.h"
#include "observer.h"
#include "blockinfo.h"
#include <iostream>

void Subject::attach(std::shared_ptr<Observer> o) {

  observers.push_back(o);    
}

void Subject::notifyObservers(bool clear) {
  for(auto i = observers.begin(); i != observers.end(); ++i) {
    if(clear) {
      Info info = getInfo();
      (*i)->notify({info.x, info.y, BlockType::Empty});
    }
    else
      (*i)->notify(getInfo());

  }

}
