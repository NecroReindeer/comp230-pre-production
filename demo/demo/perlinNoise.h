#pragma once
#include <vector>
#include <algorithm>

#ifndef perlinNoise_H
#define perlinNoise_H

class perlinNoise {
	std::vector<int> p;
public:
	perlinNoise();
	perlinNoise(unsigned int seed);
	double noise(double x, double y, double z);

private:
	double fading(double t);
	double lerp(double t, double a, double b);
	double gradient(int hash, double x, double y, double z);
};

#endif