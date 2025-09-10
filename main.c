int test1(int i) {
    int b = 1;
    int *p;
    p = &b;
    if (i==1)
        *p = 0;
    return 3 / b;
}
