
#include "../../include/notification/Observateur.h"
#include "../../include/util/Format.h"

namespace Notification
{

    Observateur::~Observateur() = default;

    std::string messageEau(Evenement evenement, double qte)
    {
        const std::string etat = evenement == Evenement::Faible ? "faible" : "de nouveau suffisante";
        return "Réserve d'eau " + etat + " : " + Util::nombre(qte) + " mL.";
    }

    std::string messageThe(Evenement evenement, const std::string &the, double qte)
    {
        const std::string etat = evenement == Evenement::Faible ? "faible" : "de nouveau suffisante";
        return "Réserve de thé " + the + " " + etat + " : " + Util::nombre(qte) + " g.";
    }

} // namespace Notification
