
class Base {
public:
    virtual ~Base() = default;
    int value{};
    int* ptr{nullptr};
};

class Derived : public Base {
public:
    int **derived_ptr;
    void run() {
        this->ptr = &value;
        ptr = nullptr;
        sink(*this->ptr);
    }
};

void sink(int);

int main() {
    Derived d;
    d.value = 3;
    Base* pBase = &d;
    pBase->ptr = &d.value;
    d.derived_ptr = &pBase->ptr;
    **d.derived_ptr = 20;
    sink(pBase->value);
    return 0;
}
