//#include <chrono>
#include <experimental/coroutine>
#include <future>
#include <iostream>
#include <vector>

using namespace std;

class resumable {
public:
  struct promise_type;
  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  resumable(coro_handle handle) : handle_(handle) {
    std::cout << "construct resumable from hande " << static_cast<const void*>(&handle)
              << std::endl;
  }
  // resumable(resumable&) = delete;
  // resumable(resumable&&) = delete;
  bool resumeXX() {
    if (not handle_.done())
      handle_.resume();
    return not handle_.done();
  }
  ~resumable() { handle_.destroy(); }

private:
  coro_handle handle_;
};

struct resumable::promise_type {
  using coro_handle = std::experimental::coroutine_handle<promise_type>;
  auto get_return_object() {
    std::cout << __FUNCTION__ << std::endl;

    return coro_handle::from_promise(*this);
  }
  auto initial_suspend() {
    std::cout << __FUNCTION__ << std::endl;
    return std::experimental::suspend_always();
  }
  auto final_suspend() {
    std::cout << __FUNCTION__ << std::endl;
    return std::experimental::suspend_always();
  }
  void return_void() {}
  void unhandled_exception() { std::terminate(); }
};

resumable foo() {
  std::cout << "Hello" << std::endl;
  co_await std::experimental::suspend_never();
  std::cout << "another co_wait" << std::endl;

  co_await std::experimental::suspend_always();

  std::cout << "Coroutine" << std::endl;
}

int main() {
  resumable res1 = foo();
  resumable res2 = foo();
  
  std::vector<resumable*> rs{&res1, &res2};
  std::vector<bool> runs{true, true};
  // while (std::any_of(runs.begin(), runs.end(), [](auto b) { return b; })) {
  //   std::cout << "about to call resume()" << std::endl;
  //   for (int i = 0; i < 2; i++) {
  //     if (runs[i]) {
  //       runs[i] = rs[i]->resumeXX();
  //     }
  //   }
  // }
      std::cout << "about to call resume1()" << std::endl;
      while (rs[0]->resumeXX());
std::cout << "about to call resume2()" << std::endl;
      
      while (rs[1]->resumeXX());

    
  
  return 0;
}