class Foo {
public:
    int value{};
};

class Bar {
public:
    Foo* foo{nullptr};
};
int sink(int);

int main() {
  Foo foo;
  foo.value = 3;

  Bar bar;
  bar.foo = &foo;
  sink(bar.foo->value);

  Bar *pBar = &bar;
  pBar->foo = nullptr;
  sink(pBar->foo->value);
  
  bar.foo = &foo;
  sink(pBar->foo->value);
}
