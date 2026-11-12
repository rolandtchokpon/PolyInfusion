
#include "../../include/distributeurEau/DistributeurEauPro.h"

namespace Machine {

    const double RATIO_SURPLUS_PRO = 0.0; // Aucun surplus

    DistributeurEauPro::~DistributeurEauPro() = default;


    DistributeurEauPro::DistributeurEauPro() : DistributeurEau(RATIO_SURPLUS_PRO) {}

} // namespace Machine