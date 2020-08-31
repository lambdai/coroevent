#include "gtest/gtest.h"
#include "glog/logging.h"

#include "source/event_future/event_base_future.h"

class EventBaseFutureTest : public ::testing::Test {
protected:
  void SetUp() override { LOG(INFO) << "in " << __FUNCTION__; }

  void TearDown() override {}

public:
  coroevent::EventBaseFuture evb_future_;
};

TEST_F(EventBaseFutureTest, testBasic) { ASSERT_NE(nullptr, evb_future_.getEventBase()); }

TEST_F(EventBaseFutureTest, testBasicResume) { evb_future_.resume(); }