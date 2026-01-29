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
  Bar bar;
  bar.foo = newFoo();
  sink(bar.foo->value);

  Bar *pBar = &bar;
  pBar->foo = nullptr;
  sink(pBar->foo->value);
  
  bar.foo = newFoo();
  sink(pBar->foo->value);
}
