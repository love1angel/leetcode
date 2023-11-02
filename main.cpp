#include "ThreadPool.hpp"
#include <stdio.h>

class Foo {
public:
    Foo();
    void Process(std::unique_ptr<uint16_t[]> im);
private:
    void ProcessImpl(std::unique_ptr<uint16_t[]> im);
    ThreadPool t;
};

Foo::Foo() : t(4) {
}

    void Foo::Process(std::unique_ptr<uint16_t[]> im) {
#if 0
    ProcessImpl(std::move(im));
#else
    auto f = [this, p = std::move(im)]() mutable {
        this->ProcessImpl(std::move(p));
    };
    t.enqueue(std::move(f));
#endif
}

void Foo::ProcessImpl(std::unique_ptr<uint16_t[]> im) {
    printf("%p\n", im.get());
}

int main()
{
    Foo f;
    auto p = std::make_unique<uint16_t[]>(100);
    printf("%p\n", p.get());

    f.Process(std::move(p));
}

