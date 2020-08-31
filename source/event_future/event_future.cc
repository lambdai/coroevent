#include "source/event_future/event_future.h"

namespace coroevent {
EventFuture::EventFuture() : base_(event_base_new()) {}
EventFuture::~EventFuture() { event_base_free(base_); }

event_base* EventFuture::getEventBase() { return base_; }

} // namespace coroevent