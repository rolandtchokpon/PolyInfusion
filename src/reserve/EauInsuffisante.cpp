
#include "../../include/reserve/EauInsuffisante.h"
#include "../../include/util/Format.h"

namespace Machine {

    EauInsuffisante::EauInsuffisante(double quantiteRequise, double quantiteDisponible) :
        quantiteRequise_(quantiteRequise),
        quantiteDisponible_(quantiteDisponible)
    {
        message_ = "Erreur : réserve d'eau insuffisante.\n"
                   "Quantité requise : " + Util::nombre(quantiteRequise_) + " mL. "
                   "Quantité disponible : " + Util::nombre(quantiteDisponible_) + " mL.\n"
                   "Aucune consommation effectuée.";
    }

    const char* EauInsuffisante::what() const noexcept {
        return message_.c_str();
    }

} // namespace Machine
