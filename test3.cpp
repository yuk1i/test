class Foo {
public:
    int value{};
};

class Bar {
public:
    Foo* foo{nullptr};
};
int sink(int);

Foo* newFoo();

int main() {
  Foo* pFoo = newFoo();
  Foo** ppFoo = &pFoo;
  if (*ppFoo != nullptr)
      sink(pFoo->value);
}
