int call(int arg0, int arg1);

int main() {
    int b = 0;
    int c = b+1;
    int a = call(b,c);
    int d = a;
    d = d + 1;
    return 0;
}

int call(int arg0, int arg1) {
    arg0 += arg1;
    return arg0 + 114514;
}