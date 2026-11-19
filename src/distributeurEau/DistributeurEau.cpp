
#include "../../include/distributeurEau/DistributeurEau.h"

namespace Machine
{

    DistributeurEau::DistributeurEau(Reserve *reserve, double ratioSurplus) : reserve_(reserve),
                                                                              ratio_(ratioSurplus)
    {
    }

    DistributeurEau::~DistributeurEau() = default;

    void DistributeurEau::distribuerEau(double quantite)
    {
        reserve_->distribuerEau(quantite, ratio_);
    }

    double DistributeurEau::obtenirRatio() const { return ratio_; }

} // namespace Machine