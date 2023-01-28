#define x first
#define y second
#define point pii

point operator + (point a, point b) {
	return point(a.x + b.x, a.y + b.y);	
}
point operator - (point a, point b) {
	return point(a.x - b.x, a.y - b.y);	
}
inline int dis2(point a, point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
inline int cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}
inline int dot(point a, point b) {
	return a.x * b.x + a.y * b.y;
}
