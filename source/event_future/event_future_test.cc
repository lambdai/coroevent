#include "gtest/gtest.h"
#include "glog/logging.h"

#include "source/event_future/event_future.h"

class EvFutureTest : public ::testing::Test {
protected:
  void SetUp() override { LOG(INFO) << "in " << __FUNCTION__; }

  void TearDown() override {}

public:
  coroevent::EventFuture ev_future_;
};

TEST_F(EvFutureTest, testBasic) { ASSERT_NE(nullptr, ev_future_.getEventBase()); }

TEST_F(EvFutureTest, testBasicResume) { ev_future_.resume(); }