#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;
class Point
{
public:
	int x, y;
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

bool compare(const Point& p1, const Point& p2)
{
	double dist2 = sqrt((p2.x * p2.x) + (p2.y*p2.y));
	double dist1 = sqrt((p1.x * p1.x) + (p1.y*p1.y));

	if (dist1 < dist2)
		return true;
	else
		return false;

}
vector<Point> K_NearestPoints(vector<Point>& vect, int k)
{
	int n = vect.size();
	if (k>n)
		return vect;

	//max heap    
	priority_queue<Point, vector<Point>, function<bool(const Point&, const Point&)>> pq(compare);

	for (int i = 0; i<k; i++)
		pq.push(vect[i]);

	for (int i = k; i<n; i++)
	{
		if (compare(vect[i], pq.top()))
		{
			pq.pop();
			pq.push(vect[i]);
		}
	}

	vector<Point> result;
	while (!pq.empty())
	{
		result.push_back(pq.top());
		pq.pop();
	}
	return result;
}

int main() {
	vector<Point> Points;
	Points.emplace_back(1, -1);
	Points.emplace_back(2, 4);
	Points.emplace_back(3, 5);
	Points.emplace_back(4, -1);
	Points.emplace_back(5, -2);
	Points.emplace_back(3, 3);
	vector<Point> vect = K_NearestPoints(Points, 5);
	for (int i = 0; i<vect.size(); i++)
	{
		cout << vect[i].x << "," << vect[i].y << "," << sqrt(vect[i].x*vect[i].x + vect[i].y*vect[i].y) << endl;

	}

	return 0;
}