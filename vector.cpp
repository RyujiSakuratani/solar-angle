#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>

int main(int argc, char **argv){

  constexpr double DEG2RAD { M_PI / 180.0 };
  constexpr double RAD2DEG { 1.0 / DEG2RAD };

  std::string str_th_v(argv[1]);/*太陽天頂角[deg]*/
  std::string str_A(argv[2]);/*方位角[deg]*/
  std::string str_lat(argv[3]);/*北緯[deg]*/
  std::string str_lon(argv[4]);/*東経[deg]*/

  double th = M_PI/2 - std::stod(str_lat) * DEG2RAD;/*地球の球面座標におけるθ[rad]*/
  double phi = std::stod(str_lon) * DEG2RAD;/*地球の球面座標におけるφ[rad]*/
  double h_pmc = 80.0;/*PMCの高度[km]*/
  double r1 = 6.38*1e3 + h_pmc;/*地球の半径[km]*/
  double th_v = std::stod(str_th_v) * DEG2RAD + M_PI/2.0;/*太陽天頂角[rad]*/
  double A = std::stod(str_A) * DEG2RAD;/*方位角、北=0、東=90、南=180、西=270*/
  double r2 = 1.5e8;/*地球から太陽までの半径[km]*/

  /*観測点の座標*/
  double x1 = r1*sin(th)*cos(phi);
  double y1 = r1*sin(th)*sin(phi);
  double z1 = r1*cos(th);

  /*太陽の座標*/
  double x2 = r2*sin(th_v)*cos(A);
  double y2 = r2*sin(th_v)*sin(A);
  double z2 = r2*cos(th_v);

  double norm = std::pow((x2 - x1)*(x2 - x1)
   + (y2 - y1)*(y2 - y1) + (z2 - z1)*(z2 - z1), 0.5);/*ノルム*/

  /*観測点から太陽への単位ベクトル*/
  x1 = (x2 - x1)/norm;
  y1 = (y2 - y1)/norm;
  z1 = (z2 - z1)/norm;

  std::cout << "x1=" << k*x1 << std::endl;
  std::cout << "y1=" << k*y1 << std::endl;
  std::cout << "z1=" << k*z1 << std::endl;

  return 0;
}
