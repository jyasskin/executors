#include <experimental/thread_pool>
#include <iostream>

namespace execution = std::experimental::execution;
using std::experimental::static_thread_pool;

int main()
{
  static_thread_pool pool{1};
  auto ex = pool.executor().require(execution::always_blocking);
  ex.execute([]{ std::cout << "we made it\n"; });
}
