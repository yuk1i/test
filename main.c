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
    d = call(99999, c);
    return 0;
}

int call(int arg0, int arg1) {
    int q = 0;
    if (arg0 < 999) {
        q = 8 + arg1;
    }
    arg0 = arg1;
    return q + 114514;
}
