# ProtoReady: Footstep System

![UE5](https://img.shields.io/badge/Unreal_Engine-5.5+-0078D7?style=for-the-badge&logo=unrealengine&logoColor=white) 
![CPP](https://img.shields.io/badge/Language-C++17-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) 
![Net](https://img.shields.io/badge/Replication-Supported-28A745?style=for-the-badge)

> **[UE 5.5+]** **[C++]** **[Production-Ready]**
> Système de pas prêt à l’emploi, basé sur Physical Surfaces et DataAsset. Aucun code Blueprint requis pour démarrer.

![Showcase Level](Distribution/Showcase_Level.png)

---

## Key Capabilities

*   **Logic/Data Decoupling**: Swap "Footstep Data Assets" at runtime (e.g., Heavy Armor vs Sneakers) without changing logic.
*   **Physics Interaction**: Validates surfaces via `PhysicalMaterials`, preventing "stone sounds on grass".
*   **Trace Versatility**: Sphere, Line, Box, and Multi-trace options.
*   **Hybrid Triggering**: AnimNotify (Animation-Driven) or Distance (Procedural).
*   **Advanced Audio**: Spatialization, Attenuation, and random modulation (Pitch/Volume).

---

## Setup

1.  **Enable the plugin**: Edit > Plugins > ProtoReady Footstep.
2.  **Define your Physical Surfaces**: Edit > Project Settings > Engine > Physics > Physical Surface.
3.  **Add the `PRFootstepComponent`** to your Character (or any Actor).
4.  **Create a `PRFootstepData` DataAsset** and assign it to the component.

*Example surfaces: Concrete, Dirt, Grass, Water, Wood. In editor, if only one `PRFootstepData` exists, it is auto-assigned when the component is created.*

![Data Asset](Distribution/Setup_DataAsset.png)

---

## How it works

### Footstep triggering
*   **AnimNotify (animation-driven)**: Add the `PR_Footstep` notify to your animations. The notify exposes `FootSocketName` and is available as soon as the plugin is installed.
*   **Distance (auto)**: Triggers a step every `DistanceInterval` cm traveled. In Distance mode, Tick is enabled automatically.

### Landing
*   `bAutoTriggerLand` auto-binds `ACharacter::LandedDelegate`.
*   `LandingSound` is used if set; otherwise the system plays a standard footstep with the landing flag.

### Traces & surfaces
*   Surface detection is done by trace on `ECC_Visibility` (Line / Sphere / Multi).
*   Surfaces come from the mesh **Physical Material**. If missing, `SurfaceType_Default` is used.
*   `DefaultSound` is the fallback sound used when the surface is not mapped or when no Physical Material is found.

---

## Package Contents

*   **PRFootstepComponent**: Lightweight C++ Actor Component.
*   **PRFootstepData**: Configuration DataAsset.
*   **20+ Audio Samples**: Concrete, Dirt, Grass, Wood, Water.
*   **5 SoundCues** & Physical Materials.
*   **Showcase Level**.

![Audio System](Distribution/Audio_System.png)

---

## Technical Specifications

### Classes
*   **`UPRFootstepComponent`** (`UActorComponent`): Core logic engine (Tick, Trace, Spawn). Optimized with LOD.
*   **`UPRFootstepData`** (`UPrimaryDataAsset`): Central configuration container.

### Blueprint API
The system exposes key functions for gameplay logic:

| Node | Description | Use Case |
| :--- | :--- | :--- |
| **Set Trigger Mode** | Switch between `AnimNotify` and `Distance` logic at runtime. | NPC Patrol vs Combat state. |
| **Set Footstep Interval** | Change the stride distance triggering a step. | Walk vs Run gait. |
| **Trigger Footstep** | Force a single footstep trace immediately. | Cutscenes or Landing events. |

---

## License

**MIT License**.
(c) 2026 ProtoReady Pack
