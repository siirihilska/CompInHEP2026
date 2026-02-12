#include "sim_particles.h"

Sim_particles::Sim_particles(double e, double x, double y, double z, int particle_id, int parent_id): Reconst_track(e, x, y, z), id(particle_id), parent_id(parent_id) {}

int Sim_particles::get_id() const { return id; }

int Sim_particles::get_parent_id() const { return parent_id; }

