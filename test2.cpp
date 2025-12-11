
class Foo {
public:
    int* value{};
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

    return 0;
}