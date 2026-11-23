
#pragma once

#include "FabriqueSysteme.h"
#include "../systeme/SystemeCompact.h"

namespace Fabrique
{

    class FabriqueCompact : public FabriqueSysteme
    {
    public:
        FabriqueCompact();
        ~FabriqueCompact();

        virtual std::unique_ptr<Machine::Systeme> creerSysteme() override;
    };

} // namespace Fabrique
