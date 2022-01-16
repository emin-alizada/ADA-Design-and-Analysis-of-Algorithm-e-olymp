#include <iostream>

using namespace std;

struct People {
    string name, surname;
    int year;

    People() {};
    People(People *a) {
        name = a->name;
        surname = a->surname;
        year = a->year;
    };
    People(string n, string s, int y) {
        name = n;
        surname = s;
        year = y;
    }
};

int comparator (People a, People b) {
    if (a.name == b.name && a.surname == b.surname) {
        return a.year > b.year;
    }
    if (a.surname == b.surname ) {
        return a.name < b.name;
    }

    return a.surname < b.surname;
}

void mergeOfSort(People a[], int lb, int le, int rb, int re) {
//    lb - left begin, le - left end, rb - right begin, re - right end
// a[lb..le] and a[rb..re] are merged into a[lb..re]

    int lp = lb; // left pointer
    int rp = rb; // right pointer
    int len = re - lp + 1;

    int i;
    People res[len]; // temporary array

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

void mergeSort(People a[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    mergeOfSort(a, left, mid, mid + 1, right);
}

int main() {
    int n;
    cin>>n;

    string name, surnane;
    int year;

    People p[n];

    for (int i = 0; i < n; ++i) {
        cin >> name >> surnane >> year;
        p[i] = new People(name, surnane, year);
    }

    mergeSort(p, 0, n-1);

    for (int i = 0; i < n; ++i) {
        cout<< p[i].name << " " << p[i].surname << " " << p[i].year << endl;
    }

    return 0;
}


/*
6
Mila Catron 1977
Ivan Mendel 1956
Mihail Egorov 1980
Eric Catron 1977
Mihail Egorov 1988
Petr Mendel 1990

 */