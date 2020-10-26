#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.Ry = 1.6598;
  body.Rz = 0.5;
  body.Vx = 0.3972;
  body.Vy = -0.8018;
  body.Vz = 0.2513;

  body.rad = 0.235;
  body.mass = 0.29698;
}

void compute_force(Particle & body)
{
  //Compute Energy
  body.E = body.Ep + body.Ek;
  
  // reset force and potential energy
  body.Fx = body.Fy = body.Fz = 0.0;
  body.Ep = 0.0;

  // gravitational force
  //body.Fy += body.mass*G;

  // force with ground
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K*delta;
    body.Ep += (K*delta*delta)/2;
  }

  //Roof
  double Ly = 2;
  delta = body.rad + body.Ry - Ly;

  if (delta > 0) {
  body.Fy -= K*delta;
  body.Ep += (K*delta*delta)/2;
  }

  //Left wall
  delta = body.rad - body.Rx;
  if (delta > 0) {
  body.Fx = K*delta;
  body.Ep += (K*delta*delta)/2;
  }

  //Right wall
  double Lx = 2;
  delta = body.rad + body.Rx - Lx;

  if (delta > 0) {
  body.Fx -= K*delta;
  body.Ep += (K*delta*delta)/2;
  }

  //back wall
  delta = body.rad - body.Rz;
  if (delta > 0) {
  body.Fz += K*delta;
  body.Ep += (K*delta*delta)/2;
  }

  //front wall
  double Lz = 2;
  delta = body.rad + body.Rz - Lz;

  if (delta > 0) {
  body.Fz -= K*delta;
  body.Ep += (K*delta*delta)/2;
  }
}


void start_integration(Particle & body, const double & dt)
{
  body.Vx -= body.Fx*dt/(2*body.mass);
  body.Vy -= body.Fy*dt/(2*body.mass);
  body.Vz -= body.Fz*dt/(2*body.mass);
}

  void time_integration(Particle & body, const double & dt)
{
  // leap-frog
  body.Vx += body.Fx*dt/(body.mass);
  body.Vy += body.Fy*dt/(body.mass);
  body.Vz += body.Fz*dt/(body.mass);
  body.Rx += body.Vx*dt;
  body.Ry += body.Vy*dt;
  body.Rz += body.Vz*dt;
}

  void Ek_in_phase(Particle & body, const double & dt)
{
  double Vx = body.Vx - body.Fx*dt/(2*body.mass);
  double Vy = body.Vy - body.Fy*dt/(2*body.mass);
  double Vz = body.Vz - body.Fz*dt/(2*body.mass);
  body.Ek = body.mass*(Vx*Vx + Vy*Vy + Vz*Vz)/2;
}

void print(Particle & body, double time)
{
  std::cout << time << "  "
            << body.Rx << "  "
            << body.Ry << "  "
            << body.Rz << "  "
            << body.Vx << "  "
            << body.Vy << "  "
            << body.Vz << "  "
            << body.E << "  "
            << "\n";
}
