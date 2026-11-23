
#include "../../include/notification/Ecran.h"

namespace Notification
{

    Ecran::Ecran() = default;

    Ecran::~Ecran() = default;

    void Ecran::alerterEau(Evenement evenement, double qte)
    {
        std::cout << "[Écran] " << messageEau(evenement, qte) << std::endl;
    }

    void Ecran::alerterThe(Evenement evenement, const std::string &the, double qte)
    {
        std::cout << "[Écran] " << messageThe(evenement, the, qte) << std::endl;
    }

} // namespace Notification
