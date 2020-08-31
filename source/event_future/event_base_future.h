#pragma once

#include <experimental/coroutine>
#include <future>

#include "event2/event.h"

namespace coroevent {
class EventBaseFuture {
public:
  struct EventBaseFuturePromise;
  using EventBaseFutureHandle = std::experimental::coroutine_handle<EventBaseFuturePromise>;
  EventBaseFuture();
  EventBaseFuture(EventBaseFuture&& rhs);
  virtual ~EventBaseFuture();

  event_base* getEventBase();

  void resume();

private:
  struct event_base* base_;
};

class EventBaseFuture::EventBaseFuturePromise {
public:
  using EventBaseFutureHandle = std::experimental::coroutine_handle<EventBaseFuturePromise>;
  auto get_return_object() { return EventBaseFutureHandle::from_promise(*this); }
  auto initial_suspend() { return std::experimental::suspend_always(); }
  auto final_suspend() { return std::experimental::suspend_always(); }
  void return_void() {}
  void unhandled_exception() { std::terminate(); }
};
} // namespace coroevent