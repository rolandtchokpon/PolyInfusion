
#include "../../include/distributeurThe/DistributeurThe.h"

namespace Machine
{

    DistributeurThe::DistributeurThe(Reserve *reserve, double ratioSurplus) : reserve_(reserve),
                                                                              ratio_(ratioSurplus)
    {
    }

    DistributeurThe::~DistributeurThe() = default;

    void DistributeurThe::distribuerThe(const std::string &the, double quantite)
    {
        reserve_->distribuerThe(the, quantite, ratio_);
    }

    const The& DistributeurThe::obtenirThe(const std::string &the)
    {
        reserve_->obtenirThe(the);
    }

    double DistributeurThe::obtenirRatio() const { return ratio_; }

} // namespace Machine