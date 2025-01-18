#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};


int crossProduct(Point a, Point b, Point c) {
    int y1 = b.y - a.y;
    int y2 = c.y - a.y;
    int x1 = b.x - a.x;
    int x2 = c.x - a.x;
    return y1 * x2 - y2 * x1;
}


int distanceSquared(Point a, Point b) {
    return (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
}

vector<Point> findConvexHull(vector<Point>& points) {
    if (points.size() < 3) {
        return points; 
    }

    
    Point start = points[0];
    for (auto& point : points) {
        if (point.x < start.x) {
            start = point;
        }
    }

    vector<Point> hull;
    Point current = start;

    while (true) {
        hull.push_back(current);
        Point nextTarget = points[0];

        for (auto& point : points) {
            if (point.x == current.x && point.y == current.y) continue;

            int val = crossProduct(current, nextTarget, point);

            if (val > 0 || (val == 0 && distanceSquared(current, point) > distanceSquared(current, nextTarget))) {
                nextTarget = point;
            }
        }

        current = nextTarget;

        // Break if we are back to the start point
        if (current.x == start.x && current.y == start.y) break;
    }

    return hull;
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
