
#pragma once

#include "FabriqueSysteme.h"
#include "../systeme/SystemePro.h"

namespace Fabrique
{

    class FabriquePro : public FabriqueSysteme
    {
    public:
        FabriquePro();
        ~FabriquePro();

        virtual std::unique_ptr<Machine::Systeme> creerSysteme() override;
    };

} // namespace Fabrique
