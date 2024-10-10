#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Calculates the distance between the two points
double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt(pow(p2.first - p1.first, 2) + pow(p2.second - p1.second, 2));
}

// Computation of the Sum of the first Natural Number
int SNM(int N) {
    return N * (N + 1) / 2;
}

int main() {
    int N;
    cout << "Enter the number of Delivery Points: ";
    cin >> N;

    vector<pair<int, int>> points(N);
    
    // Input each point's coordinates
    for (int i = 0; i < N; ++i) {
        cout << "Enter x coordinate of point " << i + 1 << ": ";
        cin >> points[i].first; 
        cout << "Enter y coordinate of point " << i + 1 << ": ";
        cin >> points[i].second;
    }

    // Calculate total distance
    double total_dist = 0.0;
    for (int i = 0; i < N - 1; ++i) {
        total_dist += dist(points[i], points[i + 1]);
    }

    // Calculate sum of first N natural numbers
    int SN = SNM(N);

    // Output results
    cout << "Total distance: " << total_dist << endl;
    cout << "Sum of first " << N << " natural numbers: " << SN << endl;

    return 0;
}
