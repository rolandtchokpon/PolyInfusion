
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

    void DistributeurThe::verifierSuffisance(const std::string &the, double quantite) const
    {
        reserve_->theSuffisant(the, quantite, ratio_);
    }

    double DistributeurThe::obtenirRatio() const { return ratio_; }

} // namespace Machine