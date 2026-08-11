#include "Graph.h"
#include "Partial_differential.h"
float z_coordination(int vx, int vy, float c, int x, int y) {
	float z;
	z = c * pow(vx, x) * pow(vy, y);
	return z;
}
