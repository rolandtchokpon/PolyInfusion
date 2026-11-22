
#include "FabriqueSysteme.h"

namespace Fabrique
{

    class FabriquePro : public FabriqueSysteme
    {
    public:
        FabriquePro();
        virtual ~FabriquePro();

        virtual std::unique_ptr<Machine::Systeme> creerSysteme() override;
    };

} // namespace Fabrique