#ifndef OBSERVER_H
#define OBSERVER_H
struct Info;

class Observer {
 public:
  virtual void notify(Info info) = 0; 
  virtual ~Observer() = default;
};
#endif
