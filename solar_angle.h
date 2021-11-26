#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>

constexpr double DEG2RAD { M_PI / 180.0 };
constexpr double RAD2DEG { 1.0 / DEG2RAD };

class matrix{
public:
  double e[3];
};

class Matrix{
public:
  double e[3][3];
};

Matrix mat_pro(Matrix a, Matrix b);
matrix r_v(double alpha, double beta);
matrix th_v(double alpha, double beta);
matrix ph_v(double alpha, double beta);
Matrix R(matrix n, double th);
matrix solar_angle(int month, int day, double hour, double lat, double lon, matrix angle);
