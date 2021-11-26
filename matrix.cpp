#include "solar_angle.h"

Matrix mat_pro(Matrix a, Matrix b){ /*行列の積*/
  Matrix v;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      v.e[i][j] = a.e[i][0]*b.e[0][j]
      + a.e[i][1]*b.e[1][j] + a.e[i][2]*b.e[2][j];
    }
  }
  return v;
}

Matrix R(matrix n, double th){ /*ロドリゲスの回転行列*/
  Matrix R;
  R.e[0][0] = cos(th) + n.e[0]*n.e[0]*(1 - cos(th));
  R.e[0][1] = n.e[0]*n.e[1]*(1 - cos(th)) - n.e[2]*sin(th);
  R.e[0][2] = n.e[2]*n.e[0]*(1 - cos(th)) + n.e[1]*sin(th);
  R.e[1][0] = n.e[0]*n.e[1]*(1 - cos(th)) + n.e[2]*sin(th);
  R.e[1][1] = cos(th) + n.e[1]*n.e[1]*(1 - cos(th));
  R.e[1][2] = n.e[1]*n.e[2]*(1 - cos(th)) - n.e[0]*sin(th);
  R.e[2][0] = n.e[2]*n.e[0]*(1 - cos(th)) - n.e[1]*sin(th);
  R.e[2][1] = n.e[1]*n.e[2]*(1 - cos(th)) + n.e[0]*sin(th);
  R.e[2][2] = cos(th) + n.e[2]*n.e[2]*(1 - cos(th));

  return R;
}
