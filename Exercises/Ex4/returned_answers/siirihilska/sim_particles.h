#ifndef SIM_PARTICLES_H
#define SIM_PARTICLES_H

#include "reconst_track.h"

class Sim_particles : public Reconst_track {
private:
    int id;
    int parent_id;

public:
    Sim_particles(double e, double x, double y, double z, int particle_id, int parent_id);

    int get_id() const;
    int get_parent_id() const;

};

#endif
