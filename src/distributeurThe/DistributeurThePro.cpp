
#include "../../include/distributeurThe/DistributeurThePro.h"

namespace Machine {

    const double RATIO_SURPLUS_PRO = 0.0; // Aucun surplus

    DistributeurThePro::~DistributeurThePro() = default;

    DistributeurThePro::DistributeurThePro() : DistributeurThe(RATIO_SURPLUS_PRO) {}

} // namespace Machine