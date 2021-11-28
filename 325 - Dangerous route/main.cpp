#include <iostream>
#include <vector>

using namespace std;

int repr(int dsu[], int i) {
//    Path compression heuristic
    if (i == dsu[i]){
        return i;
    }
    return dsu[i] = repr(dsu, dsu[i]);
}

bool isInTheSameSet(int dsu[], int a, int b) {
    return repr(dsu, a) == repr(dsu, b);
}

void make_union(int dsu[], int depthDsu[], int a, int b) {
    a = repr(dsu, a);
    b = repr(dsu, b);

    if (a == b) {
        return;
    } else {
        if (depthDsu[a] > depthDsu[b]) {
            swap(a, b);
        }
        dsu[a] = b;
        if (depthDsu[a] == depthDsu[b]) {
            depthDsu[b]++;
        }
    }
}

int numberOfSets(int dsu[], int n) {
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == dsu[i]) {
            count++;
        }
    }
    return count;
}

void setCreate(int dsu[], int depthDsu[], int i) {
    dsu[i] = i;
    depthDsu[i] = 0;
}

//Heap sort

int left(int i) {
    return 2 * i;
}

int right(int i) {
    return 2 * i + 1;
}

int comparator(pair<int, pair<int,  int>> a, pair<int, pair<int,  int>> b) {
    return a.first > b.first;
}

void heapify(vector<pair<int, pair<int,  int>>> &a, int i, int n) {
    int largest = 0;
    int l = left(i);
    int r = right(i);

    if (l <= n && comparator(a[l], a[i])) {
        largest = l;
    } else {
        largest = i;
    }
    if (r <= n && comparator(a[r], a[largest])) {
        largest = r;
    }

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, largest, n);
    }
}

void buildHeap(vector<pair<int, pair<int,  int>>> &a, int n) {
    for (int j = n / 2; j > 0; --j) {
        heapify(a, j, n);
    }
}

void heapSort(vector<pair<int, pair<int,  int>>> &a, int n) {
    for (int i = n; i > 1 ; --i) {
        swap(a[1], a[i]);
        heapify(a, 1, i-1);
    }
}


int main() {
    int n, m;
    int e1, e2, d;
    cin >> n >> m;

    int dsu[n + 1];
    int depthDsu[n + 1];

    for (int i = 1; i <= n; ++i) {
        setCreate(dsu, depthDsu, i);
    }

    vector<pair<int, pair<int,  int>>> roads;
//    As 0th index not used in heap sort
    roads.push_back(make_pair(-1, make_pair(-1,-1)));

    for (int i = 1; i <= m; ++i) {
        cin >> e1 >> e2 >> d;
//        pushing to vector as pair of danger of the road and the nodes
        roads.push_back(make_pair(d, make_pair(e1,e2)));
    }

//    Building heap
    buildHeap(roads, roads.size() - 1);
//    Sorting heap
    heapSort(roads, roads.size() - 1);

    int res = 0;

//    Finding minimal danger road when there is a way from first city to the last one
    for (int i = 1; i < roads.size(); ++i) {
        make_union(dsu, depthDsu, roads[i].second.first, roads[i].second.second);
        if (isInTheSameSet(dsu, 1, n)) {
            res = roads[i].first;
            break;
        }
    }

    cout << res << endl;

    return 0;
}