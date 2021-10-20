#include<iostream>
#include<fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <math.h>

int main(int argc, char **argv){

  std::string str_th_v(argv[1]);
  std::string str_A(argv[2]);
//  std::string str_r(argv[3]);

  double th_v = std::stod(str_th_v);//太陽天頂角[rad]
  double A = std::stod(str_A);//方位角、北=0、東=90、南=180、西=270
  double r = 1.5e8;//半径[km]

  double x = r*sin(th_v)*cos(A);
  double y = r*sin(th_v)*sin(A);
  double z = r*cos(th_v);

  std::cout << "x=" << x << std::endl;
  std::cout << "y=" << y << std::endl;
  std::cout << "z=" << z << std::endl;

  return 0;
}
