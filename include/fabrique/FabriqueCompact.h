
#include "FabriqueSysteme.h"

namespace Fabrique
{

    class FabriqueCompact : public FabriqueSysteme
    {
    public:
        FabriqueCompact();
        virtual ~FabriqueCompact();

        virtual std::unique_ptr<Machine::Systeme> creerSysteme() override;
    };

} // namespace Fabrique
