
#pragma once

#include "FabriqueSysteme.h"

namespace Fabrique
{

    class FabriqueCompact : public FabriqueSysteme
    {
    public:
        FabriqueCompact();
        ~FabriqueCompact();

        virtual std::string nomModele() const override;
        virtual std::unique_ptr<Machine::SystemeChauffage> creerChauffage() const override;
        virtual std::unique_ptr<Machine::DistributeurEau> creerDistributeurEau(Machine::Reserve *reserve) const override;
        virtual std::unique_ptr<Machine::DistributeurThe> creerDistributeurThe(Machine::Reserve *reserve) const override;
    };

} // namespace Fabrique
