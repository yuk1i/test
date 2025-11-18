class Test {
    int a{};
    Test* ptr{nullptr};

    virtual ~Test() = default;
}

struct s0 {
    int a;
    long b;
    void* p;
};

int test1(int i) {
    int *qwq, a, asd[123];
    struct s0 q;

    q.a = 123;
    q.b = 456;
    
    int b = 1;
    int *p;
    p = &b;
    if (i==1)
        *p = 0;
    return 3 / b;
}
