class Test {
    int a{};
    Test* ptr{nullptr};

    virtual ~Test() = default;
}

int test1(int i) {
    int *qwq, a, asd[123];
    struct {
        int a;
        long b;
        void* p;
    } q;
    int b = 1;
    int *p;
    p = &b;
    if (i==1)
        *p = 0;
    return 3 / b;
}
