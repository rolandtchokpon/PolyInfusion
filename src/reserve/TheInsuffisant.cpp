
#include "../../include/reserve/TheInsuffisant.h"
#include "../../include/util/Format.h"

namespace Machine {

    TheInsuffisant::TheInsuffisant(const std::string& the, double quantiteRequise, double quantiteDisponible) :
        the_(the),
        quantiteRequise_(quantiteRequise),
        quantiteDisponible_(quantiteDisponible)
    {
        message_ = "Erreur : réserve de thé " + the_ + " insuffisante.\n"
                   "Quantité requise : " + Util::nombre(quantiteRequise_) + " g. "
                   "Quantité disponible : " + Util::nombre(quantiteDisponible_) + " g.\n"
                   "Aucune consommation effectuée.";
    }

    const char* TheInsuffisant::what() const noexcept {
        return message_.c_str();
    }

} // namespace Machine
