
#pragma once

#include <iostream>

#include "../reserve/Reserve.h"

namespace Machine
{

    class DistributeurThe
    {
    public:
        virtual ~DistributeurThe() = 0;

        void distribuerThe(const std::string &the, double quantite);
        const The &obtenirThe(const std::string &the);
        double obtenirRatio() const;

    protected:
        DistributeurThe(Reserve *reserve, double ratioSurplus);

        Reserve *reserve_;
        double ratio_;
    };

} // namespace Machine