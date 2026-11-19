
#include "../../include/fabrique/FabriqueSysteme.h"

namespace Fabrique
{

    const std::string COMPACT = "compact";
    const std::string PRO = "pro";

    FabriqueSysteme::FabriqueSysteme() :
        reserve_(std::make_shared<Machine::Reserve>()),
        app_(std::make_shared<Notification::AppDistant>()),
        ecran_(std::make_shared<Notification::Ecran>())
    {}
    
    FabriqueSysteme::~FabriqueSysteme() = default;

} // namespace Fabrique