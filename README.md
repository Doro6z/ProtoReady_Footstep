# 🦶 ProtoReady: Footstep System

> **[UE 5.5+]** **[C++]** **[Production-Ready]**

A high-performance, DataAsset-driven footstep solution built for Unreal Engine. Engineered for C++ efficiency, this system offers a streamlined workflow that eliminates the need for Blueprint dependencies while maintaining full designer control.

---

## 🚀 Key Capabilities

- **Component-Based Architecture**: Seamless integration via the `PRFootstepComponent`, compatible with any Actor class.
- **Physics-Driven Detection**: Automatically identifies surface types using the engine's Physical Materials system.
- **Versatile Trace Options**:
  - **Trace Shapes**: Supports Sphere, Line, Box, and Multi-trace methods for varying terrain complexity.
  - **Trace Origin**: Configurable start point from Sockets, Actor Root, or Capsule Center.
- **Dual Triggering Mechanisms**:
  - **AnimNotify**: Ensures precise synchronization with animation frames (Animation-Driven).
  - **Distance**: Logic-driven stride calculation, ideal for procedural movement or NPCs.
- **Advanced Audio Processing**:
  - **Spatialization**: Full support for Attenuation settings and 3D positioning.
  - **DSP Effects**: Integrated support for Sound Effects Chains.
  - **Modulation**: Runtime randomization of Pitch and Volume.

---

## 🛠️ Integration Guide

### 1. Installation
1. Place the `PR_Footstep` directory into your project's `Plugins` folder.
2. Activate the plugin via **Edit > Plugins**.

### 2. Configuration
1. Define your **Physical Surfaces** within `Project Settings > Engine > Physics`.
2. Generate a `PRFootstepData` asset.
3. Map the defined surfaces to their corresponding Sound assets (SoundCues or WAVs).

![Surfaces Setup](Distribution/PR_DataAsset_Surfaces.png)

### 3. Usage
Attach the `PRFootstepComponent` to your Character class.
- **AnimNotify**: Insert the `PR_Footstep` notify into your Locomotion animations.
- **Distance Mode**: Set `TriggerMode` to *Distance* within the Data Asset configuration.

---

## 📦 Package Contents

- **PRFootstepComponent**: A lightweight, replication-ready C++ Actor Component handling all footstep logic and audio management.
- **20+ High-Fidelity Audio Samples**: Comprehensive library of WAVs and pre-configured SoundCues.
- **Showcase Level**: Includes a fully configured NPC test actor and surface demonstration area.

---

## 🔧 Technical Specifications

- **Component Class**: `UPRFootstepComponent` (derived from `UActorComponent`).
- **Configuration Class**: `UPRFootstepData` (derived from `UPrimaryDataAsset`).
- **Networking**: Client-side cosmetic execution (RPC replication supported).

---

## 📄 Licensing

Released under the **MIT License**. Authorized for commercial utilization.
(c) 2026 ProtoReady Pack
