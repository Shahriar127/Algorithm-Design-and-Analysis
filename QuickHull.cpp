#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// Cross product of vectors AB and AC
int crossProduct(Point a, Point b, Point c) {
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

// Find the farthest point from line (p1, p2)
int findFarthest(const vector<Point>& points, Point p1, Point p2) {
    int maxDist = 0, farthestIndex = -1;
    for (int i = 0; i < points.size(); ++i) {
        int dist = abs(crossProduct(p1, p2, points[i]));
        if (dist > maxDist) {
            maxDist = dist;
            farthestIndex = i;
        }
    }
    return farthestIndex;
}

// Recursive function to find convex hull
void quickHull(const vector<Point>& points, Point p1, Point p2, vector<Point>& hull) {
    int farthestIndex = findFarthest(points, p1, p2);
    if (farthestIndex == -1) {
        hull.push_back(p1);
        hull.push_back(p2);
        return;
    }

    Point farthest = points[farthestIndex];
    vector<Point> leftSet, rightSet;

    for (const Point& p : points) {
        if (crossProduct(p1, farthest, p) > 0) leftSet.push_back(p);
        if (crossProduct(farthest, p2, p) > 0) rightSet.push_back(p);
    }

    quickHull(leftSet, p1, farthest, hull);
    quickHull(rightSet, farthest, p2, hull);
}

// Main function to compute convex hull
vector<Point> findConvexHull(vector<Point>& points) {
    if (points.size() < 3) return points;

    Point leftmost = *min_element(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
    Point rightmost = *max_element(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });

    vector<Point> hull;
    vector<Point> leftSet, rightSet;

    for (const Point& p : points) {
        if (crossProduct(leftmost, rightmost, p) > 0) leftSet.push_back(p);
        if (crossProduct(rightmost, leftmost, p) > 0) rightSet.push_back(p);
    }

    quickHull(leftSet, leftmost, rightmost, hull);
    quickHull(rightSet, rightmost, leftmost, hull);

    return hull;
}

int main() {
    vector<Point> points = { {0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3} };

    vector<Point> hull = findConvexHull(points);

    cout << "Points in Convex Hull:\n";
    for (const auto& point : hull) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
