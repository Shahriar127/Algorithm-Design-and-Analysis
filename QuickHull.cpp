#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

// Function to compute the cross product of vectors AB and AC
int crossProduct(Point a, Point b, Point c) {
    return (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
}

// Function to compute the distance squared between two points
int distanceSquared(Point a, Point b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

// Function to find the farthest point from line (p1, p2) on one side of the line
int findFarthestPoint(const vector<Point>& points, Point p1, Point p2, vector<Point>& result) {
    int maxDist = -1;
    int farthestPointIndex = -1;

    for (int i = 0; i < points.size(); ++i) {
        int dist = crossProduct(p1, p2, points[i]);
        if (dist > maxDist) {
            maxDist = dist;
            farthestPointIndex = i;
        }
    }
    return farthestPointIndex;
}

// Recursive function to find the convex hull from the set of points
void quickHull(const vector<Point>& points, Point p1, Point p2, vector<Point>& result) {
    int farthestPointIndex = findFarthestPoint(points, p1, p2, result);

    // No point is farther, p1-p2 is part of the hull
    if (farthestPointIndex == -1) {
        result.push_back(p1);
        result.push_back(p2);
        return;
    }

    Point farthestPoint = points[farthestPointIndex];

    // Divide the points into two sets, one on each side of the line
    vector<Point> leftSet, rightSet;
    for (int i = 0; i < points.size(); ++i) {
        int val = crossProduct(p1, farthestPoint, points[i]);
        if (val > 0) {
            leftSet.push_back(points[i]);
        }
        val = crossProduct(farthestPoint, p2, points[i]);
        if (val > 0) {
            rightSet.push_back(points[i]);
        }
    }

    // Recursively find the convex hull for the left and right sets
    quickHull(leftSet, p1, farthestPoint, result);
    quickHull(rightSet, farthestPoint, p2, result);
}

// Function to find the convex hull using QuickHull algorithm
vector<Point> findConvexHull(vector<Point>& points) {
    // Handle case where there are less than 3 points
    if (points.size() < 3) return points;

    // Find the leftmost and rightmost points
    Point leftmost = *min_element(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });
    Point rightmost = *max_element(points.begin(), points.end(), [](Point a, Point b) { return a.x < b.x; });

    vector<Point> result;

    // Find the convex hull by dividing points into left and right subsets
    vector<Point> leftSet, rightSet;
    for (int i = 0; i < points.size(); ++i) {
        if (crossProduct(leftmost, rightmost, points[i]) > 0) {
            leftSet.push_back(points[i]);
        }
        if (crossProduct(rightmost, leftmost, points[i]) > 0) {
            rightSet.push_back(points[i]);
        }
    }

    // Call the recursive QuickHull function
    quickHull(leftSet, leftmost, rightmost, result);
    quickHull(rightSet, rightmost, leftmost, result);

    return result;
}

int main() {
    vector<Point> points = { {0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3} };

    vector<Point> hull = findConvexHull(points);

    cout << "Points in Convex Hull:\n";
    for (auto& point : hull) {
        cout << "(" << point.x << ", " << point.y << ")\n";
    }

    return 0;
}
