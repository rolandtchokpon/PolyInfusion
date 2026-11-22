
#include "../../include/reserve/TheInsuffisant.h"

namespace Machine
{

    TheInsuffisant::TheInsuffisant(const std::string &the, double quantiteRequise, double quantiteDisponible) : the_(the),
                                                                                                                quantiteRequise_(quantiteRequise),
                                                                                                                quantiteDisponible_(quantiteDisponible)
    {
        std::ostringstream oss;
        oss << "Erreur : réserve de thé " << the_ << " insuffisante.\n"
            << "Quantité requise : " << quantiteRequise_ << " g.\n"
            << "Quantité disponible : " << quantiteDisponible_ << " g.\n"
            << "Aucune consommation effectuée.";
        message_ = oss.str();
    }

    const char *TheInsuffisant::what() const noexcept
    {
        return message_.c_str();
    }

} // namespace Machine