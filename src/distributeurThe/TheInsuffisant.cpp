
#include "../../include/distributeurThe/TheInsuffisant.h"

namespace Machine {

    TheInsuffisant::TheInsuffisant(const std::string& the, double quantiteRequise, double quantiteDisponible) : 
        the_(the), 
        quantiteRequise_(quantiteRequise), 
        quantiteDisponible_(quantiteDisponible) 
    {
        message_ =  "Erreur : Réserve de thé " + the_ + " insuffisante.\n" 
                    + std::string("Quantité requise : ") + std::to_string(quantiteRequise_) + " mL\n"
                    + std::string("Quantité disponible : ") + std::to_string(quantiteDisponible_) + " mL\n";
    }

    const char* TheInsuffisant::what() const noexcept {
        return message_.c_str();
    }

} // namespace Machine