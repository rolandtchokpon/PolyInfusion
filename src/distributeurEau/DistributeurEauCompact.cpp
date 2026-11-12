
#include "../../include/distributeurEau/DistributeurEauCompact.h"

namespace Machine {

    const double RATIO_SURPLUS_COMPACT = 0.2; // 20% de surplus

    DistributeurEauCompact::~DistributeurEauCompact() = default;

    DistributeurEauCompact::DistributeurEauCompact() : DistributeurEau(RATIO_SURPLUS_COMPACT) {}

}  // namespace Machine