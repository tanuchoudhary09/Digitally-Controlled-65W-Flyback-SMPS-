# Digitally-Controlled 65W Flyback SMPS

A high-efficiency, digitally-controlled 65W isolated Flyback Switched-Mode Power Supply (SMPS) designed for universal mobile and laptop charging. This project features dynamic voltage scaling (5V–19V) via an $I^2C$-programmable architecture compliant with USB Power Delivery (PD) 3.0 and Programmable Power Supply (PPS) protocols.

---

## Hardware Design & Documentation

To review the electrical engineering layout and manufacturing assets without requiring native ECAD software, access the core design documentation directly below:

* **[Complete Circuit Diagram (Vector PDF)](.hardware/schematic.pdf)** – High-resolution vector schematic for comprehensive circuit tracking and primary/secondary insulation clearance inspection.
*  **[Bill of Materials (BOM PDF)](.hardware/BOM.pdf)** – Full component procurement document including exact manufacturer part numbers, tolerances, and package footprints.

---

## Key Features & Performance Metrics

*   **Wide Output Range:** Dynamic voltage scaling from **5V to 19V** supporting universal fast-charging standards.
*   **High Efficiency:** Optimized magnetic and switching parameters achieving an estimated peak efficiency of **>90%**.
*   **Ultra-Low Standby:** Standby/no-load consumption of **<40mW**, easily meeting strict global eco-design regulations.
*   **Fully Programmable:** Features continuous adjustment of output voltage (20mV steps) and current limits (50mA steps) via a digital interface.

---

## System Architecture & Component Selection

The architecture splits tasks between an autonomous, high-speed analog inner control loop and a digital supervisory outer control loop over $I^2C$:

1.  **Power & Regulation Stage:** Handled completely on-chip by the **InnoSwitch3-Pro** IC, combining the primary switch, secondary-side controller, and FluxLink™ magneto-inductive feedback into a single package.
2.  **Protocol & Safety Engine:** An external MCU acts as the supervisor, processing the USB PD/PPS stack, handling telemetry aggregation, and dynamically programming the InnoSwitch3-Pro's internal DACs.

### Critical Component Breakdown

| Qty | Part Ref | Primary Value | Description | Manufacturer | Mfg Part Number |
| :--- | :--- | :--- | :--- | :--- | :--- |
| 1 | U1 | INN3370C-H302 | Off-Line CV/CC Flyback Switcher IC (750V PowiGaN) | Power Integrations | INN3370C-H302 |
| 1 | T1 | E30/15/7-3F3 | Flyback Transformer Core, 3F3 MnZn Ferrite Material | Ferroxcube | E3015//7-3F3 |
| 1 | M1 | AOSP66923 | Synchronous Rectifier MOSFET (N-Ch, 100V, 9.5A) | Alpha & Omega Semi | AOSP66923 |
| 2 | M2 | AOD66406 | Output Pass/Protection MOSFET (N-Ch, 40V, 45A) | Alpha & Omega Semi | AOD66406 |
| 1 | BR1 | Z4GP208L-HF | Fast Recovery Bridge Rectifier (800V, 2A) | Comchip Technology | Z4GP208L-HF |
| 1 | C2 | 120 µF | High-Voltage Bulk Aluminum Electrolytic (400V) | Nichicon | UPT2G121MHD6 |
| 2 | C10, C11 | 680 µF | Low-ESR Organic Polymer Output Filters (35V) | Panasonic | EEH-ZS1V681UP |

---

## Engineering Challenges & Solutions

### 1. Transformer Optimization via PI Expert
Utilized Power Integrations (PI) Expert to meticulously model and simulate the magnetic core parameters. Optimizing the primary-to-secondary turns ratio and minimizing leakage inductance allowed the system to cross the **90% efficiency threshold** while keeping transient voltage spikes clamped safely below the GaN FET's breakdown rating.

### 2. PPS & Cable Current Limit Compliance
Resolved strict compliance warnings associated with the USB PD 3.0 PPS protocol. Implemented custom firmware guardrails to cross-reference real-time telemetry against structural cable current limits (e.g., 3A vs 5A e-marked cables). This prevents the power supply from delivering currents exceeding the physical capacity of the attached cable.

### 3. Fault Protection & Thermal Safeguards
Designed robust hardware-to-software fault loops. The system monitors Over-Voltage Protection (OVP), Over-Current Protection (OCP), and Over-Temperature Protection (OTP) on a cycle-by-cycle basis. If anomalies are flagged, the supervisory loop triggers an immediate emergency shutdown, preventing thermal device burnout and protecting both the SMPS and target client hardware.

## Author

Tanu Choudhary

This ongoing project is part of my exploration into **power electronics, hardware design, and practical SMPS development**.

---


