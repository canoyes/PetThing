  
  #include "Wire.h"
  #include "I2Cdev.h"
  #include "MPU9150Lib.h"
  #include "CalLib.h"
  #include <inv_mpu.h>
  #include <EEPROM.h>
  
  //  The magnetometer itself is quite noisy so some mixing with the gyro yaw can help
  //#define  MPU_MAG_MIX_GYRO_AND_MAG       10 
  #define  SERIAL_PORT_SPEED  115200
  #define  DEVICE_TO_USE    0
  
  MPU9150Lib MPU;
  #define MPU_UPDATE_RATE  (20)
  #define MAG_UPDATE_RATE  (10)
  #define  MPU_MAG_MIX_GYRO_AND_MAG       10 
  #define MPU_LPF_RATE   40
  
  
  
  
  void setup() {
    
    Wire.begin();
    Serial.begin(SERIAL_PORT_SPEED);
    delay(500);
    Serial.print("Arduino9150 starting");
    MPU.selectDevice(DEVICE_TO_USE);
    MPU.init(MPU_UPDATE_RATE, MPU_MAG_MIX_GYRO_AND_MAG, MAG_UPDATE_RATE, MPU_LPF_RATE);  
  }
  
  void loop() {
    MPUVector3 angles;
    
    delay(1000);
    MPU.selectDevice(DEVICE_TO_USE);                       
    if (MPU.read()) {                         
      Serial.print("\n MPU fused angles...");
      MPU.printAngles(MPU.m_fusedEulerPose);               
      Serial.println();
      angles[VEC3_X] = MPU.m_fusedEulerPose[VEC3_X];
      Serial.print(angles[VEC3_X]*RAD_TO_DEGREE);
      Serial.println();
      Serial.print(MPU.m_rawGyro[0]/131);   
    }
    
  }
       
  
  

