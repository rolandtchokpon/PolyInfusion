
#include "../../include/distributeurThe/DistributeurTheCompact.h"

namespace Machine {

    const double RATIO_SURPLUS_COMPACT = 0.1; // 10% de surplus

    DistributeurTheCompact::~DistributeurTheCompact() = default;


    DistributeurTheCompact::DistributeurTheCompact(Reserve *reserve) : DistributeurThe(reserve, RATIO_SURPLUS_COMPACT) {}

} // namespace Machine