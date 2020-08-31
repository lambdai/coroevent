#include "source/event_future/event_future.h"
#include "glog/logging.h"

namespace coroevent {
EventFuture::EventFuture() {}

EventFuture::~EventFuture() {
  // event_del(&raw_event_);
}

void EventFuture::resume() { LOG(INFO) << "in " << __FUNCTION__; }

} // namespace coroevent