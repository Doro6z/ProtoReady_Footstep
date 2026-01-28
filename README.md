# [ProtoReady] Audio Footstep System - système de bruit de pas.

![UE5](https://img.shields.io/badge/Unreal_Engine-5.5+-0078D7?style=for-the-badge&logo=unrealengine&logoColor=white) 
![CPP](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) 
![Replication](https://img.shields.io/badge/REPLICATION-Supported-28A745?style=for-the-badge&labelColor=28A745)

> **Système audio footstep clé en main.**
> Setup en 5 minutes. Compatible multi player. Full c++ + 3 nodes de contrôle blueprint.
> Configurable pour tous vos personnage. (n'importe quel Actor)
> 
> *   **Configuration** via DataAssets
> *   **Zéro code/Blueprint** requis
> *   **Tooltips** éditeur
> *   **20+ Samples Audio** pour un système fonctionnel dès son implémentation.

![Showcase Level](Distribution/pr_footstep_banner_v3.png)

![Trace Channel](https://img.shields.io/badge/Trace_Channel-Configurable-28A745?style=flat-square&labelColor=28A745) ![Distance](https://img.shields.io/badge/Trigger-Distance-000000?style=flat-square&labelColor=000000) ![AnimNotify](https://img.shields.io/badge/Trigger-AnimNotify-d00000?style=flat-square&labelColor=d00000)

---

## ⚡ Fonctionnalités Clés

*   **Physic Asset** : Détecte les surfaces via `PhysicalMaterials` pour y attribuer les sons.
*   **Traces** : Sphere, Line, Box, Multi-trace pour ajuster la précisions de la détection ou au spécificités du character.
*   **Mode de déclenchement** : **AnimNotify** (réglé sur l'anim asset) ou **Distance** (plus simpe pour prototyper).
*   **Mixage Audio** : Attenuation Settings & Chain Effect supporté.

---

## Installation (Setup)
![Setup](https://img.shields.io/badge/Setup-≈_5_min-28A745?style=flat-square)

1.  **Activez le plugin** : Edit > Plugins > ProtoReady Footstep.
2.  **Définissez vos Physical Surface** : Edit > Project Settings > Engine > Physics > Physical Surface. (optionel, par défault Surface Type 1,2..)
3.  **Ajoutez le `PRFootstepComponent`** à votre Character (ou n'importe quel Actor).
4.  **Créez un DataAsset `PRFootstepData`** et assignez-le au composant.

*Exemples de surfaces : Concrete, Dirt, Grass, Water, Wood. S'il n'existe qu'un seul `PRFootstepData`, il est auto-assigné à la création.*

![Data Asset](Distribution/Setup_DataAsset.png)

---

## Comment ça marche

### Déclenchement des pas
*   **AnimNotify (piloté par l'animation)** : Ajoutez la notify `PR_Footstep` à vos animations. La notify expose `FootSocketName` (optionel) et est disponible immédiatement.
*   **Distance (auto)** : Déclenche un bruit de pas tous les `DistanceInterval` (unité UE) parcourus. En mode Distance, le Tick est activé automatiquement.

### Réception (Landing)
*   `bAutoTriggerLand` se bind au `ACharacter::LandedDelegate`.
*   `LandingSound` est utilisé s'il est défini ; sinon le système joue un son de pas standard avec le flag landing.

### Traces & surfaces
*   La détection de surface se fait par trace sur un **Collision Channel** (Défaut : `ECC_Visibility`).
*   Le type de surface proviennent du **Physical Material** du mesh. S'il est manquant, `SurfaceType_Default` est utilisé.
*   Fonctionne sur les **Material Landscape** avec plusieurs layers.
*   `DefaultSound` est le son de repli utilisé lorsque la surface n'est pas mappée ou qu'aucun Physical Material n'est trouvé.

---

## Contenu du Package

*   **PRFootstepComponent** : Actor Component C++ léger.
*   **PRFootstepData** : DataAsset de configuration.
*   **20+ Samples Audio** : Béton, Terre, Herbe, Bois, Eau.
*   **5 SoundCues** & Physical Material pré-réglé.
*   **Démo level**.

![Audio System](Distribution/Audio_System.png)

---

## Spécifications Techniques

### Classes
*   **`UPRFootstepComponent`** (`UActorComponent`) : Moteur logique central (Tick, Trace, Spawn). Optimisé avec LOD.
*   **`UPRFootstepData`** (`UPrimaryDataAsset`) : Data de configuration.

### Blueprint API
![BP](https://img.shields.io/badge/Blueprint-Nodes-00599C?style=flat-square)

Le système expose des fonctions clés pour la logique de gameplay :

| Noeud | Description | Cas d'usage |
| :--- | :--- | :--- |
| **Set Trigger Mode** | Basculer entre la logique `AnimNotify` et `Distance` au runtime. | Patrouille NPC vs État de combat. |
| **Set Footstep Interval** | Changer la distance parcourue pour déclencher un pas. | Marche vs Course. |
| **Trigger Footstep** | Forcer une trace de pas unique immédiatement. | Cinématiques ou événements de réception. |

---

## Licence

**MIT License**.
(c) 2026 ProtoReady Pack
