
#include "FabriqueSysteme.h"

namespace Fabrique
{

    class FabriquePro : public FabriqueSysteme
    {
        FabriquePro();
        ~FabriquePro();

        virtual std::unique_ptr<Machine::Systeme> &creerSysteme() override;
    };

} // namespace Fabrique