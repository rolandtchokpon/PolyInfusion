
#include "../../include/fabrique/FabriqueSysteme.h"

namespace Fabrique {

    const std::string COMPACT = "compact";
    const std::string PRO = "pro";

    FabriqueSysteme::FabriqueSysteme() = default;
    FabriqueSysteme::~FabriqueSysteme() { delete ecran_; delete app_; };

    Machine::Systeme* FabriqueSysteme::creerSysteme(const std::string& modele) {
        if (modele == COMPACT) {
            return creerSystemeCompact();
        }
        else if (modele == PRO) {
            return creerSystemePro();
        }
        
        return nullptr;
    }

    Machine::Systeme* FabriqueSysteme::creerSystemeCompact() { 
        Machine::DistributeurEau* distributeurEau = new Machine::DistributeurEauCompact();
        Machine::DistributeurThe* distributeurThe = new Machine::DistributeurTheCompact();
        Machine::SystemeChauffage* systemeChauffage = new Machine::SystemeChauffageCompact();

        Notification::Observateur* ecran = new Notification::Ecran(distributeurEau, distributeurThe);
        Notification::Observateur* app = new Notification::AppDistant(distributeurEau, distributeurThe);
        ecran_ = ecran; app_ = app;

        distributeurEau->ajouterObservateur(ecran);
        distributeurEau->ajouterObservateur(app);

        distributeurThe->ajouterObservateur(ecran);
        distributeurThe->ajouterObservateur(app);

        return new Machine::SystemeCompact(distributeurEau, distributeurThe, systemeChauffage); 
    }

    Machine::Systeme* FabriqueSysteme::creerSystemePro() { 
        Machine::DistributeurEau* distributeurEau = new Machine::DistributeurEauPro();
        Machine::DistributeurThe* distributeurThe = new Machine::DistributeurThePro();
        Machine::SystemeChauffage* systemeChauffage = new Machine::SystemeChauffagePro();

        Notification::Observateur* ecran = new Notification::Ecran(distributeurEau, distributeurThe);
        Notification::Observateur* app = new Notification::AppDistant(distributeurEau, distributeurThe);
        ecran_ = ecran; app_ = app;

        distributeurEau->ajouterObservateur(ecran);
        distributeurEau->ajouterObservateur(app);

        distributeurThe->ajouterObservateur(ecran);
        distributeurThe->ajouterObservateur(app);

        return new Machine::SystemePro(distributeurEau, distributeurThe, systemeChauffage); 
    }

} // namespace Fabrique