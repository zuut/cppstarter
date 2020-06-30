
#include "util.h"

#include <string>
#include <iostream>
#include <chrono>
#include <functional>
#include <folly/futures/Future.h>
#include <folly/executors/ThreadedExecutor.h>

namespace zuut {
    TEST(follyTest, future) {
        using namespace std::chrono_literals;
        folly::ThreadedExecutor executor;
        auto calcResult = folly::via(folly::Executor::getKeepAliveToken(executor), [] {
            std::cout << "Task has started to run." <<std::endl;
            sleep( (3s).count() );
            std::cout << "Task has completed its run." <<std::endl;
            return true;
        });

        std::cout << "wait for task to run." <<std::endl;
        auto isDone = std::move(calcResult).get(); // wait for the result to be done
        std::cout << "we're done = '" << isDone << "'." <<std::endl;
    }

    TEST(follyTest, futureContinued) {
        using namespace std::chrono_literals;
        folly::ThreadedExecutor executor;

        auto calcResult = folly::via(folly::Executor::getKeepAliveToken(executor), [] {
            std::cout << "Task has started to run." <<std::endl;
            sleep( (3s).count() );
            std::cout << "Task has completed its run." <<std::endl;
            return true;
        });

        auto calcResult2 = std::move(calcResult).thenValue([] (bool r) { return r ? 42 : -42; }) ;

        std::cout << "wait for task to run." <<std::endl;
        auto isDone = std::move(calcResult2).get(); // wait for the result to be done
        std::cout << "we're done = '" << isDone << "'." <<std::endl;
    }
}
