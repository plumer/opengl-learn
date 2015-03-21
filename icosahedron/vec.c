#include "vec.h"
#include <math.h>

int normalize3(float vec[3]) {
	float length = vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
	length = sqrt(length);
	if (length == 0) {
		return -1;
	} else {
		vec[0] /= length;
		vec[1] /= length;
		vec[2] /= length;
		return 0;
	}
}

int addvec3(int count, ...) {
	return 0;
}
