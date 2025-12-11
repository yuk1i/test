
class Foo {
public:
    int* value{};
    void callMe();
};

class Bar {
public:
    Foo* foo{};
};

int sink(int);

int test2() {
    int v = 3;

    Foo foo;
    foo.value = nullptr;

    Foo* pFoo = &foo;
    pFoo->value = &v;

    Bar bar;
    bar.foo = &foo;
    sink(*(bar.foo->value));

    Bar bar2;
    bar2.foo = nullptr;
    Bar* pbar2 = &bar2;
    pbar2->foo = &foo;
    bar2.foo->callMe();

    Bar bar3;
    bar3.foo = nullptr;

    Bar& refBar3 = bar3;
    refBar3.foo = &foo;
    bar3.foo->callMe();

    return 0;
}