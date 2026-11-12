
#include "../../include/preparation/Infuseur.h"

namespace Machine {

    Infuseur::Infuseur(DistributeurEau* distributeurEau, DistributeurThe* distributeurThe, SystemeChauffage* systemeChauffage) :
        distributeurEau_(distributeurEau), 
        distributeurThe_(distributeurThe), 
        systemeChauffage_(systemeChauffage) 
    {}

    Infuseur::~Infuseur() = default;

    void Infuseur::infuser(const std::string& the) {
        const The& theObj = distributeurThe_->obtenirThe(the);

        systemeChauffage_->chaufferEau(theObj.temperatureInfusion);
        distributeurEau_->distribuerEau(theObj.volumeService);
        if (theObj.volumeRincage == 0.0) distributeurThe_->distribuerThe(the, theObj.quantiteService);

        std::cout << "Infusion : " << theObj.tempsInfusion << " secondes simulées" << std::endl;
    }

} // namespace Machine