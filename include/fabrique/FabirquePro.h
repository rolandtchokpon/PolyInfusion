
#include "FabriqueSysteme.h"

namespace Fabrique
{

    class FabriquePro : public FabriqueSysteme
    {
        FabriquePro();
        ~FabriquePro();
        
        virtual Machine::Systeme *creerSysteme() override;
    };

} // namespace Fabrique