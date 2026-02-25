# Sumobot Embedded System Competition

Competition-grade autonomous sumobot built as a complete embedded system integrating hardware design, digital motor control (VHDL), communication interfaces, and firmware coordination.

This project was developed with a system-level engineering approach, emphasizing deterministic digital control, robust clock-domain handling, and modular architecture suitable for competitive robotics environments.

---

# Overview

The system integrates:

* Custom motor power stage (dual H-bridge)
* FPGA/CPLD-based motor control in VHDL
* SPI communication interface
* Parameterized PWM generation
* Shadow register architecture for glitch-free updates
* Clock Domain Crossing (CDC) safe modules
* Embedded firmware control layer
* Custom PCB and hardware integration

The design is modular and structured to clearly separate hardware, firmware, and digital logic responsibilities.

---

# System Architecture

## 1. Power & Motor Stage

* Dual H-bridge motor driver
* Enable gating logic
* Direction and dead-time control
* Electrical isolation between control and power stages

## 2. Digital Control Layer (FPGA / CPLD – VHDL)

* Top-level hierarchical RTL structure
* Finite State Machine (FSM) motor controller
* Parameterized PWM generators
* Shadow registers for atomic duty-cycle updates
* SPI command decoder
* Clock Domain Crossing synchronization blocks
* Deterministic update sequencing

## 3. Communication Interface

* SPI master-slave architecture
* Register-mapped command system
* Structured command decoding
* Controlled update handshake

## 4. Sensor Interface

* External sensor input capture
* Edge synchronization
* Asynchronous signal conditioning
* Safe domain crossing to system clock

## 5. Embedded Firmware Layer

* High-level decision logic
* Motion strategy control
* Communication management
* System supervision and safety routines

## 6. Competition Logic

* Autonomous movement behavior
* Real-time control decisions
* Fail-safe handling
* Strategy-oriented control flow

---

# Digital Design Features

* Modular RTL structure
* Explicit Clock Domain Crossing (CDC) handling
* Multi-domain synchronization strategy
* 2-Flip-Flop synchronizers for single-bit signals
* Toggle/handshake-based pulse synchronization
* Shadow-register based PWM update scheme
* FSM-based deterministic motor control
* Clean separation between datapath and control logic

---

# Repository Structure

```
sumobot-embedded-system-competition/
│
├── README.md
├── docs/
│   ├── architecture.md
│   ├── clocking.md
│   ├── register_map.md
│   ├── bringup.md
│
├── hardware/
│   ├── schematics/
│   ├── pcb/
│   ├── bom/
│   └── mechanical/
│
├── firmware/
│   ├── pic/
│   ├── atmega/
│   └── tools/
│
├── fpga/
│   ├── rtl/
│   │   ├── top/
│   │   ├── control/
│   │   ├── pwm/
│   │   ├── spi/
│   │   ├── sensors/
│   │   └── cdc/
│   │
│   ├── sim/
│   ├── constraints/
│   └── project_files/
│
└── tools/
```

---

# Clocking Strategy

The system is designed with a primary system clock domain and clearly defined CDC boundaries.

Key principles:

* Internal logic runs in a unified system clock when possible
* External asynchronous inputs are synchronized before entering control logic
* Multi-bit buses are never synchronized bitwise
* Handshake or shadow-register techniques are used for atomic updates
* Reset de-assertion is synchronized

---

# Design Philosophy

The project prioritizes:

* Deterministic behavior
* Hardware-level reliability
* CDC-safe design
* Modular scalability
* Clear architectural separation
* Professional RTL organization

This repository is structured to reflect production-grade embedded system design practices rather than ad-hoc academic implementation.

---

# Toolchain

HDL: VHDL
Target Device: (Specify FPGA/CPLD)
EDA Tool: (Quartus / Vivado / etc.)
Simulation: (ModelSim / Questa / etc.)
Firmware Toolchain: (Specify if applicable)

---

# Current Status

Active development and iterative architectural refinement.

Modules under continuous improvement:

* CDC robustness
* Register mapping consistency
* Simulation coverage
* Documentation completeness

---

# Intended Purpose

This project serves as:

* Competition robotics platform
* Embedded systems engineering portfolio project
* Digital motor control architecture case study
* Practical implementation of multi-clock digital design
* Reference for structured VHDL-based system design

---


