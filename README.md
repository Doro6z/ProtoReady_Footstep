# 🦶 ProtoReady: Footstep System

> **[UE 5.5+]** **[C++]** **[Replication]** **Optimized**

A high-performance, DataAsset-driven footstep solution built for games made in Unreal Engine. C++ efficiency and helpful blueprint nodes for Blueprint control.

![Showcase Level](Distribution/Showcase_Level.png)

---

## 🚀 Key Capabilities

- **Component-Based Architecture**: Seamless integration via the `PRFootstepComponent`.
- **Physics-Driven Detection**: Automatically identifies surface types using the Physical Materials system.
- **Trace Options**: Sphere, Line, Box, and Multi-trace methods.
- **Trigger mode**: AnimNotify (Animation-Driven) or Distance (Procedural).
- **Audio Mix**: Spatialization, Attenuation, and random modulation (Pitch/Volume) 
- Works with multi-layered **Landscape Materials** 
---

## 🛠️ Integration Guide

### 1. Installation & Setup
1. Place `PR_Footstep` in your `Plugins` folder and enable it.
2. Define **Physical Surfaces** in `Project Settings > Engine > Physics`.
   (default PRFootStepData uses Surface Type 1-5)

![Physics Settings](Distribution/Setup_Physics.png)

### 2. Configuration
Create a `PRFootstepData` asset to map surfaces to sounds and configure trace settings.

![Data Asset Configuration](Distribution/Setup_DataAsset.png)

### 3. Usage
Add `PRFootstepComponent` to your Character. (works with any actor on Distance mode)
- **AnimNotify**: Insert the `PR_Footstep` notify into your Animation Sequence.
- **Distance Mode**: Set `Foot Interval Distance` for automatic triggering. (Blueprint controllable)

---

## 📦 Package Contents

- **PRFootstepComponent**: Lightweight C++ Actor Component.
- **20+ Footstep Audio Samples**: A selection of varied footstep sounds (Concrete, Dirt, Grass, Wood, Water) ready for prototyping.
- **5 Soundcues** & 5 simple **Physical Material**
- **1 Sound Attenuation** setting for audio distance fall-of.
- **Showcase Level**

![Audio System](Distribution/Audio_System.png)

---

## 🔧 Technical Specifications

### Classes
- **`UPRFootstepComponent`** (`UActorComponent`):
  - The core logic engine. Handles tick updates (for distance checking), trace execution, and sound spawning.
  - Optimized to minimize overhead when not moving or out of range (LOD).
- **`UPRFootstepData`** (`UPrimaryDataAsset`):
  - Central configuration file. Stores all impact sounds, trace parameters, and audio settings.
  - Decoupled from logic allows for easy swapping (e.g., Heavy vs Light boots).

### Blueprint API
The system exposes several key functions to Blueprint for gameplay logic:

*   **`TriggerFootstep(FName SocketName)`**:
    *   *Description*: Manually force a footstep trace/sound from a specific socket.
    *   *Use Case*: Landing events, special animation moments, or cutscenes.

*   **`SetFootstepInterval(float NewInterval)`**:
    *   *Description*: Updates the distance required to travel before automatically triggering a step (Distance Mode only).
    *   *Use Case*: Changing gait from Walk (120cm) to Run (200cm).

*   **`GetFootstepInterval()`**:
    *   *Description*: Returns the current interval distance.

*   **`SetTriggerMode(EPRFootstepTriggerMode NewMode)`**:
    *   *Description*: Switches between AnimNotify and Distance modes at runtime.

---

## 📄 License

Released under the **MIT License**. Authorized for commercial utilization.
(c) 2026 ProtoReady Pack
