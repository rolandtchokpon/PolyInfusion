
#pragma once

#include "../systeme/SystemeCompact.h"
#include "../systeme/SystemePro.h"
#include "../notification/AppDistant.h"
#include "../notification/Ecran.h"

namespace Fabrique
{

    class FabriqueSysteme
    {
    public:
        virtual ~FabriqueSysteme();
        virtual Machine::Systeme *creerSysteme() = 0;

    protected:
        FabriqueSysteme();

        std::shared_ptr<Machine::Reserve> reserve_;
        std::shared_ptr<Notification::Observateur> ecran_;
        std::shared_ptr<Notification::Observateur> app_;
        std::shared_ptr<Machine::DistributeurEau> dEau_;
        std::shared_ptr<Machine::DistributeurThe> dThe_;
        std::shared_ptr<Machine::SystemeChauffage> dThe_;
        std::shared_ptr<Machine::Systeme> systeme_;
    };

} // namespace Fabrique