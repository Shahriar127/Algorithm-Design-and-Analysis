#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Structure for points
struct Point {
    int x, y;
};

// To find orientation of the triplet (p, q, r)
// 0 -> Collinear, 1 -> Clockwise, 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0; // Collinear
    return (val > 0) ? 1 : 2; // Clockwise or Counterclockwise
}

// Implementation of Jarvis's Algorithm
void jarvisAlgorithm(vector<Point>& points) {
    int n = points.size();
    if (n < 3) {
        cout << "Convex hull cannot be formed with less than 3 points.\n";
        return;
    }

    vector<Point> hull;

    // Step 1: Find the leftmost point
    int leftmost = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[leftmost].x) {
            leftmost = i;
        }
    }

    // Step 2: Wrapping process
    int p = leftmost, q;
    do {
        hull.push_back(points[p]);
        q = (p + 1) % n;

        for (int i = 0; i < n; i++) {
            // Find the most counterclockwise point
            if (orientation(points[p], points[i], points[q]) == 2) {
                q = i;
            }
        }

        p = q; // Move to the next point

    } while (p != leftmost); // Until we return to the starting point

    // Step 3: Print the convex hull
    cout << "Points in the convex hull:\n";
    for (const auto& point : hull) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }
}

int main() {
    vector<Point> points = {
        {0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0},
        {0, 0}, {3, 3}
    };

    jarvisAlgorithm(points);

    return 0;
}
