#pragma once

#include "event2/event.h"

namespace coroevent {
class EventFuture {
public:
  EventFuture();
  virtual ~EventFuture();

  event_base* getEventBase();

  void resume();

private:
  struct event_base* base_;
};
} // namespace coroevent