
#include "FabriqueSysteme.h"

namespace Fabrique
{

    class FabriqueCompact : public FabriqueSysteme
    {
        FabriqueCompact();
        ~FabriqueCompact();
        
        virtual Machine::Systeme* creerSysteme() override;
    };

} // namespace Fabrique
