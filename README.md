# PolyInfusion — TP2 (LOG2400)

Simulation console, en C++17, d'une machine à thé PolyInfusion (modèles **compact** et **pro**),
conçue à base de patrons (TP2a et TP2b).

## Compiler et exécuter

Prérequis : CMake 3.15 ou plus récent, un compilateur C++17 (MSVC, GCC ou Clang) et un terminal UTF-8.
Depuis le dossier contenant `CMakeLists.txt` :

### Windows — générateur Visual Studio

```powershell
cmake -S . -B build
cmake --build build --config Debug
.\build\Debug\PolyInfusion.exe compact
```

Avec Ninja ou MinGW, l'exécutable se trouve généralement dans `build` plutôt que dans `build/Debug`.

### Linux et macOS

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/PolyInfusion compact
```

Pour le modèle pro, remplacer `compact` par `pro`.

## Instructions

| Instruction | Effet |
|---|---|
| `selection <thé>` | sélectionne le thé (annulable) |
| `portions <n>` | règle le nombre de portions, entier strictement positif (annulable) |
| `infuser` | prépare les portions du thé sélectionné ; refusé sans rien consommer si les réserves ne suffisent pas pour l'ensemble |
| `reserves` | affiche les réserves d'eau et de thé |
| `remplir eau <mL>` / `remplir <thé> <g>` | ajoute de l'eau ou du thé (point décimal : `remplir vert 1.5`) |
| `notifications <activer\|désactiver>` | gère les notifications à distance ; les alertes à l'écran restent actives |
| `configuration` | affiche le thé sélectionné et le nombre de portions |
| `routine <nom>` | applique une routine prédéfinie (`solo`, `duo`, `matin`) ; un seul `undo` l'annule |
| `apercu <nom>` | liste les changements élémentaires de la routine, sans rien modifier |
| `undo` / `redo` | annule / rétablit la dernière opération réversible |
| `h` / `q` | aide / quitter |

Les instructions sont en minuscules ; les noms de routine ne tiennent pas compte de la casse.

## Conception

| Patron | Rôle | Classes principales |
|---|---|---|
| **Strategy** | un profil d'infusion par thé, qui détermine paramètres et étapes | `ProfilInfusion`, `ProfilVert`, `ProfilNoir`, `ProfilOolong`, `RegistreProfils` |
| **Abstract Factory** | l'ensemble cohérent de composants d'un modèle | `FabriqueSysteme`, `FabriqueCompact`, `FabriquePro` |
| **Observer** | alertes de réserve (écran toujours, application distante activable) | `Notificateur`, `Reserve`, `Observateur`, `Ecran`, `AppDistant` |
| **Command** | changements de réglages annulables et rétablissables | `Commande`, `CmdReglage`, `CmdSelection`, `CmdPortion`, `HistoriqueCMD`, `Executeur` |
| **Composite** | une routine est une commande qui contient des commandes | `Routine`, `CmdRoutine`, `RegistreRoutines` |
| **Iterator** | parcours des changements élémentaires d'une routine (aperçu), sans exposer sa structure ; c'est l'itérateur qui parcourt, pas la routine | `IterateurReglage`, `IterateurFeuille`, `IterateurRoutine` |
| **Prototype** | une copie neuve de la routine à chaque exécution (annulations indépendantes) | `CmdReglage::cloner()` |

Le diagramme de classes est dans `Diagram_corrige.puml` (source PlantUML) et
`docs/diagramme_classes_corrige.{svg,png,pdf}` (image imprimable).

### Ajouter un profil, un modèle ou un destinataire

- **Nouveau thé** : écrire une classe qui hérite de `ProfilInfusion` et l'enregistrer dans `RegistreProfils`.
  Sa réserve est créée automatiquement, et la console connaît son nom.
- **Nouveau modèle** : écrire une fabrique qui hérite de `FabriqueSysteme` et ses trois composants ;
  les profils et `Systeme` ne changent pas.
- **Nouveau destinataire d'alertes** : hériter de `Observateur` et l'abonner avec `Systeme::ajouterObservateur`.
- **Nouveau changement de réglage annulable** : hériter de `CmdReglage` ; le compilateur impose `executer`, `undo`, `redo`, `apercu` et `cloner`, et `HistoriqueCMD` ne change pas.
- **Nouvelle routine** : l'enregistrer dans `RegistreRoutines`.

## Organisation

```text
include/ et src/
├── console/       InterfaceConsole, Instruction, TypeInstruction
├── executeur/     Executeur, HistoriqueCMD, RegistreRoutines
├── commande/      Commande, CmdReglage, CmdSelection, CmdPortion, Routine, CmdRoutine, CmdApercu, itérateurs, autres Cmd…
├── systeme/       Systeme, Composants
├── profil/        ProfilInfusion, ProfilVert, ProfilNoir, ProfilOolong, RegistreProfils
├── fabrique/      FabriqueSysteme, FabriqueCompact, FabriquePro
├── systemeChauffage/, distributeurEau/, distributeurThe/   composants par modèle
├── reserve/       Reserve, EauInsuffisante, TheInsuffisant
├── notification/  Notificateur, Observateur, Ecran, AppDistant
└── util/          Format.h (affichage des nombres, virgule décimale)
```

Chaque nouveau `.cpp` doit être ajouté à la liste `add_executable` de `CMakeLists.txt`.
