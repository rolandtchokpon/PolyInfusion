#pragma once

#include <iostream>
#include <map>

#include "../reserve/Reserve.h"

namespace Machine
{

    class DistributeurEau
    {
    public:
        virtual ~DistributeurEau() = 0;

        void distribuerEau(double quantite);
        double obtenirRatio() const;

    protected:
        DistributeurEau(Reserve *reserve, double ratioSurplus);

        Reserve *reserve_;
        double ratio_;
    };

} // namespace Machine