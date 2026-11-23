# PolyInfusion — Diagramme de classes (TP2a)

Patrons : **Strategy** (profils), **Abstract Factory** (composants), **Observer** (réserves et alertes).

```mermaid
classDiagram
direction TB

class Machine {
  +selectionner(nom)
  +infuser()
  +afficherReserves()
  +remplirEau(q)
  +remplirThe(nom, q)
  +activerNotificationsDistantes(actif)
}

class RegistreProfils {
  +ajouter(profil)
  +trouver(nom) ProfilInfusion
}

class ProfilInfusion {
  <<abstract>>
  +nom() string
  +besoins(composants) Besoins
  +preparer(composants, reserves)
}
class ProfilVert
class ProfilNoir
class ProfilOolong

class FabriqueComposants {
  <<abstract>>
  +creerChauffage() SystemeChauffage
  +creerDistributeurThe() DistributeurThe
  +creerDistributeurEau() DistributeurEau
}
class FabriqueCompact
class FabriquePro

class SystemeChauffage {
  <<abstract>>
  +chauffer(temperatureCible) secondes
}
class ChauffageCompact
class ChauffagePro

class DistributeurThe {
  <<abstract>>
  +quantiteReelle(nominale) double
  +distribuer(reserve, nominale)
}
class DistributeurTheCompact
class DistributeurThePro

class DistributeurEau {
  <<abstract>>
  +quantiteReelle(nominale) double
  +distribuer(reserve, nominale)
}
class DistributeurEauCompact
class DistributeurEauPro

class Reserve {
  -nom
  -niveau
  -seuil
  +retirer(q)
  +ajouter(q)
  +attacher(observateur)
  +detacher(observateur)
}

class ObservateurReserve {
  <<interface>>
  +reserveFaible(reserve)
  +reserveSuffisante(reserve)
}
class NotifieurEcran
class NotifieurDistant

Machine --> RegistreProfils
Machine --> "1" ProfilInfusion : profil sélectionné
Machine --> FabriqueComposants : crée les composants
Machine *-- "4" Reserve : eau, vert, noir, oolong
Machine --> NotifieurEcran
Machine --> NotifieurDistant

RegistreProfils o-- "*" ProfilInfusion
ProfilInfusion <|-- ProfilVert
ProfilInfusion <|-- ProfilNoir
ProfilInfusion <|-- ProfilOolong
ProfilInfusion ..> SystemeChauffage : utilise
ProfilInfusion ..> DistributeurThe : utilise
ProfilInfusion ..> DistributeurEau : utilise

FabriqueComposants <|-- FabriqueCompact
FabriqueComposants <|-- FabriquePro
FabriqueComposants ..> SystemeChauffage : crée
FabriqueComposants ..> DistributeurThe : crée
FabriqueComposants ..> DistributeurEau : crée

SystemeChauffage <|-- ChauffageCompact
SystemeChauffage <|-- ChauffagePro
DistributeurThe <|-- DistributeurTheCompact
DistributeurThe <|-- DistributeurThePro
DistributeurEau <|-- DistributeurEauCompact
DistributeurEau <|-- DistributeurEauPro

DistributeurThe ..> Reserve : retire de
DistributeurEau ..> Reserve : retire de

Reserve o-- "*" ObservateurReserve
ObservateurReserve <|.. NotifieurEcran
ObservateurReserve <|.. NotifieurDistant
```

## Valeurs propres à chaque classe concrète

| Classe | Valeur |
|---|---|
| `ChauffageCompact` / `ChauffagePro` | 5 °C/s / 10 °C/s (départ à 20 °C) |
| `DistributeurTheCompact` / `Pro` | facteur 1,10 / 1,00 |
| `DistributeurEauCompact` / `Pro` | facteur 1,20 / 1,00 |
| `ProfilVert` | 5 g, 250 mL, 80 °C, infusion directe 120 s |
| `ProfilNoir` | 5 g, 250 mL, 95 °C, infusion directe 180 s |
| `ProfilOolong` | 5 g, 250 mL, 90 °C, rinçage 50 mL puis infusion 90 s |
| `Reserve` eau / thé | seuil 500 mL / 10 g, départ 2000 mL / 20 g |
