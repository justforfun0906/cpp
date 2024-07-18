#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> Rectangle;

bool compareRectangles(const Rectangle& a, const Rectangle& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

long long merge(vector<Rectangle>& rectangles, int left, int mid, int right) {
    vector<Rectangle> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long count = 0;

    while (i <= mid && j <= right) {
        if (rectangles[i].second <= rectangles[j].second) {
            count+= right - j + 1;
            temp[k++] = rectangles[i++];
        } else {
            temp[k++] = rectangles[j++];
        }
    }

    while (i <= mid) temp[k++] = rectangles[i++];
    while (j <= right) temp[k++] = rectangles[j++];

    for (int p = 0; p < k; p++) {
        rectangles[left + p] = temp[p];
    }

    return count;
}

long long mergeSort(vector<Rectangle>& rectangles, int left, int right) {
    long long count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        count += mergeSort(rectangles, left, mid);
        count += mergeSort(rectangles, mid + 1, right);
        count += merge(rectangles, left, mid, right);
    }
    return count;
}

long long countContainedRectangles(vector<Rectangle>& rectangles) {
    // Ensure x <= y for each rectangle
    for (auto& rect : rectangles) {
        if (rect.first > rect.second) {
            swap(rect.first, rect.second);
        }
    }

    sort(rectangles.begin(), rectangles.end(), compareRectangles);
    return mergeSort(rectangles, 0, rectangles.size() - 1);
}

int main() {
    int n;
    cin >> n;
    vector<Rectangle> rectangles(n);

    for (int i = 0; i < n; i++) {
        cin >> rectangles[i].first >> rectangles[i].second;
    }

    long long result = countContainedRectangles(rectangles);
    cout << result << endl;

    return 0;
}