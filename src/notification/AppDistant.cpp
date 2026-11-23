
#include "../../include/notification/AppDistant.h"

namespace Notification
{

    AppDistant::AppDistant() = default;

    AppDistant::~AppDistant() = default;

    void AppDistant::alerterEau(Evenement evenement, double qte)
    {
        std::cout << "[Notification distante] " << messageEau(evenement, qte) << std::endl;
    }

    void AppDistant::alerterThe(Evenement evenement, const std::string &the, double qte)
    {
        std::cout << "[Notification distante] " << messageThe(evenement, the, qte) << std::endl;
    }

} // namespace Notification
