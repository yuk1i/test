int call(int arg0, int arg1);

int main() {
    int b = 0;
    int c = b+1;
    c = c + 9;
    b = c + 10;
    int a = call(b,c);
    int d = a;
    if (d > 0) {
        d = -d;
    }
    d = d + 1;
    return 0;
}

int call(int arg0, int arg1) {
    if (arg0 < 999) {
        arg1 = 1919810;
    }
    arg0 = arg1;
    return arg1 + 114514;
}
