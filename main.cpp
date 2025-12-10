class Test2;

class Test1 {
public:
    Test2 *ptr{};
    int value{};
};

class Test2 {
public:
    int value{3};
    int* intptr{};
};

void sink(int v) {}

int test1(int i) {
    int global;
    Test1 t1;
    Test2 t2;
    
    t2.intptr = &global;
    
    if (i == 1) {
        t1.ptr = &t2;
        t2.value = 4;
    } else {
        t1.ptr = nullptr;
    }

    if (i == 3) { t1.value = 5; }

    sink(*t1.ptr->intptr);
    sink(t1.value);
    sink(*t2.intptr);

    int* p0 = &global;
    sink(*p0);
    return 0;
}
