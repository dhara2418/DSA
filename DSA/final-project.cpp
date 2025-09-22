#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
};

void add(Node*& head, int v) {
    Node* n = new Node;
    n->val = v;
    n->next = nullptr;
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next) {
        t = t->next;
    }
    t->next = n;
}

void showList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int binSearch(int arr[], int n, int t) {
    int s = 0, e = n - 1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (arr[m] == t) {
            return m;
        } else if (arr[m] < t) {
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    return -1;
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int a[n1], b[n2];

    for (int i = 0; i < n1; i++) {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++) {
        b[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (a[i] <= b[j]) {
            arr[k] = a[i];
            i++;
        } else {
            arr[k] = b[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = a[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = b[j];
        j++;
        k++;
    }
}

void mSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mSort(arr, l, m);
        mSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int part(int arr[], int l, int h) {
    int p = arr[h], i = l - 1;
    for (int j = l; j < h; j++) {
        if (arr[j] < p) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

void qSort(int arr[], int l, int h) {
    if (l < h) {
        int pi = part(arr, l, h);
        qSort(arr, l, pi - 1);
        qSort(arr, pi + 1, h);
    }
}

void showArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int arr[100], n = 0, ch;

    do {
        cout << "1. Add to List" << endl;
        cout << "2. Show List" << endl;
        cout << "3. Add to Array" << endl;
        cout << "4. Merge Sort" << endl;
        cout << "5. Quick Sort" << endl;
        cout << "6. Search" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> ch;

        if (ch == 1) {
            int v;
            cout << "Number: ";
            cin >> v;
            add(head, v);
        } else if (ch == 2) {
            cout << "List: ";
            showList(head);
        } else if (ch == 3) {
            int v;
            cout << "Number: ";
            cin >> v;
            arr[n++] = v;
        } else if (ch == 4) {
            mSort(arr, 0, n - 1);
            cout << "After Merge Sort: ";
            showArr(arr, n);
        } else if (ch == 5) {
            qSort(arr, 0, n - 1);
            cout << "After Quick Sort: ";
            showArr(arr, n);
        } else if (ch == 6) {
            int t;
            cout << "Search: ";
            cin >> t;
            int idx = binSearch(arr, n, t);
            if (idx != -1) {
                cout << "Found at " << idx << endl;
            } else {
                cout << "Not found" << endl;
            }
        }

       

    } while (ch != 7);
}
