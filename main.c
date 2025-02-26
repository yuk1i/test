#include <iostream>

class MyClass {
public:
    MyClass(int value): value(value) {}
    int value;
};

void useObject(MyClass* obj) {
    std::cout << "Using object with value: " << obj->value << std::endl;
}

void deleteObject(MyClass* obj) {
    delete obj; // 释放内存
}

int main() {
    MyClass* myObj = new MyClass(42); // 创建对象
    useObject(myObj);                // 使用对象
    deleteObject(myObj);             // 删除对象，释放内存
    useObject(myObj);                // 使用对象2
    return 0;
}
