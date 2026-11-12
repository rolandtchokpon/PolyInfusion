
#include "../../include/preparation/Rinceur.h"

namespace Machine {

    Rinceur::Rinceur(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage) :
        distributeurEau_(distributeurEau),
        distributeurThe_(distributeurThe),
        systemeChauffage_(systemeChauffage)
    {}

    Rinceur::~Rinceur() = default;

    void Rinceur::rincer(const std::string& the) {
        const The& theObj = distributeurThe_->obtenirThe(the);

        if (theObj.volumeRincage > 0.0) {
            systemeChauffage_->chaufferEauRincage(theObj.temperatureInfusion);
            distributeurEau_->distribuerEau(theObj.volumeRincage);
            distributeurThe_->distribuerThe(the, theObj.quantiteService);

            std::cout << "Rincage des feuilles" << std::endl;
            std::cout << "Évacuation de l'eau de rincage  " << std::endl;
        }
    }

} // namespace Machine