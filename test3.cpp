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

  Bar &refBar = bar;
  refBar.foo = nullptr;
  sink(refBar.foo->value);
  
  bar.foo = &foo;
  sink(refBar.foo->value);
}
