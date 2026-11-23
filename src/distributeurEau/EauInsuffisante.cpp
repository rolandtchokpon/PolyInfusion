
#include "../../include/distributeurEau/EauInsuffisante.h"

namespace Machine {

    EauInsuffisante::EauInsuffisante(double quantiteRequise, double quantiteDisponible) : 
        quantiteRequise_(quantiteRequise), 
        quantiteDisponible_(quantiteDisponible) 
    {
        message_ = "Erreur : Réserve d'eau insuffisante.\n" 
                    + std::string("Quantité requise : ") + std::to_string(quantiteRequise_) + " mL\n"
                    + std::string("Quantité disponible : ") + std::to_string(quantiteDisponible_) + " mL\n";
    }

    const char* EauInsuffisante::what() const noexcept {
        return message_.c_str();
    }

} // namespace Machine