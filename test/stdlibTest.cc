
#include "util.h"

#include <string>
#include <iostream>
#include <future>
#include <chrono>

/* literals: in std::literals
 *    std::literals::chrono_literals:
 *        {num}h   - hours
 *        {num}min - minutes
 *        {num}s   - seconds
 *        {num}ms  - milliseconds
 *        {num}us  - microseconds
 *        {num}ns  - nanoseconds
 *    std::literals::complex_literals
 *        {num}i    - imaginary
 *        {num}if   - imaginary float
 *        {num}il   - imaginary long
 *    std::literals::string_literals
 *        "{string}"s - basic_string
 */
namespace zuut {

    TEST(stdlibTest, future) {
        using namespace std::chrono_literals;
        auto calcResult = std::async(std::launch::async,[] {
            std::cout << "Task has started to run." <<std::endl;
            sleep( (3s).count() );
            std::cout << "Task has completed its run." <<std::endl;
            return true;
        });

        std::cout << "wait for task to run." <<std::endl;
        auto isDone = calcResult.get(); // wait for the result to be done
        std::cout << "we're done = '" << isDone << "'." <<std::endl;
    }

    TEST(stdlibTest, chronoLiterals) {
        using namespace std::chrono_literals;
        auto t1 = 17ms;
        auto t2 = 23s;
        auto sum = t1 + t2;
        std::cout << sum.count() << " " << clazzname(sum) << std::endl;
    }

    TEST(stdlibTest, unique_ptr) {
        struct AClass { AClass(int x) : x(1) {} int x; };
        {
            std::cout << "empty unique pointer" << std::endl;
            auto f = std::unique_ptr<AClass>();

            std::cout << f.get() << " " << clazzname(f) << std::endl;

            std::shared_ptr<AClass> sp = std::move(f);
            std::shared_ptr<AClass> sp2 = sp;

            std::cout << f.get() << " " << clazzname(f) << std::endl;
            std::cout << sp.get() << " " << clazzname(sp) << std::endl;
            std::cout << sp2.get() << " " << clazzname(sp2) << std::endl;
        };
        {
            std::cout << "valid unique pointer" << std::endl;
            auto f = std::make_unique<AClass>(1);

            std::cout << f.get() << " " << clazzname(f) << std::endl;

            std::shared_ptr<AClass> sp = std::move(f);
            std::shared_ptr<AClass> sp2 = sp;

            std::cout << f.get() << " " << clazzname(f) << std::endl;
            std::cout << sp.get() << " " << clazzname(sp) << std::endl;
            std::cout << sp2.get() << " " << clazzname(sp2) << std::endl;
        }
    }

} /* namespace zuut */
