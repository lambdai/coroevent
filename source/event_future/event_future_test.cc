#include "gtest/gtest.h"
#include "glog/logging.h"

#include "source/event_future/event_future.h"

class EventFutureTest : public ::testing::Test {
protected:
  void SetUp() override { LOG(INFO) << "in " << __FUNCTION__; }

  void TearDown() override {}

public:
  coroevent::EventFuture event_future_;
};

TEST_F(EventFutureTest, testBasicResume) { event_future_.resume(); }