
int main() {
    int i; int j;
    i = 0;
    while (i < 10) {
        i = i + 1;        
        if (i == 3 || i == 5) {
            continue;
        } else {
            continue;
        }        
        if (i == 8) {
            break;
        }
        print("%d! = %d", i, factor(i));
    }
    return 0;
}

int factor(int n) {
    int i;
    if (n < 2) {
        return 1;
    }
    return n * factor(n - 1);
}
