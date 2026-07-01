#include <Arduino.h> 
#include "InnoSwitch3Pro.h"
#include "USB_PD_PPS_Engine.h"
#define CONTROL_LOOP_INTERVAL_MS 10 
InnoSwitch3Pro smps;
PPSEngine pdEngine;

unsigned long lastLoopTime = 0;

void setup() {
    Wire.begin(400000); 
    smps.begin();
    pdEngine.init();
    
    smps.setVoltage(5000); 
    smps.setCurrentLimit(3000);
    smps.enableOutput(true);
}

void loop() {
    if (millis() - lastLoopTime >= CONTROL_LOOP_INTERVAL_MS) {
        lastLoopTime = millis();
        
        uint16_t vOut = smps.readVoltageTelemetry();
        uint16_t iOut = smps.readCurrentTelemetry();
        uint8_t faultStatus = smps.readFaultRegister();
        
        pdEngine.update(vOut, iOut);
        
        if (faultStatus & (IS3P_FAULT_OVP | IS3P_FAULT_OCP | IS3P_FAULT_OTP)) {
            smps.emergencyShutdown();
            pdEngine.raiseAlert(faultStatus);
            while(1); 
        }
        
        if (pdEngine.hasTargetChanged()) {
            uint16_t targetV = pdEngine.getTargetVoltage(); 
            uint16_t targetI = pdEngine.getTargetCurrent(); 
            
            smps.setVoltage(targetV);
            smps.setCurrentLimit(targetI);
        }
    }
}
