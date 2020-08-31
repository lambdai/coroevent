#pragma once

#include <experimental/coroutine>
#include <future>

#include "event2/event.h"
#include "event2/event_struct.h"

namespace coroevent {
class EventFuture {
public:
  struct EventFuturePromise;
  using EventFutureHandle = std::experimental::coroutine_handle<EventFuturePromise>;
  EventFuture();
  EventFuture(EventFuture&& rhs) = delete;
  virtual ~EventFuture();

  void resume();

private:
  struct event raw_event_;
  EventFutureHandle handle_;
};

class EventFuturePromise {
public:
  using EventFutureHandle = std::experimental::coroutine_handle<EventFuturePromise>;
  auto get_return_object() { return EventFutureHandle::from_promise(*this); }
  auto initial_suspend() { return std::experimental::suspend_always(); }
  auto final_suspend() { return std::experimental::suspend_always(); }
  void return_void() {}
  void unhandled_exception() { std::terminate(); }
};
} // namespace coroevent