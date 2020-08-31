#include "source/event_future/event_base_future.h"

namespace coroevent {
EventBaseFuture::EventBaseFuture() : base_(event_base_new()) {}
EventBaseFuture::EventBaseFuture(EventBaseFuture&& rhs) : base_(rhs.base_) { rhs.base_ = nullptr; }

EventBaseFuture::~EventBaseFuture() { event_base_free(base_); }

event_base* EventBaseFuture::getEventBase() { return base_; }
void EventBaseFuture::resume() { event_base_loop(base_, EVLOOP_NONBLOCK); }

} // namespace coroevent