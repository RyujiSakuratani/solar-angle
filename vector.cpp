#include "solar_angle.h"

int main(int argc, char **argv){

  std::string str_month(argv[1]);
  std::string str_day(argv[2]);
  std::string str_hour(argv[3]);
  std::string str_lat(argv[4]);
  std::string str_lon(argv[5]);

  double th_h, A = 0.0;/*太陽天頂角、方位角*/
  matrix angle;
  double lat = std::stod(str_lat);
  double lon = std::stod(str_lon);

  angle = solar_angle(std::stoi(str_month),std::stoi(str_day),
  std::stod(str_hour),lat,lon,angle);

  std::cout << "lat=" << lat << std::endl;
  std::cout << "lon=" << lon << std::endl;
  std::cout << "hour=" << std::stod(str_hour) << std::endl;

  th_h = angle.e[0];
  A = angle.e[1] + M_PI;/*南を基準に西側正*/

  std::cout << "th_h[deg]=" << th_h*RAD2DEG << std::endl;
  std::cout << "A[deg]=" << A*RAD2DEG << std::endl;

  double th = (90 - lat)*DEG2RAD;/*球面座標系のθ*/
  double ph = (lon - 140.7)*DEG2RAD;/*球面座標系のφ*/

  /*球面座標系の単位ベクトル*/
  matrix r_v;
  r_v.e[0] = sin(th)*cos(ph);
  r_v.e[1] = sin(th)*sin(ph);
  r_v.e[2] = cos(th);

  /*今回使わない
  matrix th_v;
  th_v.e[0] = cos(th)*cos(ph);
  th_v.e[1] = cos(th)*sin(ph);
  th_v.e[2] = -sin(th);
  */

  matrix ph_v;
  ph_v.e[0] = -sin(ph);
  ph_v.e[1] = cos(ph);
  ph_v.e[2] = 0.0;

  /*太陽へ向かう単位ベクトル*/
  matrix s;
  for(int i=0; i<3; i++){
    s.e[i] = mat_pro(R(r_v,A),R(ph_v,th_h)).e[i][0]*r_v.e[0]
    + mat_pro(R(r_v,A),R(ph_v,th_h)).e[i][1]*r_v.e[1]
    + mat_pro(R(r_v,A),R(ph_v,th_h)).e[i][2]*r_v.e[2];
  }

  std::ofstream ofs("solar.dat", std::ios::app);
  ofs << std::stod(str_hour) << " " << lat << " " << lon << " " << s.e[0] << " " << s.e[1]
  << " " << s.e[2] << " " << th_h*RAD2DEG << " " << A*RAD2DEG << "\n";
  ofs.close();

  std::cout << "sx=" << s.e[0] << std::endl;
  std::cout << "sy=" << s.e[1] << std::endl;
  std::cout << "sz=" <<s.e[2] << std::endl;

  return 0;
}
