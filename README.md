# Digitally-Controlled-65W-Flyback-SMPS-
Hardware design of a 65W digitally controlled flyback power supply for variable voltage USB-PD charging.

This project explores the design of a **65W isolated flyback Switched-Mode Power Supply (SMPS)** capable of delivering adjustable output voltage for modern device charging. The goal is to build a compact and efficient power supply that can adapt its output based on device requirements using **USB Power Delivery (PD)** and **Programmable Power Supply (PPS)** profiles.

The design is built around the **InnoSwitch3-Pro controller** and developed using tools like **KiCad** for schematic and PCB design and **PI Expert** for optimizing the power stage and transformer parameters.

---

## Why this project?

Most modern chargers are no longer fixed-voltage supplies. Devices such as phones, tablets, and laptops expect the charger to dynamically negotiate voltage and current levels.

This project is an attempt to understand and implement such an **adaptive charging system** from the ground up, focusing on the power electronics behind digitally controlled SMPS designs.

Along the way, the project explores topics such as:

* Flyback converter design
* High-frequency transformer optimization
* Digital control of power supplies
* USB Power Delivery protocols
* PCB layout for switching converters

---

## Key Features

* 65W isolated flyback power supply topology
* Adjustable output voltage from **5V to 19V**
* Support for **USB Power Delivery (PD)** and **PPS** profiles
* Estimated **>90% peak efficiency** based on design simulations
* Target **<40 mW no-load standby consumption**
* Built-in protection mechanisms such as **Over-Voltage Protection (OVP)** and **Over-Current Protection (OCP)**

---

## Tools Used

The design process makes use of the following tools:

* **KiCad** – schematic capture and PCB layout
* **PI Expert (Power Integrations)** – power stage and transformer optimization
* Manufacturer datasheets and application notes

These tools helped in selecting the correct topology, optimizing the transformer parameters, and designing a PCB suitable for high-frequency switching circuits.

---

## Current Status

This project is currently **under development**.

Completed so far:

* Initial research on flyback topology and digital SMPS control
* Component selection for the power stage
* Schematic design using KiCad
* PCB layout design in KiCad
* Efficiency and transformer optimization using PI Expert

Next steps:

* Review and finalize PCB layout
* Fabricate the prototype board
* Hardware testing and validation
* USB-PD negotiation testing and performance evaluation

---

## Repository Structure

Digitally-Controlled-Flyback-SMPS/

docs/ → design notes, references, and calculations
schematic/ → KiCad schematic files
pcb/ → PCB layout files and Gerber outputs
images/ → schematic previews and PCB renders
README.md → project overview and documentation

---

## What I hope to learn from this project

This project is mainly a learning exercise in **power electronics and practical SMPS design**. Through it, I hope to gain deeper understanding of:

* Real-world SMPS implementation
* Transformer design considerations
* PCB layout challenges in switching converters
* Efficiency optimization and thermal considerations

---

## Author

Tanu Choudhary

This ongoing project is part of my exploration into **power electronics, hardware design, and practical SMPS development**.

---


