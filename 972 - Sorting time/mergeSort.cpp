#include <iostream>

using namespace std;

struct MyTime {
    int hour, min, sec;
    MyTime() {};
    MyTime(MyTime *a) {
        hour = a->hour;
        min = a->min;
        sec = a->sec;
    };
    MyTime(int h, int m, int s) {
        hour = h;
        min = m;
        sec = s;
    }
};

int comparator (MyTime a, MyTime b) {
    if (a.hour == b.hour && a.min == b.min) {
        return a.sec < b.sec;
    }
    if (a.hour == b.hour ) {
        return a.min < b.min;
    }
    return a.hour < b.hour;
}

void printArray(MyTime a[], int n) {
    for (int i = 1; i <= n; ++i) {
        cout << a[i].hour << " " << a[i].min << " " << a[i].sec << endl;
    }
}

void mergeOfSort(MyTime a[], int lb, int le, int rb, int re) {
//    lb - left begin, le - left end, rb - right begin, re - right end
// a[lb..le] and a[rb..re] are merged into a[lb..re]

    int lp = lb; // left pointer
    int rp = rb; // right pointer
    int len = re - lp + 1;

    int i;
    MyTime res[len]; // temporary array

    for (i = 0; lp <= le && rp <= re; i++) {
        if (comparator(a[lp], a[rp])) {
            res[i] = a[lp];
            lp++;
        } else {
            res[i] = a[rp];
            rp++;
        }
    }

//    rest of left part
    while (lp <= le) {
        res[i] = a[lp];
        lp++;
        i++;
    }

//    rest of right part
    while (rp <= re) {
        res[i] = a[rp];
        rp++;
        i++;
    }

    for (int j = 0; j < len; ++j) {
        a[lb + j] = res[j];
    }
}

void mergeSort(MyTime a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    mergeOfSort(a, left, mid, mid + 1, right);
}

int main() {
    int n, h,m,s;

    cin >> n;

    MyTime a[n + 1];

    for (int i = 1; i <= n; ++i) {
        cin >> h >> m >> s;
        a[i] = new MyTime(h, m, s);
    }

    mergeSort(a, 1, n);

    printArray(a, n);

    return 0;
}