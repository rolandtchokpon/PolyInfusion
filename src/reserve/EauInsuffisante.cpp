
#include "../../include/reserve/EauInsuffisante.h"

namespace Machine {

    EauInsuffisante::EauInsuffisante(double quantiteRequise, double quantiteDisponible) : 
        quantiteRequise_(quantiteRequise), 
        quantiteDisponible_(quantiteDisponible) 
    {
       std::ostringstream oss;
        oss << "Erreur : réserve d'eau insuffisante.\n"
            << "Quantité requise : " << quantiteRequise_ << " mL.\n"
            << "Quantité disponible : " << quantiteDisponible_ << " mL.\n"
            << "Aucune consommation effectuée.";
        message_ = oss.str();
    }

    const char* EauInsuffisante::what() const noexcept {
        return message_.c_str();
    }

} // namespace Machine