# ProtoReady: Footstep System

![UE5](https://img.shields.io/badge/Unreal_Engine-5.5+-0078D7?style=for-the-badge&logo=unrealengine&logoColor=white) 
![CPP](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) 
![Replication](https://img.shields.io/badge/REPLICATION-Ready-28A745?style=for-the-badge)

> **Production-Ready Footstep System setup in under 5 minutes.**
>
> A high-performance solution engineered for **Physical Surfaces**. Drop the component on your character, and it just works. No spaghetti Blueprint logic required.

![Showcase Level](Distribution/pr_footstep_banner_v3.png)

![Trace](https://img.shields.io/badge/Trace-Sphere_/_Line_/_Box-d00000?style=flat-square&labelColor=black) ![Surface](https://img.shields.io/badge/Surface-Physical_Material-d00000?style=flat-square&labelColor=black) ![Trigger](https://img.shields.io/badge/Trigger-Distance_/_AnimNotify-d00000?style=flat-square&labelColor=black)

---

## ⚡ Key Capabilities

*   **Zero-Code Setup**: Strictly DataAsset-driven. Designers handle configuration, not logic.
*   **Physics Interaction**: Automatically validates surfaces via `PhysicalMaterials` (e.g., prevents "stone sounds on grass").
*   **Trace Versatility**: Sphere, Line, Box, and Multi-trace options for precise detection.
*   **Hybrid Triggering**: Frame-perfect **AnimNotify** or procedurally calculated **Distance**.
*   **Audio Mix**: Full support for Spatialization, Attenuation, and random modulation.

---

## Setup
![Setup](https://img.shields.io/badge/Setup-≈_5_min-28A745?style=flat-square)

1.  **Enable the plugin**: Edit > Plugins > ProtoReady Footstep.
2.  **Define your Physical Surfaces**: Edit > Project Settings > Engine > Physics > Physical Surface.
3.  **Add the `PRFootstepComponent`** to your Character (or any Actor).
4.  **Create a `PRFootstepData` DataAsset** and assign it to the component.

*Example surfaces: Concrete, Dirt, Grass, Water, Wood. If only one `PRFootstepData` exists, it is auto-assigned on creation.*

![Data Asset](Distribution/Setup_DataAsset.png)

---

## How it works

### Footstep triggering
*   **AnimNotify (animation-driven)**: Add the `PR_Footstep` notify to your animations. The notify exposes `FootSocketName` and is available immediately.
*   **Distance (auto)**: Triggers a step every `DistanceInterval` cm traveled. In Distance mode, Tick is enabled automatically.

### Landing
*   `bAutoTriggerLand` auto-binds `ACharacter::LandedDelegate`.
*   `LandingSound` is used if set; otherwise the system plays a standard footstep with the landing flag.

### Traces & surfaces
*   Surface detection is done by trace on a **Configurable Collision Channel** (Default: `ECC_Visibility`).
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
![BP](https://img.shields.io/badge/Blueprint-Native_Nodes-00599C?style=flat-square)

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
